#include "raylib.h"

int main()
{
	const int windowWidth{ 384 };
	const int windowHeight{ 384 };
	InitWindow(windowWidth, windowHeight, "OutRun");

	Texture2D map = LoadTexture("assets/tilesets/worldmap.png");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		Vector2 mapPos{ 0.0,0.0 };
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
		EndDrawing();
	}
	CloseWindow();


}