#include "Character.h"

//constructor
Character::Character(int winWidth, int winHeight)
{
	frameWidth = static_cast<float>(texture.width) / MAXFRAMES;
	frameHeight	 = texture.height / 10.f;

	screenPos =
	{
		static_cast<float>(winWidth) / 2.0f - scale * (0.5f * frameWidth),
		static_cast<float>(winHeight) / 2.0f - scale * (0.5f * frameHeight)
	};

}

void Character::Update(float deltaTime)
{
	worldPosLastFrame = worldPos;
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

	Rectangle dest{ screenPos.x,screenPos.y,scale * frameWidth,scale * frameHeight };

	DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Character::UndoMovement()
{
	worldPos = worldPosLastFrame;
}
