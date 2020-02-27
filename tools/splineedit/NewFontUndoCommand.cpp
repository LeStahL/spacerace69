#include "NewFontUndoCommand.hpp"
#include "FontModel.hpp"

NewFontUndoCommand::NewFontUndoCommand(SplineEdit *splineEdit, Font* font)
    : QUndoCommand()
    , m_spline_edit(splineEdit)
    , m_font(font)
{
    if(m_font == nullptr) m_font = new Font;
    m_font_model = new FontModel(m_font);
    m_old_font_model = m_spline_edit->m_font_model;
}

NewFontUndoCommand::~NewFontUndoCommand()
{
    delete m_font;
    delete m_font_model;
}

void NewFontUndoCommand::redo()
{
    m_old_font = m_spline_edit->m_font;
    m_spline_edit->m_font = m_font;
    
    m_spline_edit->m_ui.actionSave->setEnabled(true);
    m_spline_edit->m_ui.actionSave_As->setEnabled(true);
    m_spline_edit->m_ui.actionAdd_Glyph->setEnabled(true);
    m_spline_edit->m_ui.tableView->setEnabled(true);
    
    m_spline_edit->m_font_model = m_font_model;
    m_spline_edit->m_ui.tableView->setModel(m_font_model);
    m_spline_edit->m_ui.tableView->update();
    
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
    
    m_spline_edit->m_font_model = m_old_font_model;
    if(m_old_font_model != nullptr) m_spline_edit->m_ui.tableView->setModel(m_old_font_model);
    m_spline_edit->m_ui.tableView->update();
    
    QUndoCommand::undo();
}

