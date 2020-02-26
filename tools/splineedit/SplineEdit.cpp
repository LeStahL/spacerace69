#include <QApplication>

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
}

SplineEdit::~SplineEdit()
{
}
