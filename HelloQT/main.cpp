#include <QtCore/QVariant>
#include <QtGui/QApplication>
#include "logindialog.h"
#include <QMessageBox>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QMotifStyle>

//��Ҫ�������ĸ�ʽ QTextCodec
#include <QTextCodec>

#include <Createdbtable.h>
#include <mysplashscreen.h>

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

   //��������е���������
   //QTextCodec::codecForName("UTF-8");
   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

   QApplication::setStyle("macintosh");
   
   //QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath())+QDir::separator()+"plugins");
   //a.addLibraryPath(strLibPath); 

   
    MySplashScreen *splash = new MySplashScreen(QPixmap(":/debug/images/logo.png"));
    splash->show(); // ��ʾ  
    splash->setGeometry(128,72,500,100); 

   
   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

   db.setHostName("localhost");   //���ݿ������
   db.setDatabaseName("qtdb");   //���ݿ���
   db.setUserName("qtuser");      //��¼��
   db.setPassword("qtuser");    //����

   if(db.open())
   {
	QSqlQuery query;
    
	InitDBTableStringObj intobj;
     query.clear();
     query.exec(intobj.GetClassSQL());

    splash->setProgress(16);// ��ʾ16%  

    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    //do{
       //now=QDateTime::currentDateTime();
    //} while (n.secsTo(now)<=6);//6Ϊ��Ҫ��ʱ������

    //sleep(3);  

	  
      query.clear();
      query.exec(intobj.GetCourseSQL());

    splash->setProgress(32); 
    //sleep(3);  

	n=QDateTime::currentDateTime();
    //do{
    //   now=QDateTime::currentDateTime();
   // } while (n.secsTo(now)<=6);//6Ϊ��Ҫ��ʱ������
      
      query.clear();
      query.exec(intobj.GetTeacherSQL());

    splash->setProgress(48); 
    //sleep(3);  
n=QDateTime::currentDateTime();
   //do{
    //   now=QDateTime::currentDateTime();
   // } while (n.secsTo(now)<=6);//6Ϊ��Ҫ��ʱ������
      
	  query.clear();
      query.exec(intobj.GetStudentSQL());

  splash->setProgress(64); 
    //sleep(3); 
n=QDateTime::currentDateTime();
   //do{
   //    now=QDateTime::currentDateTime();
   // } while (n.secsTo(now)<=6);//6Ϊ��Ҫ��ʱ������

      
	  query.clear();
      query.exec(intobj.GetCourseHasTeacherSQL());

  splash->setProgress(80); 
    //sleep(3);
n=QDateTime::currentDateTime(); 
   //do{
   //    now=QDateTime::currentDateTime();
   // } while (n.secsTo(now)<=6);//6Ϊ��Ҫ��ʱ������
      
	  query.clear();
      query.exec(intobj.GetStudentHasCourseSQL());

  splash->setProgress(100); 
    //sleep(3); 






      QString loginusername = "";
      QString loginpasswod = "";

      LoginDialog dlg;
      //dlg.exec();
    splash->finish(&dlg); // ��ʧ  
    delete splash; 

      if(dlg.exec() == QDialog::Accepted)
      {
          loginusername = dlg.GetUserName();
          loginpasswod = dlg.GetPassword();
      }
      else
      {
            a.exit();
      }

      query.clear();
      query.exec("SELECT * FROM qt_user");
      QString strusername = "";
      QString strpassword = "";

      bool bFindUser = false;
      while(query.next())
      {
          strusername = (QString)query.value(1).toString();
          if(loginusername == strusername)
          {
                          bFindUser = true;
              strpassword = (QString)query.value(3).toString();
              if(strpassword == loginpasswod)
                  break;
              else
              {
                  QMessageBox message(QMessageBox::Warning,"����","���벻��ȷ!",QMessageBox::Yes|QMessageBox::No,NULL);
                  message.exec();
                  a.exit();
                  return 0;
              }
          }
      }
	  
	  if(!bFindUser)
	  {
         QMessageBox message(QMessageBox::Warning,"����","�û�������ȷ",QMessageBox::Yes|QMessageBox::No,NULL);
         message.exec();
         a.exit();
         return 0;	  
	  }

 
  	  
	  
 
      QMessageBox message(QMessageBox::Information,"Information","Complete Database Tables",QMessageBox::Yes|QMessageBox::No,NULL);
      message.exec();
	  

	  
	  
	  a.exit();
	  
	  
	  return 0;

      //QString name = query.value(1).toString();
      //query.exec("update patient_basic_info set sex ='m 'where patient_id = 3");
      //query.exec("DELETE FROM patient_basic_info where patient_id = 3");
      //query.exec("SELECT patient_id , patient_name,ID_card_no,sex FROM patient_basic_info");//nameΪ��������
      //query.next();
      //QString name = query.value(1).toString();                                                                                 w.ui.patient_name_text->setText(name);
      //model=new QSqlQueryModel;
      //model->setQuery(query);
       //table->setModel(model);
    }
    else
    {
    // ���ݿ��ʧ�ܣ���ʾ���ݿⷵ�ص�ʧ����Ϣ
       QMessageBox::critical(0,"���ݿ��ʧ��",db.lastError().text());
       a.exit();
       return 0;
    }
    
     QApplication::connect(&a, SIGNAL(lastWindowClose()), &a, SLOT(quit()));

    return a.exec();;
}
