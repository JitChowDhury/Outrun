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
	const float MAP_SCALE{ 4.0f };


	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		mapPos = Vector2Scale(player.GetWorldPos(), -1.f);
		DrawTextureEx(map, mapPos, 0.0, MAP_SCALE, WHITE);

		player.Update(GetFrameTime());
		//check map bounds
		if (player.GetWorldPos().x < 0.f ||
			player.GetWorldPos().y<0.f ||
			player.GetWorldPos().x+WINDOW_WIDTH>map.width* MAP_SCALE ||
			player.GetWorldPos().y+WINDOW_HEIGHT>map.height* MAP_SCALE)
		{
			player.UndoMovement();


		}



	

		



		EndDrawing();
	}
	CloseWindow();
}


