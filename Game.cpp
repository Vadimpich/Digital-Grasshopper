#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include "Game.h"

using namespace std;


class Game {
public:
    enum GameState {
        MENU,
        PLAYING,
        WIN,
        FAIL
    };
    enum CellState {
        FREE,
        MOVABLE,
        MOVED
    };

    class Point {
    public:
        int row;
        int col;

        Point(int row, int col) {
            this->row = row;
            this->col = col;
        }
    };


    class Cell {
    private:
        CellState state;
        int number;
        bool dest;
        bool selected;

    public:
        vector<Point> moves;

        explicit Cell(CellState state = FREE, int number = 0) {
            this->state = state;
            this->number = number;
        }

        void setMoves(vector<Point> moves) {
            this->moves = std::move(moves);
        }

        void setState(CellState state) {
            this->state = state;
        }

        CellState getState() {
            return state;
        }

        bool isFree() {
            return (state == FREE);
        }

        void setNumber(int number) {
            this->number = number;
        }

        int getNumber() {
            return number;
        }

        void setDest(bool dest) {
            this->dest = dest;
        }

        bool isDest() {
            return dest;
        }

        void setSelected(bool selected) {
            this->selected = selected;
        }

        bool isSelected() {
            return selected;
        }

        Cell clone() {
            Cell cell = Cell(this->state, this->number);
            cell.moves = vector<Point>(this->moves);
            return cell;
        }
    };

    class Number {
    public:
        int value;
        double freq;

        Number(int value, double freq) {
            this->value = value;
            this->freq = freq;
        }
    };

    GameState state = MENU;
    int points = 0;
    Cell **field;
    Cell **prevField;
    Cell selectedCell;
    Cell nullCell = Cell();


    int getRowCount() {
        return (field == nullptr) ? 0 : sizeof(field) / sizeof(field[0]);
    }

    int getColCount() {
        return (field == nullptr) ? 0 : sizeof(field[0]) / sizeof(Cell);
    }


    vector<Point> getMoves(int row, int col) {
        int rowCount = getRowCount();
        int colCount = getColCount();
        vector<Point> moves = vector<Point>();
        int step = field[row][col].getNumber();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int rShift = i * step;
                int cShift = j * step;
                if (
                        row + rShift >= 0 && row + rShift < rowCount
                        && col + cShift >= 0 && col + cShift < colCount
                        && field[row + rShift][col + cShift].isFree()
                        ) {
                    moves.emplace_back(row + rShift, col + cShift);
                }
            }
        }
        return moves;
    }

    void updateMoves(int rowCount, int colCount) {
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                field[r][c].setMoves(getMoves(r, c));
            }
        }
    }


    void calcState() {
        int rowCount = getRowCount();
        int colCount = getColCount();
        GameState curState;
        bool noMoves = true, allMoved = true;
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                Cell cell = field[r][c];
                if (cell.getState() == MOVABLE) {
                    allMoved = false;
                    if (getMoves(r, c).size() > 0) {
                        noMoves = false;
                    }
                }
            }
        }
        if (allMoved) {
            state = WIN;
        } else if (noMoves) {
            state = FAIL;
        } else {
            state = PLAYING;
        }
    }


    vector<int> genNumbers(int rowCount, int colCount, int diff) {
        vector<int> cells = vector<int>();
        vector<Number> numbers = vector<Number>();
        int count = rowCount * colCount;
        switch (diff) {
            case 1:
                numbers.emplace_back(2, 0.40);
                numbers.emplace_back(3, 0.14);
                numbers.emplace_back(4, 0.03);
                break;
            case 2:
                numbers.emplace_back(2, 0.22);
                numbers.emplace_back(1, 0.16);
                numbers.emplace_back(3, 0.28);
                numbers.emplace_back(4, 0.06);
                break;
            case 3:
                numbers.emplace_back(2, 0.33);
                numbers.emplace_back(1, 0.42);
                numbers.emplace_back(3, 0.05);
                numbers.emplace_back(4, 0.08);
                break;
            default:
                break;
        }
        for (Number num: numbers) {
            for (int i = 0; i < (int) (num.freq * count); i++) {
                cells.push_back(num.value);
            }
        }
        int zeros = count - cells.size();
        for (int i = 0; i < zeros; i++) {
            cells.push_back(0);
        }
        return cells;
    }

    void newGame(int rowCount, int colCount, int diff) {
        srand(std::time(nullptr));
        field = new Cell *[rowCount];
        for (int i = 0; i < rowCount; i++) {
            field[i] = new Cell[colCount];
        }
        vector<int> cells = genNumbers(rowCount, colCount, diff);
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                int curValueInd = rand() % cells.size();
                CellState curState = (cells[curValueInd] == 0)
                                     ? FREE
                                     : MOVABLE;
                field[r][c] = Cell(curState, cells[curValueInd]);
                auto it = cells.begin();
                for (int i = 0; i < curValueInd; i++) {
                    it++;
                }
                cells.erase(it);
            }
        }

        updateMoves(rowCount, colCount);
        int points = 0;
        prevField = new Cell *[rowCount];
        for (int i = 0; i < rowCount; i++) {
            prevField[i] = new Cell[colCount];
        }
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                prevField[r][c] = field[r][c].clone();
                prevField[r][c].setSelected(false);
            }
        }
        state = PLAYING;
    }

    void restartGame(int rowCount, int colCount) {
        field = new Cell *[rowCount];
        for (int i = 0; i < rowCount; i++) {
            field[i] = new Cell[colCount];
        }
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                field[r][c] = prevField[r][c].clone();
                field[r][c].setDest(false);
                field[r][c].setSelected(false);
            }
        }

        updateMoves(rowCount, colCount);
        int points = 0;
        state = PLAYING;
    }

    void leftMouseClick(int row, int col) {
        int rowCount = getRowCount(), colCount = getColCount();
        if (row < 0 || row >= rowCount || col < 0 || col >= colCount) {
            return;
        }
        if (field[row][col].isDest()) {
            field[row][col] = selectedCell.clone();
            field[row][col].setState(MOVED);
            selectedCell.setState(FREE);
            selectedCell.setNumber(0);
            points++;
        }
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                field[r][c].setDest(false);
                field[r][c].setSelected(false);
            }
        }
        if (field[row][col].getState() == MOVABLE) {
            selectedCell = field[row][col];
            field[row][col].setSelected(true);
            for (Point p: field[row][col].moves) {
                field[p.row][p.col].setDest(true);
            }
        }
        updateMoves(rowCount, colCount);
        calcState();
    }

    Cell getCell(int row, int col) {
        int rowCount = getRowCount(), colCount = getColCount();
        if (row < 0 || row >= rowCount || col < 0 || col >= colCount) {
            return nullCell;
        }
        return field[row][col];
    }

    GameState getState() {
        return state;
    }

};
