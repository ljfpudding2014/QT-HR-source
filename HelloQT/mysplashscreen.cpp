    #include "mysplashscreen.h"
     
      
    MySplashScreen::MySplashScreen(const QPixmap& pixmap) : QSplashScreen(pixmap)        
    {  
        ProgressBar = new QProgressBar(this); // 父类为MySplashScreen  
        ProgressBar->setGeometry(0,100-16,500,16);  
        ProgressBar->setRange(0, 100);  
        ProgressBar->setValue(0);  
        ProgressBar->setTextVisible(false);
        connect(ProgressBar, SIGNAL(valueChanged(int)), this, SLOT(progressChanged(int))); //值改变时，立刻repaint  
      
        //QFont font;  
        //font.setPointSize(16);  
        //ProgressBar->setFont(font); // 设置进度条里面的字体  
      
    }  
      
    MySplashScreen::~MySplashScreen()  
    {  
    }  
      
    void MySplashScreen::setProgress(int value)  
    {  
            ProgressBar->setValue(value);  
    }  
      
      
    void MySplashScreen::progressChanged(int)  
    {  
        repaint();  
    }  