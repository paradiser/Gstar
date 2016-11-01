#include "md5.h"
#include "dealCsv.h"
#include "sendString.h"
#include "sendThread.h"
#include "userFunction.h"
#include "contentDialog.h"
#include "mainInterface.h"
#include "registerWindow.h"
#include "ui_mainInterface.h"
#include <QDebug>
#include <QString>
#include <QProcess>
#include <QSplashScreen>
#include <QElapsedTimer>
#include <QDateTime>
#include <QPixmap>

mainInterface::mainInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainInterface)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    a = 0;
}

mainInterface::~mainInterface()
{
    delete ui;
}

void mainInterface::on_pushButton_clicked()
{
    /*QFile fp("../shell/scp_file.ep");
    if(fp.open(QFile::WriteOnly)) {
        QTextStream out(&fp);
        out << "#!/usr/bin/expect" << endl;
        out << "set timeout 6" << endl;
        out << "spawn scp -o ConnectTimeout=5 " << serverName << "@" << serverIp << endl;
        out << "expect {" << endl << "\t" << "\"no)?\" {" << endl;
        out << "\t\t" << "send \"yes\\r\"" << endl;
        out << "\t\t" << "expect \":\"" << endl;
        out << "\t\t" << "send \"" << serverPwd << "\\r\"" << endl << "\t}" << endl;
        out << "\t" << "\":\" {" << endl << "\t\t" << "send \"" << serverPwd
            << "\\r\"" << endl << "\t}" << endl;
        out << "}" << endl << "interact" << endl;
    }*/
    registerWindow * rWindow = new registerWindow(this);
    rWindow->setModal(true);
    rWindow->show();
}

void mainInterface::on_pushButton_2_clicked() {
    cDialog = new contentDialog();
    cDialog->setModal(true);
//    printf("ready to abc");
    if(ui->lineEdit->text().isEmpty()) {
        cDialog->setLabelText(QObject::tr("用户名不可为空！"));
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
        connect(sendThread, SIGNAL(allowed(QString, QString, QString, QString, QString)), this, SLOT(send_process_successed(QString, QString, QString, QString, QString)), Qt::AutoConnection);
        sendThread->start();
//        send_process = new QProcess(this);
//        connect(send_process, SIGNAL(started()), this, SLOT(send_process_started()));
//        send_process->start();

//    hide();

    }
}

/*
void mainInterface::send_process_started()
{
    qDebug() << "ready to get resultStr" << endl;
    resultStr = sendStringToMaster("LogIn," +
                                          ui->lineEdit->text().toStdString() + "," +
                                          MD5(ui->lineEdit_2->text().toStdString()).toString() + "," +
                                          getStringValue("../settings.csv", "ThisIp", 1) + ","
                                          + getStringValue("../settings.csv", "ThisPort", 1) + ",");
    qDebug() << QString::fromStdString(resultStr) << endl;
    vector<string> content=split(resultStr, ',');
    if(resultStr == "false") {
//          printf("abc");
        cDialog->setLabelText(QObject::tr("服务器连接失败，请确定您已联网且服务器已开启。"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }
    else if(content[0] == "Allow") {
        QString servername = QString::fromStdString(content[3]);
        QString password = QString::fromStdString(content[4]);
        QString ipaddress = QString::fromStdString(content[1]);
        QString username =  ui->lineEdit->text();
        QString portnum = QString::fromStdString(content[2]);
        close();
        UserFunction * userFunction = new UserFunction(servername, password, ipaddress, username, portnum, 0);
        userFunction->show();
    }
    else if(resultStr == "LogInUnsuccessfully") {
        cDialog->setLabelText(QObject::tr("用户名和密码不匹配！"));
        cDialog->setButtonEnabled();
        cDialog->show();
    }

}
*/

void mainInterface::send_process_successed(QString servername, QString password, QString ipaddress, QString username, QString portnum)
{
    QPixmap pixmap("../res/logo.jpg");
    QSplashScreen screen(pixmap);
    screen.show();
//    screen.showMessage("LOVE", Qt::AlignCenter, Qt::red);
#if 0
    int delayTime = 1;
    QElapsedTimer timer;
    timer.start();

    while(timer.elapsed() < (delayTime * 1000))
    {
         qApp->processEvents();
    }
#endif

#if 1
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        qApp->processEvents();
    } while (n.secsTo(now)<=1);//5为需要延时的秒数
#endif

    cout << "ready to open userFunction" << endl;
    UserFunction * userFunction = new UserFunction(servername, password, ipaddress, username, portnum);
    userFunction->show();
}
