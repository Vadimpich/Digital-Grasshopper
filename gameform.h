#ifndef GAMEFORM_H
#define GAMEFORM_H

#include <QMainWindow>
#include <QTimer>
#include "Game.h"
#include "GameParams.h"
#include "dialog.h"
#include "records.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameForm; }
QT_END_NAMESPACE

class GameForm : public QMainWindow {
Q_OBJECT

public:
    explicit GameForm(QWidget *parent = nullptr);

    ~GameForm() override;

    void updateTable();

    void updateParams();

    void adjustCellSize();

    void customCellSize();

private slots:

    void handleCellClicked(int row, int column);

    void onNewGameClicked();

    void onParamsClicked();

    void onRestartClicked();

    static void onRecordsClicked();

    static void onRulesClicked();

    static void onInfoClicked();


private:
    Ui::GameForm *ui;
    Game game;
    GameParams params;
    QTimer timer;
    Dialog dialog;
    QFont bnb;
};

#endif // GAMEFORM_H
