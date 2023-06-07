#include "records.h"
#include "ui_records.h"

#include <QtSql>
#include <QDebug>

const QString DIFF_NAMES[] = {
        "Лёгкая",
        "Средняя",
        "Сложная",
};

const QString SIZE_NAMES[] = {
        "Маленький",
        "Средний",
        "Большой",
};

Records::Records(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Records)
{
    ui->setupUi(this);

    newQuery();

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](){
        newQuery();
    });

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](){
        newQuery();
    });
}



Records::~Records()
{
    delete ui;
}

void Records::updateDb(int s, int d) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite3");
    if (!db.open()) {
        qDebug() << "Open db error";
    }

    QSqlQuery query;
    QString q = "SELECT * FROM Records";
    if (s) {
        q += " WHERE size = " + QString::fromStdString(std::to_string(s));
    }
    if (d) {
        if (s) {
            q += " AND ";
        } else {
            q += " WHERE ";
        }
        q += " diff = " + QString::fromStdString(std::to_string(d));
    }
    if (!query.exec(q)) {
        qDebug() << "Select error";
    }
    QSqlRecord rec = query.record();

    int size, diff, time;

    ui->tableWidget->setRowCount(0);
    while (query.next()) {
        size = query.value(rec.indexOf("size")).toInt();
        diff = query.value(rec.indexOf("diff")).toInt();
        time = query.value(rec.indexOf("time")).toInt();

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        auto *item = new QTableWidgetItem();
        item->setText(SIZE_NAMES[size-1]);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
        item = new QTableWidgetItem();
        item->setText(DIFF_NAMES[diff-1]);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromStdString(std::to_string(time)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, item);
    }
}

void Records::newQuery() {
    int s = ui->comboBox->currentIndex();
    int d = ui->comboBox_2->currentIndex();
    updateDb(s, d);
}

void Records::newRecord(int s, int d, int t) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite3");
    if (!db.open()) {
        qDebug() << "Open db error";
    }

    QSqlQuery query;
    QString q_template = "INSERT INTO Records(size, diff, time) "
                         "VALUES (%1, '%2', %3);";
    QString q = q_template.arg(s).arg(d).arg(t);

    if (!query.exec(q)) {
        qDebug() << "Insert error";
    }
}
