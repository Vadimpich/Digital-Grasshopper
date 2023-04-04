#include <iostream>
#include "GameParams.h"

using namespace std;

class GameParams {

private:
    int rowCount;
    int colCount;
    int diff;

public:
    explicit GameParams(int rowCount = 6, int colCount = 6, int diff = 1) {
        this->rowCount = rowCount;
        this->colCount = colCount;
        this->diff = diff;
    }

    int getColCount() {
        return colCount;
    }

    void setColCount(int colCount) {
        this->colCount = colCount;
    }

    int getRowCount() {
        return rowCount;
    }

    void setRowCount(int rowCount) {
        this->rowCount = rowCount;
    }

    int getDiff() {
        return diff;
    }

    void setDiff(int diff) {
        this->diff = diff;
    }


};
