#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    
public slots:
   void accept();

private:
    Ui::LoginDialog *ui;

private:
    QString m_strUsername;
    QString m_strPassword;

public:
    QString GetUserName();
    QString GetPassword();

};

#endif // LOGINDIALOG_H
