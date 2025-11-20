#include "raylib.h"
#include "raymath.h"

class Character
{
private:
	Texture2D texture{ LoadTexture("assets/texture/Player.png") };
	Vector2 screenPos{};
	Vector2 worldPos{};
	//right for 1 left for -1
	float rightLeft{ 1.f };
	float speed{ 4.0 };

	//ANIMATION VARIABLES

	float runningTime{};
	int frame{};
	const int MAXFRAMES{ 6 };
	const float UPDATETIME{ 1.f / 12.f };
	const float SPEED{ 4.f };
	float frameWidth{ };
	float frameHeight{ };

	//draw the character
	int column = 0;
	int idle_row = 1;
	int run_row_side = 4;
	int run_row_down = 3;
	int run_row_up = 5;
	int row{};
public:
	Character();
	Vector2 GetWorldPos() { return worldPos; }
	void SetScreenPos(int winWidth, int winHeight);
	void Update(float deltaTime);


};