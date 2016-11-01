#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include "contentDialog.h"
#include <QProcess>
#include <QDialog>
#include <string>

using namespace::std;

namespace Ui {
    class mainInterface;
}

class mainInterface : public QDialog
{
    Q_OBJECT

public:
    explicit mainInterface(QWidget *parent = 0);
    ~mainInterface();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
//    void send_process_started();
    void send_process_successed(QString, QString, QString, QString, QString);

private:
    Ui::mainInterface *ui;
    int a;
    std::string resultStr;
    QProcess * send_process;
    contentDialog * cDialog;
};

#endif // MAININTERFACE_H
