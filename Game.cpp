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

};
