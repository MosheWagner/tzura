/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri May 13 13:42:34 2011
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
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
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QDoubleSpinBox *satSpinBox;
    QPushButton *reprocBTN;
    QToolButton *saveLayoutBTN;
    QToolButton *toolButton;
    QLabel *proglabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QToolButton *whiteBTN;
    QToolButton *blackBTN;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(721, 622);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 0);
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

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        satSpinBox = new QDoubleSpinBox(centralWidget);
        satSpinBox->setObjectName(QString::fromUtf8("satSpinBox"));
        satSpinBox->setDecimals(2);
        satSpinBox->setMaximum(1);
        satSpinBox->setSingleStep(0.1);
        satSpinBox->setValue(0.8);

        horizontalLayout->addWidget(satSpinBox);

        reprocBTN = new QPushButton(centralWidget);
        reprocBTN->setObjectName(QString::fromUtf8("reprocBTN"));

        horizontalLayout->addWidget(reprocBTN);

        saveLayoutBTN = new QToolButton(centralWidget);
        saveLayoutBTN->setObjectName(QString::fromUtf8("saveLayoutBTN"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Icons/button_accept.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveLayoutBTN->setIcon(icon2);
        saveLayoutBTN->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(saveLayoutBTN);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        proglabel = new QLabel(centralWidget);
        proglabel->setObjectName(QString::fromUtf8("proglabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        proglabel->setFont(font);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 693, 468));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setPointSize(7);
        groupBox->setFont(font1);
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(groupBox_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);


        horizontalLayout_2->addWidget(groupBox_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 12, -1, -1);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        label_5->setFont(font2);

        horizontalLayout_5->addWidget(label_5);

        whiteBTN = new QToolButton(tab_2);
        whiteBTN->setObjectName(QString::fromUtf8("whiteBTN"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/Icons/White.png"), QSize(), QIcon::Normal, QIcon::Off);
        whiteBTN->setIcon(icon4);
        whiteBTN->setCheckable(true);

        horizontalLayout_5->addWidget(whiteBTN);

        blackBTN = new QToolButton(tab_2);
        blackBTN->setObjectName(QString::fromUtf8("blackBTN"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/Icons/Black.png"), QSize(), QIcon::Normal, QIcon::Off);
        blackBTN->setIcon(icon5);
        blackBTN->setCheckable(true);
        blackBTN->setChecked(false);

        horizontalLayout_5->addWidget(blackBTN);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 693, 424));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

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
        label_4->setText(QApplication::translate("MainWindow", "Square strictness:", 0, QApplication::UnicodeUTF8));
        reprocBTN->setText(QApplication::translate("MainWindow", "Re-process", 0, QApplication::UnicodeUTF8));
        saveLayoutBTN->setText(QApplication::translate("MainWindow", "Save layout", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QString());
        proglabel->setText(QApplication::translate("MainWindow", "proglbl", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Original page:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Detected blocks:", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Blocks", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Perfect detection:", 0, QApplication::UnicodeUTF8));
        whiteBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        blackBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Pixeles", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
