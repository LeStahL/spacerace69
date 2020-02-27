#ifndef SPLINEEDIT_HPP
#define SPLINEEDIT_HPP

#include <QMainWindow>
#include "ui_SplineEdit.h"

#include "FontModel.hpp"
#include "Font.hpp"

class SplineEdit : public QMainWindow
{
public:
    SplineEdit(QApplication *app);
    virtual ~SplineEdit();
    
private:
    Ui::SplineEdit m_ui;
    QApplication *m_app;
};

#endif
