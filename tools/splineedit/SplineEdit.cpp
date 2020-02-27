#include <QApplication>
#include <QChar>

#include "SplineEdit.hpp"
#include "NewFontUndoCommand.hpp"

int main(int argc, char **args)
{
    QApplication app(argc, args);
    SplineEdit mainWindow(&app);
    mainWindow.show();
    app.exec();
}

SplineEdit::SplineEdit(QApplication* app)
    : m_ui(Ui::SplineEdit())
    , m_app(app)
    , m_font(nullptr)
{
    m_ui.setupUi(this);
}

SplineEdit::~SplineEdit()
{
}

void SplineEdit::editRedo()
{
    if(m_undo_stack.canRedo()) m_undo_stack.redo();
    manageEnabled();
}

void SplineEdit::editUndo()
{
    if(m_undo_stack.canUndo()) m_undo_stack.undo();
    manageEnabled();
}

void SplineEdit::fileNew()
{
    m_undo_stack.push(new NewFontUndoCommand(this, m_font));
    manageEnabled();
}

void SplineEdit::manageEnabled()
{
    m_ui.actionRedo->setEnabled(m_undo_stack.canRedo());
    m_ui.actionUndo->setEnabled(m_undo_stack.canUndo());
}
