#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QProcess>
#include <vector>
#include <string>

using namespace::std;

namespace Ui {
    class registerWindow;
}

class registerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerWindow(QWidget *parent = 0);
    ~registerWindow();
    vector<string> content;

signals:
    void newdocker_finished();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void newdocker_process_started();
    void newdocker_process_finished(int , QProcess::ExitStatus);

    void stopdocker_process_started();
    void stopdocker_process_finished(int , QProcess::ExitStatus);

    void send_process_successed(QString command);
    void command_finished_get(QString command);

private:
    Ui::registerWindow *ui;
};

#endif // REGISTERWINDOW_H
