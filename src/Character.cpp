#include "Character.h"





Character::Character()
{
	frameWidth = (float)texture.width / MAXFRAMES;
	frameHeight	 = texture.height / 10.f;

}

void Character::SetScreenPos(int winWidth, int winHeight)
{
	screenPos =
	{
		winWidth / 2.0f - 4.0f * (0.5f * frameWidth),
		winHeight / 2.0f - 4.0f * (0.5f * frameHeight)
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

	Rectangle source{

	frame * frameWidth,
	row * frameHeight,
	rightLeft * frameWidth,
	frameHeight

	};

	Rectangle dest{ screenPos.x,screenPos.y,4.0f * frameWidth,4.0f * frameHeight };

	DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}
