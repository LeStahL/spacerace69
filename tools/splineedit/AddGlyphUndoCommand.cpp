#include "AddGlyphUndoCommand.hpp"

AddGlyphUndoCommand::AddGlyphUndoCommand(SplineEdit* splineEdit, Font* font, Glyph* glyph)
    : QUndoCommand()
    , m_spline_edit(splineEdit)
    , m_font(font)
    , m_glyph(glyph)
{
    if(m_glyph == nullptr) m_glyph = new Glyph;
}

AddGlyphUndoCommand::~AddGlyphUndoCommand()
{
    delete m_glyph;
}

void AddGlyphUndoCommand::redo()
{
    m_font->m_glyphs.push_back(m_glyph);
    m_spline_edit->m_ui.graphicsView->setEnabled(true);
    m_spline_edit->m_ui.tableView->update();
    
    QUndoCommand::redo();
}

void AddGlyphUndoCommand::undo()
{
    m_font->m_glyphs.removeOne(m_glyph);
    if(m_font->m_glyphs.empty()) m_spline_edit->m_ui.graphicsView->setEnabled(false);
    m_spline_edit->m_ui.tableView->update();
    
    QUndoCommand::undo();
}
