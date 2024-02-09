#include "Player.h"
#include <Novice.h>

Player::Player()
{
    playerPosX = 1280 / 2;
    playerPosY = 720 / 2;
    playerSpeedX = 0;
    playerSpeedY = 0;
}

void Player::Drow()
{
    Novice::DrawEllipse(playerGetPosX(), playerGetPosY(), 50, 50, 0.0f, WHITE, kFillModeSolid);
}

void Player::move(char keys[])
{
    playerPosX += playerSpeedX;
    playerPosY += playerSpeedY;

    playerSpeedX = 0;
    playerSpeedY = 0;

    if (keys[DIK_RIGHT] || keys[DIK_D]) {
        playerSpeedX = 10;
    }
    if (keys[DIK_LEFT] || keys[DIK_A]) {
        playerSpeedX = -10;
    }
    if (keys[DIK_UP] || keys[DIK_W]) {
        playerSpeedY = -10;
    }
    if (keys[DIK_DOWN] || keys[DIK_S]) {
        playerSpeedY = 10;
    }
}

void Player::shoot()
{

}
