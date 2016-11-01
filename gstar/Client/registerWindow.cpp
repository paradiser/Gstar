#include "contentDialog.h"
#include "md5.h"
#include "dealCsv.h"
#include "sendString.h"
#include "sendThread.h"
#include "registerWindow.h"
#include "acceptStringThenReply.h"
#include "ui_registerWindow.h"
#include <QProcess>
#include <QDebug>

registerWindow::registerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::on_pushButton_clicked()
{
    contentDialog * cDialog = new contentDialog();
    contentDialog * cDialog_2 = new contentDialog();
    cDialog->setModal(true);
    cDialog_2->setModal(true);
//    printf("ready to abc");
    if(ui->lineEdit->text().isEmpty()) {
        cDialog->setLabelText(QObject::tr("用户名不可为空！"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
    else if(ui->lineEdit_2->text() != ui->lineEdit_3->text()) {
        cDialog->setLabelText(QObject::tr("密码填写不一致！"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
    else {
        cDialog->setLabelText(QObject::tr("正在连接服务器……"));
        cDialog->setButtonDisabled();
        cDialog->show();
        SendThread * sendThread = new SendThread(ui->lineEdit->text().toStdString(),
                                               MD5(ui->lineEdit_2->text().toStdString()).toString(),
                                               this, cDialog);
        connect(sendThread, SIGNAL(registered(QString)), this, SLOT(send_process_successed(QString)), Qt::AutoConnection);
        connect(sendThread, SIGNAL(command_finished(QString)), this, SLOT(command_finished_get(QString)), Qt::AutoConnection);
        sendThread->start();
/*
        string resultString = sendStringToMaster("Register," +
                              ui->lineEdit->text().toStdString() + "," +
                              MD5(ui->lineEdit_2->text().toStdString()).toString() + "," +
                              getStringValue("../settings.csv", "ThisIp", 1) + "," +
                              getStringValue("../settings.csv", "ThisPort", 1) + ",");
        vector<string> content=split(resultString, ',');
        if(resultString == "false") {
//          printf("abc");
            cDialog_2->setLabelText(QObject::tr("服务器连接失败，请确定您已联网且服务器已开启。"));
            cDialog_2->setButtonEnabled();
            cDialog_2->show();
            cDialog->close();
        }
        else if(content[0] == "New") {
            cDialog_2->setLabelText(QObject::tr("注册成功！"));
            cDialog_2->setButtonEnabled();
            cDialog_2->show();
            cDialog->close();
            close();
            //注册成功后为用户创建docker
            QString servername = QString::fromStdString(content[3]);
            QString password = QString::fromStdString(content[4]);
            QString ipaddress = QString::fromStdString(content[1]);
            QString username =  ui->lineEdit->text();
            QString portnum = QString::fromStdString(content[2]);
            QString command = "sh ../shell/new_docker";
            command += " " + servername;
            command += " " + password;
            command += " " + ipaddress;
            command += " " + username;
            command += " " + portnum;
            QProcess *p = new QProcess(this);
            connect(p , SIGNAL(started()) , this ,
                    SLOT(newdocker_process_started()));
            connect(p , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
                    SLOT(newdocker_process_finished(int,QProcess::ExitStatus)));
            p->start(command);
            qDebug() << command << endl;
        }
        else if(resultString == "AddUserUnsuccessfully") {
            cDialog_2->setLabelText(QObject::tr("注册失败！"));
            cDialog_2->setButtonEnabled();
            cDialog_2->show();
            cDialog->close();
        }
        else if(resultString == "Exist") {
            cDialog_2->setLabelText(QObject::tr("用户名已经存在！"));
            cDialog_2->setButtonEnabled();
            cDialog_2->show();
            cDialog->close();
        }
*/
/*
        if(replyStr == "AddUserSuccessfully") {
            cDialog->setLabelText(QObject::tr("注册成功！"));
            cDialog->setButtonEnabled();
            cDialog->show();
            close();
        }
        else if(replyStr == "AddUserUnsuccessfully") {
            cDialog->setLabelText(QObject::tr("注册失败！"));
            cDialog->setButtonEnabled();
            cDialog->show();
            close();
        }
        else if(replyStr == "Exist") {
            cDialog->setLabelText(QObject::tr("用户名已经存在！"));
            cDialog->setButtonEnabled();
            cDialog->show();
            close();
        }
*/
    }
}

void registerWindow::on_pushButton_2_clicked()
{
    close();
}

void registerWindow::newdocker_process_started() {
    qDebug() << "started !" << endl;
    //qDebug() << "servername: " << servername << ", password: " << password
             //<< endl;
}

void registerWindow::newdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
    if(exitStatus == QProcess::NormalExit) {
        qDebug() << "finished !" << endl;
        emit newdocker_finished();
    } else {
        qDebug() << "failed !" << endl;
    }
}

void registerWindow::stopdocker_process_started() {
    qDebug() << "stopping !" << endl;
    //qDebug() << "servername: " << servername << ", password: " << password
             //<< endl;
}

void registerWindow::stopdocker_process_finished(int , QProcess::ExitStatus) {
    qDebug() << "stopped !" << endl;
    //qDebug() << "servername: " << servername << ", password: " << password
             //<< endl;
}

void registerWindow::send_process_successed(QString command)
{
    QProcess *p = new QProcess(this);
    connect(p , SIGNAL(started()) , this ,
            SLOT(newdocker_process_started()));
    connect(p , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
            SLOT(newdocker_process_finished(int,QProcess::ExitStatus)));
    p->start(command);
}

void registerWindow::command_finished_get(QString command)
{
    QProcess *stop = new QProcess(this);
    connect(stop , SIGNAL(started()) , this ,
            SLOT(stopdocker_process_started()));
    connect(stop , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
            SLOT(stopdocker_process_finished(int,QProcess::ExitStatus)));
    stop->start(command);
}
