#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;

    InitiatlizeGrid();
    colors = GetCellColors();
}

void Grid::InitiatlizeGrid()
{
    for(int row = 0; row < numRows; row++) //this iterates through the grid array and assigns a value of 0 to all elements
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::PrintGrid() //looks at each element in grid array and prints value
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() //Draw shapes with certain colors depending on index in the color vector
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column]; //iterates through each cell on the grid, and assigns a value to that cell
            DrawRectangle(column * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]); //additions and subtractions are there to make the grid lines visible on the game grid

        }
    }
}

bool Grid::IsCellOutside(int row, int column) //prevent blocks from moving outside the game grid
{
    if(row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column) //checks if current cell is empty
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows() //clears completed rows and adds to completed counter
{
    int completedRows = 0;
    for (int row = numRows - 1; row >= 0; row--) //iterates trhough grid in reverse order
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completedRows++;
        }
        else if (completedRows > 0)
        {
            MoveRowsDown(row, completedRows);
        }
    }
    return completedRows;
}

bool Grid::IsRowFull(int row) //checks if a row is full of blocks
{
    for (int column = 0; column < numCols; column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) //clears row 
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowsDown(int row, int numRows) //moves rows down depending on how many rows were full
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
};