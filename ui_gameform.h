/********************************************************************************
** Form generated from reading UI file 'gameform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFORM_H
#define UI_GAMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE

class Ui_GameForm
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_3;
    QWidget *centralwidget;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_2;
    QFrame *verticalFrame1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *lcdNumber_2;
    QSpacerItem *horizontalSpacer_4;
    QFrame *horizontalFrame1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *GameForm)
    {
        if (GameForm->objectName().isEmpty())
            GameForm->setObjectName(QString::fromUtf8("GameForm"));
        GameForm->resize(720, 800);
        GameForm->setMinimumSize(QSize(720, 800));
        GameForm->setMaximumSize(QSize(720, 800));
        GameForm->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(153, 255, 153, 255), stop:1 rgba(230, 255, 230, 255));"));
        action = new QAction(GameForm);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(GameForm);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_4 = new QAction(GameForm);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(GameForm);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(GameForm);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_3 = new QAction(GameForm);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(GameForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalFrame = new QFrame(centralwidget);
        verticalFrame->setObjectName(QString::fromUtf8("verticalFrame"));
        verticalFrame->setGeometry(QRect(0, 0, 720, 140));
        verticalFrame->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(195, 255, 195, 255), stop:1 rgba(223, 255, 223, 255));"));
        verticalFrame->setLineWidth(3);
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        horizontalFrame = new QFrame(verticalFrame);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setEnabled(true);
        horizontalFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalFrame->setFrameShape(QFrame::Panel);
        horizontalFrame->setFrameShadow(QFrame::Sunken);
        horizontalFrame->setLineWidth(2);
        horizontalFrame->setMidLineWidth(0);
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcdNumber = new QLCDNumber(horizontalFrame);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(100, 0));
        lcdNumber->setMaximumSize(QSize(100, 100));
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgba(153,255,153, 100);"));
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(2);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(3);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcdNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalFrame1 = new QFrame(horizontalFrame);
        verticalFrame1->setObjectName(QString::fromUtf8("verticalFrame1"));
        verticalFrame1->setMinimumSize(QSize(20, 0));
        verticalLayout_2 = new QVBoxLayout(verticalFrame1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        pushButton = new QPushButton(verticalFrame1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 36));
        QFontDatabase fontDatabase;
        int id = fontDatabase.addApplicationFont(":/bnr.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont font(family);
        font.setPointSize(24);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(153,255,153, 100);"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(verticalFrame1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 36));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgba(153,255,153, 100);"));

        verticalLayout_2->addWidget(pushButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(verticalFrame1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lcdNumber_2 = new QLCDNumber(horizontalFrame);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber_2->sizePolicy().hasHeightForWidth());
        lcdNumber_2->setSizePolicy(sizePolicy);
        lcdNumber_2->setMinimumSize(QSize(100, 0));
        lcdNumber_2->setMaximumSize(QSize(100, 100));
        lcdNumber_2->setStyleSheet(QString::fromUtf8("background-color: rgba(153,255,153, 100);"));
        lcdNumber_2->setFrameShape(QFrame::Panel);
        lcdNumber_2->setFrameShadow(QFrame::Sunken);
        lcdNumber_2->setLineWidth(2);
        lcdNumber_2->setSmallDecimalPoint(true);
        lcdNumber_2->setDigitCount(3);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcdNumber_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(horizontalFrame);

        horizontalFrame1 = new QFrame(centralwidget);
        horizontalFrame1->setObjectName(QString::fromUtf8("horizontalFrame1"));
        horizontalFrame1->setGeometry(QRect(10, 140, 700, 563));
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        tableWidget = new QTableWidget(horizontalFrame1);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(brush1);
        __qtablewidgetitem->setForeground(brush);
        __qtablewidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMinimumSize(QSize(558, 558));
        QPalette palette;
        QLinearGradient gradient(0, 1, 1, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(153, 255, 153, 255));
        gradient.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush2(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        QLinearGradient gradient1(0, 1, 1, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(153, 255, 153, 255));
        gradient1.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush4(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush4);
        QLinearGradient gradient2(0, 1, 1, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(153, 255, 153, 255));
        gradient2.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush5(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(0, 0, 0, 50));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush7);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        QLinearGradient gradient3(0, 1, 1, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(153, 255, 153, 255));
        gradient3.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush9(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QLinearGradient gradient4(0, 1, 1, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(153, 255, 153, 255));
        gradient4.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush10(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        QLinearGradient gradient5(0, 1, 1, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(153, 255, 153, 255));
        gradient5.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush11(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        QLinearGradient gradient6(0, 1, 1, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(153, 255, 153, 255));
        gradient6.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush12(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        QBrush brush13(QColor(164, 166, 168, 96));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        QLinearGradient gradient7(0, 1, 1, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(153, 255, 153, 255));
        gradient7.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush14(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        QLinearGradient gradient8(0, 1, 1, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(153, 255, 153, 255));
        gradient8.setColorAt(1, QColor(230, 255, 230, 255));
        QBrush brush15(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        QBrush brush16(QColor(29, 84, 92, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush7);
        QBrush brush17(QColor(208, 208, 208, 128));
        brush17.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush17);
#endif
        tableWidget->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bebas Neue Bold"));
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setFrameShape(QFrame::Panel);
        tableWidget->setLineWidth(3);
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setRowCount(6);
        tableWidget->setColumnCount(6);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(39);
        tableWidget->horizontalHeader()->setDefaultSectionSize(92);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setDefaultSectionSize(92);

        horizontalLayout_2->addWidget(tableWidget);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 710, 721, 61));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(158, 255, 158, 255), stop:1 rgba(195, 255, 195, 255));"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        GameForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 20));
        menubar->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(195, 255, 195, 255), stop:1 rgba(223, 255, 223, 255));"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        GameForm->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addSeparator();
        menu->addAction(action_4);
        menu_2->addAction(action_5);
        menu_2->addAction(action_6);

        retranslateUi(GameForm);

        QMetaObject::connectSlotsByName(GameForm);
    } // setupUi

    void retranslateUi(QMainWindow *GameForm)
    {
        GameForm->setWindowTitle(QApplication::translate("GameForm", "\320\246\320\270\321\204\321\200\320\276\320\262\320\276\320\271 \320\232\321\203\320\267\320\275\320\265\321\207\320\270\320\272", nullptr));
        action->setText(QApplication::translate("GameForm", "\320\235\320\276\320\262\320\260\321\217", nullptr));
        action_2->setText(QApplication::translate("GameForm", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        action_4->setText(QApplication::translate("GameForm", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_5->setText(QApplication::translate("GameForm", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        action_6->setText(QApplication::translate("GameForm", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        action_3->setText(QApplication::translate("GameForm", "\320\240\320\265\320\272\320\276\321\200\320\264\321\213", nullptr));
        pushButton->setText(QApplication::translate("GameForm", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        pushButton_2->setText(QApplication::translate("GameForm", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\227\320\260\320\275\320\276\320\262\320\276", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("GameForm", "\320\230\320\263\321\200\320\260 \320\230\320\264\321\221\321\202", nullptr));
        menu->setTitle(QApplication::translate("GameForm", "\320\230\320\263\321\200\320\260", nullptr));
        menu_2->setTitle(QApplication::translate("GameForm", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameForm: public Ui_GameForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFORM_H
