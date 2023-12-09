#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int columns);
        std::vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotation();
        int id;
        std::map<int, std::vector<Position>> cells; // map/dict with vectors of Position objects
    private:
        int cellSize;
        int rotationState; //current rotation of block
        std::vector<Color> colors;
        int rowOffset; //These two offset variables control where on the grids to move the block. This is done by moving the block's origin point.
        int colOffset;

};
