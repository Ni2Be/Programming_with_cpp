/********************************************************************************
** Form generated from reading UI file 'qttry.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTRY_H
#define UI_QTTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTtryClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTtryClass)
    {
        if (QTtryClass->objectName().isEmpty())
            QTtryClass->setObjectName(QStringLiteral("QTtryClass"));
        QTtryClass->resize(600, 400);
        menuBar = new QMenuBar(QTtryClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QTtryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTtryClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTtryClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTtryClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QTtryClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTtryClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTtryClass->setStatusBar(statusBar);

        retranslateUi(QTtryClass);

        QMetaObject::connectSlotsByName(QTtryClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTtryClass)
    {
        QTtryClass->setWindowTitle(QApplication::translate("QTtryClass", "QTtry", 0));
    } // retranslateUi

};

namespace Ui {
    class QTtryClass: public Ui_QTtryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTRY_H
