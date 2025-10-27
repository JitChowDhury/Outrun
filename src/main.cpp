#include "raylib.h"
#include "raymath.h"

int main()
{
	const int windowWidth{384};
	const int windowHeight{384};
	InitWindow(windowWidth, windowHeight, "OutRun");

	//map

	Texture2D map = LoadTexture("assets/tilesets/worldmap.png");
	Vector2 mapPos{0.0, 0.0};
	float speed{4.0};

	//Player
	Texture2D player = LoadTexture("assets/texture/Player.png");
	Vector2 playerPos{
		windowWidth / 2.0f - 4.0f * (0.5f * (float)player.width / 6.0f),
		windowHeight / 2.0f - 4.0f * (0.5f * (float)player.height / 10.0f)
	};

	float frameWidth = player.width / 6.0f;
	float frameHeight = player.height / 10.0f;


	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		Vector2 direction{};

		if (IsKeyDown(KEY_A))
			direction.x -= 1.0;
		if (IsKeyDown(KEY_D))
			direction.x += 1.0;
		if (IsKeyDown(KEY_W))
			direction.y -= 1.0;
		if (IsKeyDown(KEY_S))
			direction.y += 1.0;

		if (Vector2Length(direction) != 0.0)
		{
			// set map pos = mappos-direction

			mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
		}
		//draw the map
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
		//draw the character

		int column = 0;
		int row = 1;

		Rectangle source{ 
			column*frameWidth,
			row*frameHeight,
			(float)player.width / 6.f,
			(float)player.height / 10.0f };

		Rectangle dest{ playerPos.x,playerPos.y,4.0f * (float)player.width / 6.0f,4.0f * (float)player.height / 10.0f };
		DrawTexturePro(player, source, dest, Vector2{}, 0.f, WHITE);
		EndDrawing();
	}
	CloseWindow();
}