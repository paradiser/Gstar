#ifndef SENDTHREAD_H
#define SENDTHREAD_H
#include <QThread>
#include <string>
#include <vector>
#include "mainInterface.h"
#include "registerWindow.h"
#include "contentDialog.h"

using namespace::std;

class SendThread : public QThread
{
    Q_OBJECT
public:
    bool stop ;
    explicit SendThread(string, string, mainInterface *, contentDialog *, QObject *parent = 0);
    explicit SendThread(string, string, registerWindow *, contentDialog *, QObject *parent = 0);
    void run();

signals:
    void allowed(QString, QString, QString, QString, QString);
    void registered(QString);
    void command_finished(QString);

private slots:
    void newdocker_finished_thread();

private:
    string usernameStr;
    string passwordMD5;
    string sendStr;
    contentDialog * cDialog;
    mainInterface * mInterface;
    registerWindow * rWindow;
    vector<string> content;
};
#endif // MYTHREAD_H
