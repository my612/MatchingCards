#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "playing.h"
#include <stdexcept>

//Class Playing;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->label_3->setVisible(false);
    QPixmap pix(":/images/img2.png");
    int w = ui->label_4->width();
    int h = ui->label_4->height();
    ui->label_4->setPixmap(pix.scaled(w , h , Qt::KeepAspectRatio));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}




    void LoginWindow::on_login_button_clicked()
    {
        bool loginsuccessful = false;
        QString enteredUsername = ui->username_label->text();
        QString enteredPassword = ui->password_label->text();

        for (int i = 0; i < usersCount; i++)
        {
            if (usernames[i] == enteredUsername && passwords[i] == enteredPassword)
            {
                loginsuccessful = true;
                this->close();
                Playing* playing= new Playing();
                playing->view->show();
            }
        }

        if (!loginsuccessful)
        {
            ui->label_3->setVisible(true);
            // Clear the entered username and password fields
            ui->username_label->clear();
            ui->password_label->clear();
        }
    }




    /* bool loginsuccessful = false;
    for (int i=0;i<usersCount;i++)
    {
        if(usernames[i]==ui->username_label->text() && passwords[i]==ui->password_label->text())
        {
            loginsuccessful=true;
            WelcomeWindow* welcomewin = new WelcomeWindow(ui->username_label->text(),ages[i]);
            welcomewin->show();
            this->close();}

    }

    if (!loginsuccessful)
    {
        ui->label_3->setVisible(true);
    }*/




void LoginWindow::on_register_button_clicked()
{

    this->close();
}

