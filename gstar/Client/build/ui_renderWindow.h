/********************************************************************************
** Form generated from reading UI file 'renderWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERWINDOW_H
#define UI_RENDERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_renderWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *renderWindow)
    {
        if (renderWindow->objectName().isEmpty())
            renderWindow->setObjectName(QStringLiteral("renderWindow"));
        renderWindow->resize(800, 600);
        menubar = new QMenuBar(renderWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        renderWindow->setMenuBar(menubar);
        centralwidget = new QWidget(renderWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        renderWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(renderWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        renderWindow->setStatusBar(statusbar);

        retranslateUi(renderWindow);

        QMetaObject::connectSlotsByName(renderWindow);
    } // setupUi

    void retranslateUi(QMainWindow *renderWindow)
    {
        renderWindow->setWindowTitle(QApplication::translate("renderWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class renderWindow: public Ui_renderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERWINDOW_H
