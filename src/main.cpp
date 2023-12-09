#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0; //used to keep track of how long the game has been running

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    //create window, 500px X 620px
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60); //limit FPS

    Font font = LoadFontEx("Font/PixelFont.ttf", 64, 0, 0);

    Game game = Game();


    while(WindowShouldClose() == false) //if esc is pressed or X is clicked, window closes
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2)) //this makes the block fall every 500 ms
        {
            game.MoveDown();
        }
        BeginDrawing();
        ClearBackground(tetrisBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAMEOVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); //used to center score text no matter what the number is


        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }


    //close window
    CloseWindow();
    return 0;
}