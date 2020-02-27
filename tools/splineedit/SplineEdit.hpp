#ifndef SPLINEEDIT_HPP
#define SPLINEEDIT_HPP

#include <QMainWindow>
#include <QUndoStack>
#include "ui_SplineEdit.h"

#include "FontModel.hpp"
#include "Font.hpp"

class SplineEdit : public QMainWindow
{
    Q_OBJECT
    
public:
    SplineEdit(QApplication *app);
    virtual ~SplineEdit();
    
    void manageEnabled();
    
private slots:
    void fileNew();
    void editUndo();
    void editRedo();
    void fontAddGlyph();
    
public:
    Ui::SplineEdit m_ui;
    QApplication *m_app;
    QUndoStack m_undo_stack;
    Font *m_font;
    FontModel *m_font_model;
};

#endif
