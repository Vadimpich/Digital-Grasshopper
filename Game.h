#ifndef DIGITAL_GRASSHOPPER_GAME_H
#define DIGITAL_GRASSHOPPER_GAME_H

#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include "Game.h"

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
        bool dest = false;

    public:
        std::vector<Point> moves;

        explicit Cell(CellState state = FREE, int number = 0) {
            this->state = state;
            this->number = number;
        }

        void setMoves(const std::vector<Point>& m) {
            this->moves = m;
        }

        void setState(CellState s) {
            this->state = s;
        }

        CellState getState() {
            return state;
        }

        bool isFree() {
            return (state == FREE);
        }

        void setNumber(int n) {
            this->number = n;
        }

        int getNumber() const {
            return number;
        }

        void setDest(bool d) {
            this->dest = d;
        }

        bool isDest() const {
            return dest;
        }

        Cell clone();
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
    Cell **field{};
    Cell **prevField{};
    Point selectedCell{-1, -1};
    Cell nullCell = Cell();


    int getRowCount() {
        return 6;
    }

    int getColCount() {
        return 6;
    }

    std::vector<Point> getMoves(int row, int col);

    void updateMoves(int rowCount, int colCount);

    void calcState();

    static std::vector<int> genNumbers(int rowCount, int colCount, int diff);

    void newGame(int rowCount, int colCount, int diff);

    void restartGame(int rowCount, int colCount);

    void leftMouseClick(int row, int col);

    GameState getState() const {
        return state;
    }

};


#endif //DIGITAL_GRASSHOPPER_GAME_H
