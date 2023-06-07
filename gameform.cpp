#include "gameform.h"
#include "./ui_gameform.h"
#include "dialog.cpp"
#include "records.cpp"
#include "Game.cpp"

#include <vector>
#include <random>
#include <ctime>
#include <QDebug>
#include <QHeaderView>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QMessageBox>

class CustomDelegate : public QStyledItemDelegate {
public:
    explicit CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QColor cellColor = index.data(Qt::BackgroundColorRole).value<QColor>();

        painter->save();
        if (option.state & QStyle::State_Selected) {
            if (cellColor.isValid()) {
                QColor darkerColor = cellColor.darker(110);
                painter->fillRect(option.rect, darkerColor);
            }
        } else {
            painter->fillRect(option.rect, option.backgroundBrush);
        }
        painter->restore();

        QStyledItemDelegate::paint(painter, option, index);
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option,
                     const QModelIndex &index) override {
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }
};

const QRgb COLORS[] = {
        Qt::transparent,
        qRgb(255, 200, 0),
        qRgb(255, 175, 175),
        qRgb(0, 255, 0),
        qRgb(0, 255, 255),
};

void GameForm::updateTable() {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
            auto *item = new QTableWidgetItem();

            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            item->setFont(bnb);

            Game::Cell cell = game.field[row][column];

            QColor backColor;
            if (cell.getState() == Game::MOVABLE) {
                backColor = COLORS[cell.getNumber()];
            } else if (cell.getState() == Game::MOVED) {
                backColor = qRgb(192, 192, 192);
            } else {
                backColor = qRgb(255, 255, 255);
            }

            char ch = ' ';
            QColor color;
            if (cell.getState() == Game::MOVABLE) {
                ch = char('0' + cell.getNumber());
                color = qRgb(64, 64, 64);
            } else if (cell.getState() == Game::MOVED) {
                ch = char('0' + cell.getNumber());
                color = qRgb(255, 255, 255);
            } else if (cell.isDest()) {
                ch = 'X';
                color = qRgb(128, 128, 128);
            }

            item->setText(QString(ch));
            if (!cell.isFree()) {
                item->setBackgroundColor(backColor);
            }
            item->setTextColor(color);

            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row, column, item);
        }
    }
    switch (game.getState()) {
        case Game::PLAYING:
            ui->label->setText("Игра идёт");
            break;
        case Game::WIN:
            ui->label->setText("Победа :)");
            Records::newRecord(
                    params.rowCount / 2 - 2,
                    params.diff,
                    ui->lcdNumber->intValue()
            );
            break;
        case Game::FAIL:
            ui->label->setText("Поражение :(");
            break;
        default:
            break;
    }
}

GameForm::GameForm(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::GameForm) {
    ui->setupUi(this);

    srand(time(nullptr));

    game = Game();
    game.newGame(
            params.rowCount,
            params.colCount,
            params.diff
    );

    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        if (game.getState() == Game::PLAYING) {
            ui->lcdNumber->display(ui->lcdNumber->intValue() + 1);
        }
    });

    timer.start();

    adjustCellSize();
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setItemDelegate(new CustomDelegate);

    int id = QFontDatabase::addApplicationFont(":/bnb.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    bnb = QFont(family);
    bnb.setPointSize(36);

    updateTable();

    connect(
            ui->tableWidget,
            SIGNAL(cellClicked(int, int)),
            this,
            SLOT(handleCellClicked(int, int))
    );
    connect(
            ui->pushButton,
            &QPushButton::clicked,
            this,
            &GameForm::onNewGameClicked
    );
    connect(
            ui->pushButton_2,
            &QPushButton::clicked,
            this,
            &GameForm::onRestartClicked
    );
    connect(
            ui->action,
            &QAction::triggered,
            this,
            &GameForm::onNewGameClicked
    );
    connect(
            ui->action_2,
            &QAction::triggered,
            this,
            &GameForm::onParamsClicked
    );
    connect(
            ui->action_3,
            &QAction::triggered,
            this,
            &GameForm::onRecordsClicked
    );
    connect(ui->action_4, &QAction::triggered, [&]() {
        QCoreApplication::quit();
    });
    connect(
            ui->action_5,
            &QAction::triggered,
            this,
            &GameForm::onRulesClicked
    );
    connect(
            ui->action_6,
            &QAction::triggered,
            this,
            &GameForm::onInfoClicked
    );
}

GameForm::~GameForm() {
    delete ui;
}

void GameForm::handleCellClicked(int row, int column) {
    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    if (item && game.getState() == Game::PLAYING) {
        game.leftMouseClick(row, column);
        ui->lcdNumber_2->display(game.points);
        updateTable();
    }
}

void GameForm::onNewGameClicked() {
    game.newGame(
            params.rowCount,
            params.colCount,
            params.diff
    );
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    updateTable();
}

void GameForm::onRestartClicked() {
    game.restartGame();
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    updateTable();
}


void GameForm::onParamsClicked() {
    timer.stop();
    dialog.setupParams();
    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.diff != params.diff
            || dialog.size != params.rowCount
            || dialog.cellSize != params.cellSize) {
            updateParams();
            if (params.autoSize) {
                adjustCellSize();
            } else {
                customCellSize();
            }
            dialog.params = params;
            onNewGameClicked();
        }
    }
    timer.start();
}

void GameForm::updateParams() {
    params.diff = dialog.diff;
    params.colCount = dialog.size;
    params.rowCount = dialog.size;
    params.autoSize = dialog.autoSize;
    params.cellSize = dialog.cellSize;
}

void GameForm::adjustCellSize() {
    ui->tableWidget->setRowCount(params.rowCount);
    ui->tableWidget->setColumnCount(params.colCount);
    for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
        ui->tableWidget->setColumnWidth(column, 558 / params.rowCount - 1);
    }
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        ui->tableWidget->setRowHeight(row, 558 / params.colCount - 1);
    }
}

void GameForm::customCellSize() {
    ui->tableWidget->setRowCount(params.rowCount);
    ui->tableWidget->setColumnCount(params.colCount);
    for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
        ui->tableWidget->setColumnWidth(column, int((558.0 / params.rowCount - 1) * params.cellSize));
    }
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        ui->tableWidget->setRowHeight(row, int((558.0 / params.colCount - 1) * params.cellSize));
    }
}

void GameForm::onRecordsClicked() {
    Records records;
    records.exec();
}

void GameForm::onRulesClicked() {
    QMessageBox messageBox;
    messageBox.setText(
            "Для победы вам необходимо сделать по одному ходу каждой фишкой.\n"
            "Длина шага - число на фишке."
    );
    messageBox.setWindowTitle("Правила");
    messageBox.setIcon(QMessageBox::Information);
    messageBox.addButton(QMessageBox::Ok);
    messageBox.exec();
}

void GameForm::onInfoClicked() {
    QMessageBox messageBox;
    messageBox.setText(
            "Игра \"Цифровой Кузнечик\" разработана командой GAMEDEVstvenniki\n"
            " - Пичурин Вадим\n"
            " - Прудников Андрей\n"
            " - Григоров Илья\n"
            "ПКШ, РТ5-21Б, 2023."
    );
    messageBox.setWindowTitle("О программе");
    messageBox.setIcon(QMessageBox::Information);
    messageBox.addButton(QMessageBox::Ok);
    messageBox.exec();
}



