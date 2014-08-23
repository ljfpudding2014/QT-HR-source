#ifndef HRMAINWINDOW_H
#define HRMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class HRMainWindow;
}

class HRMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HRMainWindow(QWidget *parent = 0);
    ~HRMainWindow();

private:
    Ui::HRMainWindow *ui;
};

#endif // HRMAINWINDOW_H
