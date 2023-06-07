#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>

namespace Ui {
    class Records;
}

class Records : public QDialog {
Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);

    ~Records() override;

    static void newRecord(int s, int d, int t);

private:
    Ui::Records *ui;

    void updateDb(int s = 0, int d = 0);

    void newQuery();

    void initDB();
};

#endif // RECORDS_H
