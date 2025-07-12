#include <raylib.h>
#include <string>
#include <cstdlib>

int WINDOW_WIDTH = 500;
int WINDOW_HEIGHT= 500;

int randint(int min, int max) {
    return min + rand() % (max - min + 1);
}


int main(){
    InitWindow(int(WINDOW_WIDTH), int(WINDOW_HEIGHT), "snek game");
    SetTargetFPS(60);
    
    int score = 0;
    int vel = 2; 
    int currX = WINDOW_WIDTH/2;
    int currY = WINDOW_HEIGHT/2;
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

      std::string scoreText = "score: " + std::to_string(score);

      ClearBackground(Color(GREEN)); 
      DrawFPS(int(0), int(0));
    
      DrawText(scoreText.c_str() , 375, 10, 20, BLACK);

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
    
      currX += dirX * vel;
      currY += dirY * vel;
      
            
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
