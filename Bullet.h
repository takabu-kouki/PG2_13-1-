#pragma once
#include "Player.h"

class Bullet
{
private:
	int bulletPosX;
	int bulletPosY;
	int bulletSpeed;
	bool BulletFlag = false;
public:

	Bullet();
	void SetPosition(int x, int y);

	int bulletGetPosX() const { return bulletPosX; }
	int bulletGetPosY() const { return bulletPosY; }

	void Drow();
	void shot(char keys[], char preKeys[], int x, int y);

	Player player;
};
