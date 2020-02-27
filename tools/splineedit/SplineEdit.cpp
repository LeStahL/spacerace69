#include <QApplication>
#include <QChar>

#include "SplineEdit.hpp"

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
{
    m_ui.setupUi(this);
    
    // ### Test Font display
    Font *font = new Font();
    font->m_glyphs.push_back(new Glyph(QChar('a')));
    font->m_glyphs.push_back(new Glyph(QChar('b')));
    font->m_glyphs.push_back(new Glyph(QChar('c')));
    FontModel *model = new FontModel(font);
    m_ui.tableView->setModel(model);
    update();
}

SplineEdit::~SplineEdit()
{
}
