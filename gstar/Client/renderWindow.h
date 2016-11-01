#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <QMainWindow>

namespace Ui {
class renderWindow;
}

class renderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit renderWindow(QWidget *parent = 0);
    ~renderWindow();

private:
    Ui::renderWindow *ui;
};

#endif // RENDERWINDOW_H
