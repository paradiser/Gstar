#include <QApplication>
#include <iostream>
#include "md5.h"
#include "communication.h"
#include "mainInterface.h"
#include <QDebug>
#include "cmysplashscreen.h"
#include <QPixmap>
#include <QTimer>
#include <QDesktopWidget>

using namespace::std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//  Communication w;
    mainInterface mInterface; //新建mainInterface类对象
    mInterface.setWindowTitle(QObject::tr("登录"));

    QPixmap pixmap("../res/logo.jpg");
    pixmap.scaled(QApplication::desktop()->availableGeometry().size(),Qt::KeepAspectRatio);
    CMySplashScreen *splash = new CMySplashScreen(pixmap,3500);
    splash->setDisabled(true);//禁用用户的输入事件响应
    splash->show();
    QTimer::singleShot(3500, &mInterface, SLOT(show()));
    return a.exec();
}
