#include "dialog.h"
#include "ui_dialog.h"

const int DIFFS[] = {
        1,
        2,
        3,
};

const int SIZES[] = {
        6,
        8,
        10,
};



Dialog::Dialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setupParams();

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index){
        diff = DIFFS[index];
    });

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index){
        size = SIZES[index];
    });

    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            autoSize = true;
            ui->horizontalSlider->setValue(50);
            ui->horizontalSlider->setDisabled(true);
        } else {
            autoSize = false;
            ui->horizontalSlider->setDisabled(false);
        }
    });

    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](double value){
        cellSize = value / 100 * 2;
    });
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setupParams() {
    autoSize = params.autoSize;
    ui->checkBox->setCheckState((autoSize) ? Qt::Checked : Qt::Unchecked);
    cellSize = params.cellSize;
    ui->horizontalSlider->setValue(int(cellSize * 100 / 2));
    ui->horizontalSlider->setDisabled(ui->checkBox->checkState() == Qt::Checked);
    diff = params.diff;
    ui->comboBox->setCurrentIndex(diff - 1);
    size = params.rowCount;
    ui->comboBox->setCurrentIndex(size / 2 - 3);
}
