#include "Game.h"

std::vector<Game::Point> Game::getMoves(int row, int col) const {
    std::vector<Point> moves = std::vector<Point>();
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

void Game::updateMoves() const {
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            field[r][c].setMoves(getMoves(r, c));
        }
    }
}

void Game::calcState() {
    bool noMoves = true, allMoved = true;
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            Cell cell = field[r][c];
            if (cell.getState() == MOVABLE) {
                allMoved = false;
                if (!getMoves(r, c).empty()) {
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


std::vector<int> Game::genNumbers(int diff) const {
    std::vector<int> cells = std::vector<int>();
    std::vector<Number> numbers = std::vector<Number>();
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
    size_t zeros = count - cells.size();
    for (int i = 0; i < zeros; i++) {
        cells.push_back(0);
    }
    return cells;
}

void Game::newGame(int rCount, int cCount, int diff) {
    this->rowCount = rCount;
    this->colCount = cCount;
    points = 0;
    srand(std::time(nullptr));
    field = new Cell *[rCount];
    for (int i = 0; i < rCount; i++) {
        field[i] = new Cell[cCount];
    }
    std::vector<int> cells = genNumbers(diff);
    for (int r = 0; r < rCount; r++) {
        for (int c = 0; c < cCount; c++) {
            size_t curValueInd = rand() % cells.size();
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

    updateMoves();
    prevField = new Cell *[rCount];
    for (int i = 0; i < rCount; i++) {
        prevField[i] = new Cell[cCount];
    }
    for (int r = 0; r < rCount; r++) {
        for (int c = 0; c < cCount; c++) {
            prevField[r][c] = field[r][c].clone();
        }
    }
    state = PLAYING;
}

void Game::restartGame() {
    points = 0;
    field = new Cell *[rowCount];
    for (int i = 0; i < rowCount; i++) {
        field[i] = new Cell[colCount];
    }
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            field[r][c] = prevField[r][c].clone();
            field[r][c].setDest(false);
        }
    }

    updateMoves();
    state = PLAYING;
}

void Game::leftMouseClick(int row, int col) {
    if (field[row][col].isDest()) {
        field[row][col] = field[selectedCell.row][selectedCell.col].clone();
        field[row][col].setState(MOVED);
        field[selectedCell.row][selectedCell.col].setState(FREE);
        field[selectedCell.row][selectedCell.col].setNumber(0);
        points++;
    }
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            field[r][c].setDest(false);
        }
    }
    if (field[row][col].getState() == MOVABLE) {
        selectedCell = Point(row, col);
        for (Point p: field[row][col].moves) {
            field[p.row][p.col].setDest(true);
        }
    }
    updateMoves();
    calcState();
}

Game::Cell Game::Cell::clone() {
    Cell cell = Cell(this->state, this->number);
    cell.moves = std::vector<Point>(this->moves);
    return cell;
}