#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 500
#define CELL_COUNT    20
#define CELL_WIDTH    (WINDOW_WIDTH / CELL_COUNT)
#define CELL_HEIGHT   (WINDOW_HEIGHT / CELL_COUNT)
#define MAX_SNAKE_LENGTH 100

int randint(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Classic Snake");
    //SetTargetFPS(60);

    int score = 0;

    int snakeX[MAX_SNAKE_LENGTH];
    int snakeY[MAX_SNAKE_LENGTH];
    int snakeLength = 3;

    for (int i = 0; i < snakeLength; i++) {
        snakeX[i] = CELL_COUNT / 2 - i;
        snakeY[i] = CELL_COUNT / 2;
    }

    int dirX = 1;
    int dirY = 0;

    int foodX = randint(0, CELL_COUNT - 1);
    int foodY = randint(0, CELL_COUNT - 1);

    float moveDelay = 0.15f;
    float moveTimer = 0.0f;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_A) && dirX != 1) { dirX = -1; dirY = 0; }
        if (IsKeyPressed(KEY_D) && dirX != -1) { dirX = 1; dirY = 0; }
        if (IsKeyPressed(KEY_W) && dirY != 1) { dirX = 0; dirY = -1; }
        if (IsKeyPressed(KEY_S) && dirY != -1) { dirX = 0; dirY = 1; }

        moveTimer += GetFrameTime();
        if (moveTimer >= moveDelay) {
            moveTimer = 0.0f;

            for (int i = snakeLength - 1; i > 0; i--) {
                snakeX[i] = snakeX[i - 1];
                snakeY[i] = snakeY[i - 1];
            }

            snakeX[0] += dirX;
            snakeY[0] += dirY;

            if (snakeX[0] < 0) snakeX[0] = CELL_COUNT - 1;
            if (snakeX[0] >= CELL_COUNT) snakeX[0] = 0;
            if (snakeY[0] < 0) snakeY[0] = CELL_COUNT - 1;
            if (snakeY[0] >= CELL_COUNT) snakeY[0] = 0;

            for (int i = 1; i < snakeLength; i++) {
                if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
                    CloseWindow();
                    return 0;
                }
            }

            if (snakeX[0] == foodX && snakeY[0] == foodY) {
                snakeLength++;
                if (snakeLength > MAX_SNAKE_LENGTH) snakeLength = MAX_SNAKE_LENGTH;
                foodX = randint(0, CELL_COUNT - 1);
                foodY = randint(0, CELL_COUNT - 1);
                score++;
            }
        }

        BeginDrawing();
        ClearBackground(GREEN);

        for (int i = 0; i < CELL_COUNT; i++) {
            DrawLine(0, CELL_HEIGHT * i, WINDOW_WIDTH, CELL_HEIGHT * i, DARKGREEN);
            DrawLine(CELL_WIDTH * i, 0, CELL_WIDTH * i, WINDOW_HEIGHT, DARKGREEN);
        }

        DrawRectangle(foodX * CELL_WIDTH, foodY * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, RED);

        for (int i = 0; i < snakeLength; i++) {
            DrawRectangle(snakeX[i] * CELL_WIDTH, snakeY[i] * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, BLUE);
        }

        char scoreText[64];
        sprintf(scoreText, "Score: %d", score);
        DrawText(scoreText, 375, 10, 20, BLACK);
        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
