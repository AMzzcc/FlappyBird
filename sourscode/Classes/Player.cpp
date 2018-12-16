#include"Player.h"

Player::Player()
{
	m_isJumping = false;
}
Player::~Player(){}

bool Player::init()
{
	return true;
}

void Player::jump()
{
	if (getSprite() == NULL)
	{
		return;
	}
	/*if (m_isJumping)
	{
		return;
	}*/
	m_isJumping = true;

	auto jump = JumpBy::create(1.5f, Point(0, 0), 90, 1);
	

	auto callFunc = CallFunc::create([&]() {
		m_isJumping = false;
	});

	auto jumpActions = Sequence::create(jump, callFunc, NULL);
	this->runAction(jumpActions);
}