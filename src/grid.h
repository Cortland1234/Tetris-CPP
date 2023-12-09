#pragma once //included only once
#include <vector> //including vector data structure
#include <raylib.h>

class Grid
{

public:
    Grid(); //method for grid shape and size
    void InitiatlizeGrid();
    void PrintGrid();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int grid[20][10];

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowsDown(int row, int numRows);
    int numRows; //number of rows, columns, and size of each cell on game grid
    int numCols;
    int cellSize;
    std::vector<Color> colors; //Tetris needs 7 colors for the blocks, and 1 color for the grid
};

