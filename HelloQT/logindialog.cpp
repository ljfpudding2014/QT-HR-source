#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::GetUserName()
{
    return this->m_strUsername;
}

QString LoginDialog::GetPassword()
{
    return this->m_strPassword;
}

void LoginDialog::accept()
{
  
   if(m_strUsername.isEmpty() || m_strPassword.isEmpty() )
   {
        return;
    }
    else
    {
       return QDialog::accept();
    }

    return QDialog::accept();
}


void LoginDialog::on_buttonBox_clicked(QAbstractButton *button)
{


    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button )
    {
        if(!ui->lineEditUserName->text().isEmpty())
        {
           m_strUsername = ui->lineEditUserName->text();
        }
        else
        {
           QMessageBox message(QMessageBox::Warning,"警告","请输入用户名!",QMessageBox::Yes|QMessageBox::No,NULL);
           message.exec();
        }

        if(!ui->lineEditPassword->text().isEmpty())
        {
            m_strPassword = ui->lineEditPassword->text();
        }
        else
        {
          QMessageBox message(QMessageBox::Warning,"警告","请输入密码!",QMessageBox::Yes|QMessageBox::No,NULL);
          message.exec();
        }



    }
    else if( ui->buttonBox->button(QDialogButtonBox::Cancel) == button )
    {
        this->close();
        return;

    }
}
