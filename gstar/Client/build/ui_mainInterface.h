/********************************************************************************
** Form generated from reading UI file 'mainInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAININTERFACE_H
#define UI_MAININTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainInterface
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;

    void setupUi(QDialog *mainInterface)
    {
        if (mainInterface->objectName().isEmpty())
            mainInterface->setObjectName(QStringLiteral("mainInterface"));
        mainInterface->resize(320, 146);
        mainInterface->setStyleSheet(QLatin1String("QWidget {\n"
"	color: rgb(241, 241, 241);\n"
"	background-color: rgb(59, 59, 59)\n"
"}\n"
"QMenuBar{\n"
"	background-color: rgb(143, 143, 143);\n"
"}\n"
"QPushButton {\n"
"	background-color: rgb(134, 134, 134);\n"
"}\n"
"\n"
"QTextEdit {\n"
"	background-color: rgb(134, 134, 134);\n"
"}"));
        verticalLayoutWidget = new QWidget(mainInterface);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 17, 221, 104));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setOpenExternalLinks(false);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(false);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 10, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label = new QLabel(mainInterface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 128, 61, 17));
        label->setStyleSheet(QLatin1String("font: 9pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"text-decoration: underline;"));
        label->setAlignment(Qt::AlignCenter);
        label->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEdit);
        label_3->setBuddy(lineEdit_2);
#endif // QT_NO_SHORTCUT

        retranslateUi(mainInterface);

        pushButton_2->setDefault(true);


        QMetaObject::connectSlotsByName(mainInterface);
    } // setupUi

    void retranslateUi(QDialog *mainInterface)
    {
        mainInterface->setWindowTitle(QApplication::translate("mainInterface", "mainInterface", 0));
        label_2->setText(QApplication::translate("mainInterface", "\347\224\250\346\210\267\345\220\215(&U)\357\274\232", 0));
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("mainInterface", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\347\224\250\346\210\267\345\220\215", 0));
        label_3->setText(QApplication::translate("mainInterface", "\345\257\206\347\240\201(&P)\357\274\232\343\200\200", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("mainInterface", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("mainInterface", "\346\263\250\345\206\214(&R)", 0));
        pushButton_2->setText(QApplication::translate("mainInterface", "\347\231\273\345\275\225(&L)", 0));
        label->setText(QApplication::translate("mainInterface", "\346\270\270\345\256\242\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class mainInterface: public Ui_mainInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAININTERFACE_H
