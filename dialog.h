#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "GameParams.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
Q_OBJECT

public:
    int diff = 1;
    int size = 6;
    double cellSize = 1;
    bool autoSize = true;
    GameParams params;

    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog();

    void setupParams();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
