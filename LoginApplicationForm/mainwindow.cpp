#include "mainwindow.h"
#include<QPushButton>
#include<QLineEdit>
#include<QMessageBox>
#include<QVBoxLayout>
#include<QDebug>
#include<QLabel>
#include<QFont>
#include<dialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Image icon for username
    QLabel *lab=new QLabel(this);
    lab->setMinimumSize(150,100);
    lab->move(100,50);
    QPixmap p("C:/Users/mohit/OneDrive/Desktop/qt/login.jpg");
    lab->setPixmap(p.scaled(20,20));

    // image icon for username
    QLabel *mlabel=new QLabel(this);
    mlabel->move(180,25);
    mlabel->setAlignment(Qt::AlignHCenter);
    QPixmap pi("C:/Users/mohit/OneDrive/Desktop/qt/username.png");
    mlabel->setPixmap(pi.scaled(20,20));

    //label for username
    QLabel *lab1=new QLabel("UserName",this);
    lab1->setMinimumSize(70,50);
    lab1->move(130,50);
    QPalette pal;
    pal.setColor(QPalette::WindowText,Qt::red);
    lab1->setPalette(pal);

    //Qlineedit for username
    QLineEdit *line1=new QLineEdit(this);
    line1->setMinimumSize(200,50);
    line1->move(220,50);
    line1->setStyleSheet("border:1px solid red");

    //image icon for password
    QLabel *labpass=new QLabel(this);
    labpass->move(100,110);
    labpass->setMinimumSize(200,50);
    QPixmap pix("C:/Users/mohit/OneDrive/Desktop/qt/password.png");
    labpass->setPixmap(pix.scaled(20,20));

    //label for password
    QLabel *pass=new QLabel("Password",this);
    pass->setMinimumSize(70,50);
    pass->move(130,110);
    QPalette pall;
    pall.setColor(QPalette::WindowText,Qt::green);
    pass->setPalette(pall);

    //lineedit for password
    QLineEdit *line2=new QLineEdit(this);
    line2->setMinimumSize(200,50);
    line2->move(220,110);
    line2->setEchoMode(QLineEdit::Password);
    line2->setStyleSheet("border:1px solid green");

    QLabel *acc=new QLabel("Don't have account?",this);
    acc->setMinimumSize(110,60);
    acc->move(110,170);

    QFont button1("good brush",8,QFont::Bold);
    QPushButton *btn1=new QPushButton("Sign Up",this);
    btn1->setFont(button1);
    btn1->move(220,180);
    connect(btn1,&QPushButton::clicked,[=](){
            Dialog *d=new Dialog(this);
            d->exec();
        });

        QFont button("good brush",18,QFont::Bold);
        QPushButton *btn=new QPushButton("Login",this);
        btn->setFont(button);
        btn->move(220,280);
        connect(btn,&QPushButton::clicked,[=](){
            QString uname=line1->text();
            QString p=line2->text();
            if(uname=="mohith"&& p=="pass")
            {
                QMessageBox::information(this,"Login","Username and password are correct!");
            }
            else
            {
                QMessageBox::information(this,"Login","Username or Password is incorrect");
            }
        });
       line1->setPlaceholderText("username");
       line2->setPlaceholderText("password");

}

MainWindow::~MainWindow()
{
}

