#pragma once
#include "Novice.h"

class Enemy
{
private:
	int enemyPosX;
	int enemyPosY;
	int enemyPosX2;
	int enemyPosY2;
	int enemySpeed;
	int enemySpeed2;
	bool EnemyFlag;

public:
	Enemy();

	int getX() const { return enemyPosX; }
	int getY() const { return enemyPosY; }
	int getX2() const { return enemyPosX2; }
	int getY2() const { return enemyPosY2; }
	int Flag() const { return EnemyFlag; }

	void Drow();

	void move();

	void FlagChange();
};

