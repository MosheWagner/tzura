/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 9 22:08:43 2011
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
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *proglabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QToolButton *whiteBTN;
    QToolButton *blackBTN;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QToolButton *plusBTN;
    QToolButton *minusBTN;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(799, 622);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        openfileBTN = new QPushButton(centralWidget);
        openfileBTN->setObjectName(QString::fromUtf8("openfileBTN"));
        QFont font;
        font.setPointSize(9);
        openfileBTN->setFont(font);

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
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        satSpinBox = new QDoubleSpinBox(centralWidget);
        satSpinBox->setObjectName(QString::fromUtf8("satSpinBox"));
        satSpinBox->setFont(font);
        satSpinBox->setDecimals(2);
        satSpinBox->setMaximum(1);
        satSpinBox->setSingleStep(0.02);
        satSpinBox->setValue(0.8);

        horizontalLayout->addWidget(satSpinBox);

        reprocBTN = new QPushButton(centralWidget);
        reprocBTN->setObjectName(QString::fromUtf8("reprocBTN"));
        reprocBTN->setFont(font);

        horizontalLayout->addWidget(reprocBTN);

        saveLayoutBTN = new QToolButton(centralWidget);
        saveLayoutBTN->setObjectName(QString::fromUtf8("saveLayoutBTN"));
        saveLayoutBTN->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Icons/button_accept.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveLayoutBTN->setIcon(icon2);
        saveLayoutBTN->setIconSize(QSize(40, 16));
        saveLayoutBTN->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(saveLayoutBTN);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 791, 560));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        proglabel = new QLabel(tab_2);
        proglabel->setObjectName(QString::fromUtf8("proglabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        proglabel->setFont(font1);

        verticalLayout_2->addWidget(proglabel);

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

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font3;
        font3.setPointSize(8);
        font3.setItalic(true);
        label_6->setFont(font3);

        horizontalLayout_5->addWidget(label_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        plusBTN = new QToolButton(tab_2);
        plusBTN->setObjectName(QString::fromUtf8("plusBTN"));
        plusBTN->setMaximumSize(QSize(14, 14));
        plusBTN->setIconSize(QSize(8, 8));

        verticalLayout_3->addWidget(plusBTN);

        minusBTN = new QToolButton(tab_2);
        minusBTN->setObjectName(QString::fromUtf8("minusBTN"));
        minusBTN->setMaximumSize(QSize(14, 14));

        verticalLayout_3->addWidget(minusBTN);


        horizontalLayout_5->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 787, 479));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

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
        saveLayoutBTN->setText(QApplication::translate("MainWindow", "Save layout and next", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QString());
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Blocks", 0, QApplication::UnicodeUTF8));
        proglabel->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Perfect detection:", 0, QApplication::UnicodeUTF8));
        whiteBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        blackBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Brush size:", 0, QApplication::UnicodeUTF8));
        plusBTN->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        minusBTN->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Pixeles", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
