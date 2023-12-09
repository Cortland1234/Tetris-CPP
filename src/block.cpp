#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();

    for(Position item: tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows; //changing the offsets
    colOffset += columns;
}

std::vector<Position> Block::GetCellPositions() //method for storing and modifying the positions of the block cells
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + colOffset); //changing position of block on grid using offsets
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate() //handles block rotations
{
    rotationState ++; //increases rotation state

    if (rotationState == (int)cells.size()) //if rotation state is the max cell size, resets rotationState to 0
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState --;

    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
