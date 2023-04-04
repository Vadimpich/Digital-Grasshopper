#include <iostream>
#include "GameParams.h"
using namespace std;

class GameParams{

private:
    int rowCount;
    int colCount;
    int diff;

public:
    GameParams(int rowCount, int colCount, int diff) {                                                         ?
        this->rowCount = rowCount;
        this->colCount = colCount;
        this->diff = diff;
    }

    GameParams() {
        this->rowCount = 6;
        this->colCount = 6;
        this->diff = 1;
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
