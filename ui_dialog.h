/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QFrame *verticalFrame_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(500, 270);
        Dialog->setStyleSheet(QString::fromUtf8(
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(195, 255, 195, 255), stop:1 rgba(246, 255, 246, 255));"));
        QFontDatabase fontDatabase;
        int id = fontDatabase.addApplicationFont(":/golos-ui_regular.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont font(family);
        font.setPointSize(12);
        Dialog->setFont(font);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 230, 471, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setStyleSheet(QString::fromUtf8(
                "background-color: rgba(196, 255, 196, 255);"
                ));
        gridFrame = new QFrame(Dialog);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(5, 10, 490, 211));
        gridFrame->setFrameShape(QFrame::Panel);
        gridFrame->setFrameShadow(QFrame::Sunken);
        gridFrame->setLineWidth(2);
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(gridFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString::fromUtf8(
                "background-color: rgba(196, 255, 196, 255)"
                ));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(gridFrame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Golos UI"));
        font1.setPointSize(10);
        comboBox->setFont(font1);

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(gridFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(
                "background-color: rgba(196, 255, 196, 255)"
        ));

        horizontalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(gridFrame);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font1);

        horizontalLayout->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalFrame_2 = new QFrame(gridFrame);
        verticalFrame_2->setObjectName(QString::fromUtf8("verticalFrame_2"));
        verticalFrame_2->setMaximumSize(QSize(260, 16777215));
        verticalLayout_2 = new QVBoxLayout(verticalFrame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 0, -1, 0);
        verticalFrame_2->setStyleSheet(QString::fromUtf8(
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(219, 255, 219, 255), stop:1 rgba(246, 255, 246, 255));"));
        frame = new QFrame(verticalFrame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 40));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        verticalLayout_2->addWidget(frame);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBox = new QCheckBox(verticalFrame_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);
        checkBox->setLayoutDirection(Qt::LeftToRight);
        checkBox->setAutoFillBackground(true);
        checkBox->setChecked(true);

        verticalLayout_4->addWidget(checkBox);

        horizontalSlider = new QSlider(verticalFrame_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::NoTicks);

        verticalLayout_4->addWidget(horizontalSlider);


        verticalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addWidget(verticalFrame_2, 0, 1, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label->setText(QApplication::translate("Dialog", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog", "\320\233\320\265\320\263\320\272\320\260\321\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        comboBox->setItemText(2, QApplication::translate("Dialog", "\320\241\320\273\320\276\320\266\320\275\320\260\321\217", nullptr));

        label_2->setText(QApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\273\321\217", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Dialog", "\320\234\320\260\320\273\320\265\320\275\321\214\320\272\320\270\320\271", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Dialog", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Dialog", "\320\221\320\276\320\273\321\214\321\210\320\276\320\271", nullptr));

        label_3->setText(QApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\273\320\265\321\202\320\272\320\270", nullptr));
        checkBox->setText(QApplication::translate("Dialog", "\320\220\320\262\321\202\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
