#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int WINDOW_WIDTH = 500;
int WINDOW_HEIGHT= 500;

int randint(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main(){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snek game");
    SetTargetFPS(20000);
    
    int score = 0;
    
    // divide velocity by GetFPS() to normalize speed

    
    float vel = 200.0f; 
    float currX = WINDOW_WIDTH/2.0f;
    float currY = WINDOW_HEIGHT/2.0f;
    int recW = 50;
    int recH = 20;
    
    int dirX = 0;
    int dirY = 0;

    int foodX = randint(0, WINDOW_WIDTH - 10);
    int foodY = randint(0, WINDOW_HEIGHT - 10);
    
    

    while (!WindowShouldClose()){

      if (IsKeyDown(KEY_ESCAPE)){
        CloseWindow();
      }

      BeginDrawing();
      
      char scoreText[64];
      sprintf(scoreText, "Score: %d", score); 

      ClearBackground(GREEN); 
      DrawFPS(7, 5);
    
      DrawText(scoreText, 375, 10, 20, BLACK);

      Rectangle snek = { (float)currX, (float)currY, (float)recW, (float)recH };
      Rectangle food = { (float)foodX, (float)foodY, 10, 10 };
      
      DrawRectangleRec(food, RED);
      DrawRectangleRec(snek, BLUE);

      if (IsKeyDown(KEY_A)){
        recW = 50;
        recH = 20;
        dirX = -1;
        dirY = 0;
      }
      if (IsKeyDown(KEY_D)){
        recW = 50;
        recH = 20;
        dirX = 1;
        dirY = 0;
      }
      
      if (IsKeyDown(KEY_S) ){
        recW = 20;
        recH = 50;
        dirY = 1;
        dirX = 0;
      }

      if (IsKeyDown(KEY_W)){ 
        recW = 20;
        recH = 50;
        dirY = -1;
        dirX = 0;
      }
    
      currX += dirX * vel * GetFrameTime();
      currY += dirY * vel * GetFrameTime();
      
            
      if (CheckCollisionRecs(snek, food)){
        foodX = randint(0, WINDOW_WIDTH - 10);
        foodY = randint(0, WINDOW_HEIGHT - 10);
        score++;
      }

      EndDrawing();

  }
  CloseWindow();
  return 0;
}
