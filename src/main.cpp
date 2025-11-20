#include "raylib.h"
#include "raymath.h"
class Character
{
private:
	Texture2D texture{LoadTexture("assets/texture/Player.png") };
	Vector2 screenPos;
	Vector2 worldPos;
	//right for 1 left for -1
	float rightLeft{ 1.f };

	//ANIMATION VARIABLES

	float runningTime{};
	int frame{};
	const int MAXFRAMES{ 6 };
	const float UPDATETIME{ 1.f / 12.f };
	const float SPEED{ 4.f };


	//draw the character
	int column = 0;
	int idle_row = 1;
	int run_row_side = 4;
	int run_row_down = 3;
	int run_row_up = 5;
	int row{};
public:

	Vector2 GetWorldPos() { return worldPos; }
	void SetScreenPos(int winWidth, int winHeight);
	void Update(float deltaTime);
	

};



void Character::SetScreenPos(int winWidth, int winHeight)
{
	screenPos =
	{
		winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
		winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height / 10.0f),
	};
}

void Character::Update(float deltaTime)
{
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
		//set worldPos=worldPos+direction
		worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
		direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
		if (direction.y > 0.f && direction.x == 0.f)
		{
			row = run_row_down;
		}
		else if (direction.y < 0.f && direction.x == 0.f)
		{
			row = run_row_up;
		}
		else
		{
			row = run_row_side;
		}
	}
	else
	{
		row = idle_row;
	}

	runningTime += deltaTime;
	if (runningTime >= UPDATETIME)
	{
		frame++;
		runningTime = 0.f;
		if (frame > MAXFRAMES) frame = 0;
	}
}











int main()
{
	const int WINDOW_WIDTH{ 684 };
	const int WINDOW_HEIGHT{ 684 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OutRun");

	Texture2D map = LoadTexture("assets/tilesets/worldmap.png");
	Vector2 mapPos{ 0.0,0.0 };

	float speed{ 4.0 };


	Vector2 playerPos
	{
		WINDOW_WIDTH / 2.0f - 4.0f*(0.5f * (float)player.width / 6.0f),
		WINDOW_HEIGHT / 2.0f - 4.0f*(0.5f * (float)player.height / 10.0f),
	};
	
	float frameWidth = player.width / 6.0f;
	float frameHeight = player.height / 10.0f;

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);




	
		
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

		//update animation Time

	

		


		Rectangle source{
			frame * frameWidth,
			row* frameHeight,
			rightLeft*(float)player.width / 6.f,
			(float)player.height / 10.0f
		};

		Rectangle dest{ playerPos.x,playerPos.y,4.0f * (float)player.width / 6.0f,4.0f * (float)player.height / 10.0f };
		DrawTexturePro(player, source, dest, Vector2{}, 0.f, WHITE);
		EndDrawing();
	}
	CloseWindow();
}


