#ifndef NEWFONTUNDOOPERATION_HPP
#define NEWFONTUNDOOPERATION_HPP

#include <QUndoCommand>

#include "Font.hpp"
#include "SplineEdit.hpp"
#include "FontModel.hpp"

class NewFontUndoCommand : public QUndoCommand
{
public:
    NewFontUndoCommand(SplineEdit *splineEdit, Font *font = nullptr);
    virtual ~NewFontUndoCommand();
    
    void undo() override;
    void redo() override;
    
    Font *m_font, *m_old_font;
    SplineEdit *m_spline_edit;
    FontModel *m_font_model, *m_old_font_model;
};

#endif
