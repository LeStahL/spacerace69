#include "NewFontUndoCommand.hpp"

NewFontUndoCommand::NewFontUndoCommand(SplineEdit *splineEdit, Font* font)
    : QUndoCommand()
    , m_spline_edit(splineEdit)
    , m_font(font)
{
    if(m_font == nullptr) m_font = new Font;
}

NewFontUndoCommand::~NewFontUndoCommand()
{
    delete m_font;
}

void NewFontUndoCommand::redo()
{
    m_old_font = m_spline_edit->m_font;
    m_spline_edit->m_font = m_font;
    
    m_spline_edit->m_ui.actionSave->setEnabled(true);
    m_spline_edit->m_ui.actionSave_As->setEnabled(true);
    m_spline_edit->m_ui.actionAdd_Glyph->setEnabled(true);
    m_spline_edit->m_ui.tableView->setEnabled(true);
    
    QUndoCommand::redo();
}

void NewFontUndoCommand::undo()
{
    m_spline_edit->m_font = m_old_font;
    if(m_old_font == nullptr)
    {
        m_spline_edit->m_ui.actionSave->setEnabled(false);
        m_spline_edit->m_ui.actionSave_As->setEnabled(false);
        m_spline_edit->m_ui.actionAdd_Glyph->setEnabled(false);
        m_spline_edit->m_ui.tableView->setEnabled(false);
    }
    
    QUndoCommand::undo();
}

