#ifndef CONTENTDIALOG_H
#define CONTENTDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class contentDialog;
}

class contentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit contentDialog(QWidget *parent = 0);
    ~contentDialog();
    bool setLabelText(QString);
    bool setButtonEnabled();
    bool setButtonDisabled();
    std::string acceptString();
    std::string labelStr, getStr;

signals:
    void strStatusChanged();

private slots:
    void on_pushButton_clicked();

private:
    Ui::contentDialog *ui;
};

#endif // CONTENTDIALOG_H
