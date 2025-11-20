#include "raylib.h"
#include "raymath.h"

#include "Character.h"

int main()
{
	const int WINDOW_WIDTH{ 684 };
	const int WINDOW_HEIGHT{ 684 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OutRun");
	Character player;
	player.SetScreenPos(WINDOW_WIDTH, WINDOW_HEIGHT);

	Texture2D map = LoadTexture("assets/tilesets/worldmap.png");
	Vector2 mapPos{ 0.0,0.0 };


	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		mapPos = Vector2Scale(player.GetWorldPos(), -1.f);
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

		player.Update(GetFrameTime());



	

		



		EndDrawing();
	}
	CloseWindow();
}


