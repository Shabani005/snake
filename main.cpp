#include <raylib.h>

int WINDOW_WIDTH = 500;
int WINDOW_HEIGHT= 500;

int main(){
    InitWindow(int(WINDOW_WIDTH), int(WINDOW_HEIGHT), "hello world");

    while (!WindowShouldClose()){
      if (IsKeyDown(KEY_ESCAPE)){
        CloseWindow();
      }
      BeginDrawing();
      ClearBackground(Color(GREEN));
      DrawFPS(int(0), int(0));
      DrawCircle(int(WINDOW_WIDTH/2), int (WINDOW_HEIGHT/2), float(10), Color(BLUE));
      EndDrawing();

  }
  CloseWindow();
  return 0;
}
