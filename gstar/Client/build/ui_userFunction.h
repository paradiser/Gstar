/********************************************************************************
** Form generated from reading UI file 'userFunction.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFUNCTION_H
#define UI_USERFUNCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserFunction
{
public:
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QWidget *centralwidget;
    QTextEdit *outputDialog;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_R;

    void setupUi(QMainWindow *UserFunction)
    {
        if (UserFunction->objectName().isEmpty())
            UserFunction->setObjectName(QStringLiteral("UserFunction"));
        UserFunction->resize(540, 372);
        UserFunction->setStyleSheet(QLatin1String("QWidget {\n"
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
        action_2 = new QAction(UserFunction);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(UserFunction);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(UserFunction);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(UserFunction);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(UserFunction);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(UserFunction);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_8 = new QAction(UserFunction);
        action_8->setObjectName(QStringLiteral("action_8"));
        centralwidget = new QWidget(UserFunction);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        outputDialog = new QTextEdit(centralwidget);
        outputDialog->setObjectName(QStringLiteral("outputDialog"));
        outputDialog->setGeometry(QRect(50, 269, 431, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 471, 17));
        label->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 80, 161, 121));
        pushButton->setStyleSheet(QStringLiteral("image: url(:/res/render.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/render.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(96, 96));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 80, 161, 121));
        pushButton_2->setStyleSheet(QStringLiteral("image: url(:/res/render.png);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/uploadAndRender.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(96, 96));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 220, 201, 20));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 220, 221, 20));
        label_3->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        label_3->setAlignment(Qt::AlignCenter);
        UserFunction->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserFunction);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserFunction->setStatusBar(statusbar);
        menubar = new QMenuBar(UserFunction);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 540, 27));
        menubar->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        menubar->setNativeMenuBar(true);
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_F->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        menu_R = new QMenu(menubar);
        menu_R->setObjectName(QStringLiteral("menu_R"));
        UserFunction->setMenuBar(menubar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(pushButton);
        label_3->setBuddy(pushButton_2);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_R->menuAction());
        menu_F->addAction(action_2);
        menu_F->addAction(action_6);
        menu_F->addSeparator();
        menu_F->addAction(action_8);
        menu_F->addAction(action_3);
        menu_R->addAction(action_5);
        menu_R->addAction(action_7);

        retranslateUi(UserFunction);

        QMetaObject::connectSlotsByName(UserFunction);
    } // setupUi

    void retranslateUi(QMainWindow *UserFunction)
    {
        UserFunction->setWindowTitle(QApplication::translate("UserFunction", "render", 0));
        action_2->setText(QApplication::translate("UserFunction", "\344\270\212\344\274\240\346\226\207\344\273\266(&U)", 0));
        action_2->setShortcut(QApplication::translate("UserFunction", "Ctrl+U", 0));
        action_3->setText(QApplication::translate("UserFunction", "\351\200\200\345\207\272(&X)", 0));
        action_3->setShortcut(QApplication::translate("UserFunction", "Ctrl+X", 0));
        action_4->setText(QApplication::translate("UserFunction", "\346\226\260\345\273\272\346\270\262\346\237\223", 0));
        action_5->setText(QApplication::translate("UserFunction", "\346\241\214\351\235\242\346\270\262\346\237\223(&D)", 0));
        action_6->setText(QApplication::translate("UserFunction", "\344\270\213\350\275\275\346\226\207\344\273\266(&D)", 0));
        action_6->setShortcut(QApplication::translate("UserFunction", "Ctrl+D", 0));
        action_7->setText(QApplication::translate("UserFunction", "\351\207\215\347\275\256\346\270\262\346\237\223(&F)", 0));
        action_8->setText(QApplication::translate("UserFunction", "\346\263\250\351\224\200(&L)", 0));
        action_8->setShortcut(QApplication::translate("UserFunction", "Ctrl+L", 0));
        label->setText(QApplication::translate("UserFunction", "\346\202\250\345\217\257\344\273\245\344\275\277\347\224\250\344\273\245\344\270\213\344\270\244\347\247\215\346\226\271\345\274\217\346\235\245\350\277\233\350\241\214\346\270\262\346\237\223\357\274\232", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QApplication::translate("UserFunction", "\344\270\212\344\274\240\346\226\207\344\273\266\345\271\266\346\270\262\346\237\223(&U)", 0));
        label_3->setText(QApplication::translate("UserFunction", "\346\211\223\345\274\200\346\241\214\351\235\242\347\216\257\345\242\203\345\271\266\346\270\262\346\237\223(&D)", 0));
        menu_F->setTitle(QApplication::translate("UserFunction", "\346\226\207\344\273\266(&F)", 0));
        menu_R->setTitle(QApplication::translate("UserFunction", "\346\270\262\346\237\223(&R)", 0));
    } // retranslateUi

};

namespace Ui {
    class UserFunction: public Ui_UserFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFUNCTION_H
