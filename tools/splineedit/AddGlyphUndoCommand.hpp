#ifndef ADDGLYPHUNDOCOMMAND_HPP
#define ADDGLYPHUNDOCOMMAND_HPP

#include <QUndoCommand>

#include "Font.hpp"
#include "Glyph.hpp"
#include "SplineEdit.hpp"

class AddGlyphUndoCommand : public QUndoCommand
{
public:
    AddGlyphUndoCommand(SplineEdit *splineEdit, Font *font, Glyph *glyph = nullptr);
    virtual ~AddGlyphUndoCommand();
    
    void undo() override;
    void redo() override;
    
    Font *m_font;
    Glyph *m_glyph;
    SplineEdit *m_spline_edit;
};

#endif
