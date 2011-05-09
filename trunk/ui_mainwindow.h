/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Apr 24 17:39:40 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *openfileBTN;
    QLineEdit *fileLine;
    QToolButton *prevBTN;
    QToolButton *nextBTN;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QToolButton *blackBTN;
    QToolButton *whiteBTN;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QDoubleSpinBox *satSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *reprocBTN;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *saveLayoutBTN;
    QSpacerItem *horizontalSpacer_3;
    QLabel *proglabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_7;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(753, 580);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        openfileBTN = new QPushButton(centralWidget);
        openfileBTN->setObjectName(QString::fromUtf8("openfileBTN"));

        horizontalLayout->addWidget(openfileBTN);

        fileLine = new QLineEdit(centralWidget);
        fileLine->setObjectName(QString::fromUtf8("fileLine"));

        horizontalLayout->addWidget(fileLine);

        prevBTN = new QToolButton(centralWidget);
        prevBTN->setObjectName(QString::fromUtf8("prevBTN"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevBTN->setIcon(icon);

        horizontalLayout->addWidget(prevBTN);

        nextBTN = new QToolButton(centralWidget);
        nextBTN->setObjectName(QString::fromUtf8("nextBTN"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextBTN->setIcon(icon1);

        horizontalLayout->addWidget(nextBTN);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label_5->setFont(font);

        horizontalLayout_8->addWidget(label_5);

        blackBTN = new QToolButton(centralWidget);
        blackBTN->setObjectName(QString::fromUtf8("blackBTN"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Icons/Black.png"), QSize(), QIcon::Normal, QIcon::Off);
        blackBTN->setIcon(icon2);
        blackBTN->setCheckable(true);
        blackBTN->setChecked(false);

        horizontalLayout_8->addWidget(blackBTN);

        whiteBTN = new QToolButton(centralWidget);
        whiteBTN->setObjectName(QString::fromUtf8("whiteBTN"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Icons/White.png"), QSize(), QIcon::Normal, QIcon::Off);
        whiteBTN->setIcon(icon3);
        whiteBTN->setCheckable(true);

        horizontalLayout_8->addWidget(whiteBTN);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_8->addWidget(label_4);

        satSpinBox = new QDoubleSpinBox(centralWidget);
        satSpinBox->setObjectName(QString::fromUtf8("satSpinBox"));
        satSpinBox->setDecimals(2);
        satSpinBox->setMaximum(1);
        satSpinBox->setSingleStep(0.1);
        satSpinBox->setValue(0.8);

        horizontalLayout_8->addWidget(satSpinBox);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        reprocBTN = new QPushButton(centralWidget);
        reprocBTN->setObjectName(QString::fromUtf8("reprocBTN"));

        horizontalLayout_8->addWidget(reprocBTN);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        saveLayoutBTN = new QToolButton(centralWidget);
        saveLayoutBTN->setObjectName(QString::fromUtf8("saveLayoutBTN"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/Icons/button_accept.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveLayoutBTN->setIcon(icon4);
        saveLayoutBTN->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_8->addWidget(saveLayoutBTN);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_8);

        proglabel = new QLabel(centralWidget);
        proglabel->setObjectName(QString::fromUtf8("proglabel"));

        verticalLayout->addWidget(proglabel);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 346));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 96, 35));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_5->addWidget(scrollArea_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_7 = new QHBoxLayout(tab_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        scrollArea_3 = new QScrollArea(tab_3);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 96, 35));
        horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(scrollAreaWidgetContents_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_7->addWidget(scrollArea_3);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 753, 28));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help!", 0, QApplication::UnicodeUTF8));
        openfileBTN->setText(QApplication::translate("MainWindow", "Select image:", 0, QApplication::UnicodeUTF8));
        prevBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        nextBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Improve detection:", 0, QApplication::UnicodeUTF8));
        blackBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        whiteBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Square strictness:", 0, QApplication::UnicodeUTF8));
        reprocBTN->setText(QApplication::translate("MainWindow", "Re-process", 0, QApplication::UnicodeUTF8));
        saveLayoutBTN->setText(QApplication::translate("MainWindow", "Save layout", 0, QApplication::UnicodeUTF8));
        proglabel->setText(QString());
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Blocks", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Pixeles", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Original", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
