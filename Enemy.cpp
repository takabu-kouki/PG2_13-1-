#include "Enemy.h"

Enemy::Enemy()
{
	enemyPosX = 500;
	enemyPosY = 100;
	enemyPosX2 = 100;
	enemyPosY2 = 200;
	enemySpeed = 10;
	enemySpeed2 = 10;
	EnemyFlag = false;
}

void Enemy::Drow()
{
	if (EnemyFlag == false)
	{
		Novice::DrawEllipse(getX(), getY(), 50, 50, 0.0f, RED, kFillModeSolid);
		Novice::DrawEllipse(getX2(), getY2(), 50, 50, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::FlagChange()
{
	EnemyFlag = true;

}

void Enemy::move()
{
	enemyPosX += enemySpeed;
	enemyPosX2 -= enemySpeed2;

	if (enemyPosX < 0)
	{
		enemySpeed *= -1;
	}

	if (enemyPosX > 1280)
	{
		enemySpeed = -enemySpeed;
	}

	if (enemyPosX2 < 0)
	{
		enemySpeed2 *= -1;
	}

	if (enemyPosX2 > 1280)
	{
		enemySpeed2 = -enemySpeed2;
	}
}

