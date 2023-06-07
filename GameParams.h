#ifndef GAMEPARAMS_H
#define GAMEPARAMS_H

class GameParams {
public:
    GameParams() = default;
    int rowCount = 6;
    int colCount = 6;
    int diff = 1;
    bool autoSize = true;
    double cellSize = 1;
};

#endif
