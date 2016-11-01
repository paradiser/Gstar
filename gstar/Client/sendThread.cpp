#include "userFunction.h"
#include "sendString.h"
#include "sendThread.h"
#include "dealCsv.h"
#include <QDebug>
#include <QProcess>

using namespace::std;

SendThread::SendThread(string usernameStr, string passwordMD5, mainInterface * mInterface, contentDialog * cDialog, QObject *parent) :
    QThread(parent)
{
    this->usernameStr = usernameStr;
    this->passwordMD5 = passwordMD5;
    this->mInterface = mInterface;
    this->cDialog = cDialog;
    this->rWindow = NULL;
    stop = false;
    sendStr = "LogIn," + usernameStr + "," + passwordMD5 + "," +
            getStringValue("../settings.csv", "ThisIp", 1) + "," +
            getStringValue("../settings.csv", "ThisPort", 1) + ",";
}

SendThread::SendThread(string usernameStr, string passwordMD5, registerWindow * rWindow, contentDialog * cDialog, QObject *parent) :
    QThread(parent)
{
    this->usernameStr = usernameStr;
    this->passwordMD5 = passwordMD5;
    this->rWindow = rWindow;
    this->cDialog = cDialog;
    this->mInterface = NULL;
    stop = false;
    sendStr = "Register," + usernameStr + "," + passwordMD5 + "," +
            getStringValue("../settings.csv", "ThisIp", 1) + "," +
            getStringValue("../settings.csv", "ThisPort", 1) + ",";
}

void SendThread::run()
{
    qDebug() << "ready to get resultStr" << endl;
    string resultStr = sendStringToMaster(sendStr);
    qDebug() << QString::fromStdString(resultStr) << endl;
    content=split(resultStr, ',');
    if(rWindow != NULL) {
        connect(rWindow, SIGNAL(newdocker_finished()), this, SLOT(newdocker_finished_thread()), Qt::AutoConnection);
    }
    if(resultStr == "false") {
//          printf("abc");
        cDialog->setLabelText(QObject::tr("服务器连接失败，请确定您已联网且服务器已开启"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
    else if(content[0] == "Allow") {
        QString servername = QString::fromStdString(content[3]);
        QString password = QString::fromStdString(content[4]);
        QString ipaddress = QString::fromStdString(content[1]);
        QString username = QString::fromStdString(usernameStr);
        QString portnum = QString::fromStdString(content[2]);
        emit allowed(servername, password, ipaddress, username, portnum);
//        cout << "emited!" << endl;
        mInterface->close();
        cDialog->close();
//        UserFunction * userFunction = new UserFunction(servername, password, ipaddress, username, portnum, 0);
//        userFunction->show();
    }
    else if(resultStr == "LogInUnsuccessfully") {
        cDialog->setLabelText(QObject::tr("用户名和密码不匹配！"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
    else if(content[0] == "New") {
        cDialog->setLabelText(QObject::tr("注册成功！"));
        cDialog->setButtonEnabled();
        cDialog->show();
        //注册成功后为用户创建docker
        QString servername = QString::fromStdString(content[3]);
        QString password = QString::fromStdString(content[4]);
        QString ipaddress = QString::fromStdString(content[1]);
        QString username = QString::fromStdString(usernameStr);
        QString portnum = QString::fromStdString(content[2]);
        QString command = "sh ../shell/new_docker";
        command += " " + servername;
        command += " " + password;
        command += " " + ipaddress;
        command += " " + username;
        command += " " + portnum;
        qDebug() << command << endl;
        emit registered(command);
        rWindow->close();
    }
    else if(resultStr == "AddUserUnsuccessfully") {
        cDialog->setLabelText(QObject::tr("注册失败！"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
    else if(resultStr == "Exist") {
        cDialog->setLabelText(QObject::tr("用户名已经存在！"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
}

void SendThread::newdocker_finished_thread()
{
    QString servername = QString::fromStdString(content[3]);
    QString password = QString::fromStdString(content[4]);
    QString ipaddress = QString::fromStdString(content[1]);
    QString username = QString::fromStdString(usernameStr);
    QString command = "sh ../shell/stop_docker";
    command += " " + servername;
    command += " " + password;
    command += " " + ipaddress;
    command += " " + username;
    qDebug() << command << endl;
    emit command_finished(command);
}
