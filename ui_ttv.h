/********************************************************************************
** Form generated from reading UI file 'ttv.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTV_H
#define UI_TTV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ttv
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QGroupBox *preference_groupBox;
    QSpinBox *width_spinBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *height_spinBox;
    QLineEdit *num_serv_lineEdit;
    QLabel *label_4;
    QLineEdit *width_lineEdit;
    QLabel *label_5;
    QLineEdit *height_lineEdit;
    QLabel *label_6;
    QSpinBox *rows_wanted_spinBox;
    QLabel *label_7;
    QSpinBox *titleSpace_spinBox;
    QLabel *label_8;
    QLabel *label_3;
    QPushButton *ffplay_pushButton;
    QPushButton *setMPVs_pushButton;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ttv)
    {
        if (ttv->objectName().isEmpty())
            ttv->setObjectName(QStringLiteral("ttv"));
        ttv->resize(702, 310);
        centralWidget = new QWidget(ttv);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(310, 30, 381, 201));
        preference_groupBox = new QGroupBox(centralWidget);
        preference_groupBox->setObjectName(QStringLiteral("preference_groupBox"));
        preference_groupBox->setGeometry(QRect(10, 10, 271, 261));
        width_spinBox = new QSpinBox(preference_groupBox);
        width_spinBox->setObjectName(QStringLiteral("width_spinBox"));
        width_spinBox->setGeometry(QRect(0, 150, 61, 29));
        width_spinBox->setMinimum(60);
        width_spinBox->setMaximum(1024);
        width_spinBox->setSingleStep(10);
        width_spinBox->setValue(60);
        label = new QLabel(preference_groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 130, 61, 20));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(preference_groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 130, 62, 20));
        label_2->setAlignment(Qt::AlignCenter);
        height_spinBox = new QSpinBox(preference_groupBox);
        height_spinBox->setObjectName(QStringLiteral("height_spinBox"));
        height_spinBox->setGeometry(QRect(80, 150, 61, 29));
        height_spinBox->setMinimum(60);
        height_spinBox->setMaximum(720);
        height_spinBox->setSingleStep(10);
        height_spinBox->setValue(60);
        num_serv_lineEdit = new QLineEdit(preference_groupBox);
        num_serv_lineEdit->setObjectName(QStringLiteral("num_serv_lineEdit"));
        num_serv_lineEdit->setGeometry(QRect(0, 100, 131, 30));
        label_4 = new QLabel(preference_groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 80, 131, 20));
        width_lineEdit = new QLineEdit(preference_groupBox);
        width_lineEdit->setObjectName(QStringLiteral("width_lineEdit"));
        width_lineEdit->setGeometry(QRect(0, 40, 113, 30));
        label_5 = new QLabel(preference_groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 20, 111, 20));
        label_5->setLayoutDirection(Qt::LeftToRight);
        height_lineEdit = new QLineEdit(preference_groupBox);
        height_lineEdit->setObjectName(QStringLiteral("height_lineEdit"));
        height_lineEdit->setGeometry(QRect(130, 40, 113, 30));
        label_6 = new QLabel(preference_groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 20, 111, 20));
        rows_wanted_spinBox = new QSpinBox(preference_groupBox);
        rows_wanted_spinBox->setObjectName(QStringLiteral("rows_wanted_spinBox"));
        rows_wanted_spinBox->setGeometry(QRect(190, 150, 48, 30));
        rows_wanted_spinBox->setMinimum(1);
        rows_wanted_spinBox->setMaximum(9);
        rows_wanted_spinBox->setValue(1);
        label_7 = new QLabel(preference_groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 130, 91, 20));
        titleSpace_spinBox = new QSpinBox(preference_groupBox);
        titleSpace_spinBox->setObjectName(QStringLiteral("titleSpace_spinBox"));
        titleSpace_spinBox->setGeometry(QRect(0, 210, 71, 30));
        titleSpace_spinBox->setMinimum(30);
        titleSpace_spinBox->setMaximum(60);
        titleSpace_spinBox->setSingleStep(5);
        label_8 = new QLabel(preference_groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 190, 71, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 10, 121, 20));
        ffplay_pushButton = new QPushButton(centralWidget);
        ffplay_pushButton->setObjectName(QStringLiteral("ffplay_pushButton"));
        ffplay_pushButton->setGeometry(QRect(400, 240, 83, 28));
        setMPVs_pushButton = new QPushButton(centralWidget);
        setMPVs_pushButton->setObjectName(QStringLiteral("setMPVs_pushButton"));
        setMPVs_pushButton->setGeometry(QRect(310, 240, 83, 28));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 240, 83, 28));
        ttv->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ttv);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ttv->setStatusBar(statusBar);

        retranslateUi(ttv);

        QMetaObject::connectSlotsByName(ttv);
    } // setupUi

    void retranslateUi(QMainWindow *ttv)
    {
        ttv->setWindowTitle(QApplication::translate("ttv", "ttviewer", Q_NULLPTR));
        preference_groupBox->setTitle(QApplication::translate("ttv", "Frame Preferences", Q_NULLPTR));
        label->setText(QApplication::translate("ttv", "Width", Q_NULLPTR));
        label_2->setText(QApplication::translate("ttv", "Height", Q_NULLPTR));
        label_4->setText(QApplication::translate("ttv", "Number of Streams", Q_NULLPTR));
        label_5->setText(QApplication::translate("ttv", "Display Width", Q_NULLPTR));
        label_6->setText(QApplication::translate("ttv", "Display Height", Q_NULLPTR));
        label_7->setText(QApplication::translate("ttv", "Rows Wanted", Q_NULLPTR));
        label_8->setText(QApplication::translate("ttv", "Title Space", Q_NULLPTR));
        label_3->setText(QApplication::translate("ttv", "Streams Available", Q_NULLPTR));
        ffplay_pushButton->setText(QApplication::translate("ttv", "FFplay", Q_NULLPTR));
        setMPVs_pushButton->setText(QApplication::translate("ttv", "MPV", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ttv", "LUF_mon", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ttv: public Ui_ttv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTV_H
