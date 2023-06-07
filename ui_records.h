/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE

class Ui_Records
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(516, 618);
        QFontDatabase fontDatabase;
        int id = fontDatabase.addApplicationFont(":/golos-ui_regular.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont font(family);
        font.setPointSize(12);
        Dialog->setFont(font);
        Dialog->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(195, 255, 195, 255), stop:1 rgba(246, 255, 246, 255));"));
        gridFrame = new QFrame(Dialog);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(5, 10, 502, 600));
        gridFrame->setFont(font);
        gridFrame->setFrameShape(QFrame::Panel);
        gridFrame->setFrameShadow(QFrame::Sunken);
        gridFrame->setLineWidth(2);
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(gridFrame);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFont(font);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setDefaultSectionSize(154);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox_2 = new QComboBox(gridFrame);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font);

        gridLayout_2->addWidget(comboBox_2, 0, 2, 1, 1);

        comboBox = new QComboBox(gridFrame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        label = new QLabel(gridFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Рекорды", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Dialog", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Dialog", "\320\233\321\221\320\263\320\272\320\260\321\217", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Dialog", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("Dialog", "\320\241\320\273\320\276\320\266\320\275\320\260\321\217", nullptr));

        comboBox->setItemText(0, QApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\273\321\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "\320\234\320\260\320\273\320\265\320\275\321\214\320\272\320\270\320\271", nullptr));
        comboBox->setItemText(2, QApplication::translate("Dialog", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        comboBox->setItemText(3, QApplication::translate("Dialog", "\320\221\320\276\320\273\321\214\321\210\320\276\320\271", nullptr));

        label->setText(QApplication::translate("Dialog", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Records: public Ui_Records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
