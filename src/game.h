#pragma once
#include "grid.h"
#include "blocks.cpp"

//Game class is a contianer for all game elements (blocks, grid, colors, etc)
//it also contains logic for controlling positions of blocks 

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void MoveDown();
    void HandleInput();  
    bool gameOver;
    int score;
    Music music;

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    std::vector<Block> blocks; //vector for all blocks in the game
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveLeft();
    void MoveRight(); 
    Sound rotateSound;
    Sound clearSound;
};