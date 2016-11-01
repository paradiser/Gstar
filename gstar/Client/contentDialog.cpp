#include <QString>
#include <string>
#include <acceptStringThenReply.h>
#include "contentDialog.h"
#include "ui_contentDialog.h"

contentDialog::contentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contentDialog)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
//    connect(this, SIGNAL(strStatusChanged()), this, SLOT(setLabelText(getStr)));
}

contentDialog::~contentDialog()
{
    delete ui;
}

bool contentDialog::setLabelText(QString QStr)
{
    ui->label->setText(QStr);
    this->update();
    return true;
}

bool contentDialog::setButtonEnabled()
{
    ui->pushButton->setEnabled(true);
    return true;
}

bool contentDialog::setButtonDisabled()
{
    ui->pushButton->setDisabled(true);
    return true;
}

void contentDialog::on_pushButton_clicked()
{
    close();
}

std::string contentDialog::acceptString()
{
    string getStr = acceptStringThenReply();
    emit strStatusChanged();
    return getStr;
}
