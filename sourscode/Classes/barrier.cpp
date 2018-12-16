#include"barrier.h"
#include"Player.h"

barrier::barrier()
{
	m_isAlive = false;
}
barrier::~barrier(){}
bool barrier::init()
{
	return true;
}
void barrier::show()
{
	if (getSprite() != NULL)
	{
		setVisible(true);
		m_isAlive = true;
	}
}
void barrier::hide1()
{
	if (getSprite() != NULL)
	{
		setVisible(false);
		reset1();
		m_isAlive = false;
	}
}

void barrier::hide2()
{
	if (getSprite() != NULL)
	{
		setVisible(false);
		reset2();
		m_isAlive = false;
	}
}

void barrier::hide3()
{
	if (getSprite() != NULL)
	{
		setVisible(false);
		reset3();
		m_isAlive = false;
	}
}

void barrier::hide4()
{
	if (getSprite() != NULL)
	{
		setVisible(false);
		reset4();
		m_isAlive = false;
	}
}

float y;
float x;
void barrier::reset1()
{
	if (getSprite() != NULL)
	{
		
		setPosition(Point(x=512.5, y=-135 + CCRANDOM_0_1() *300));


	}
}
void barrier::reset2()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(512.5, 730+y));

	}
}

void barrier::reset3()
{
	if (getSprite() != NULL)
	{

		setPosition(Point(x+160, y = -100 + CCRANDOM_0_1() * 380));

	}
}
void barrier::reset4()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(x+160, 710 + y));

	}
}

bool barrier::isAlive()
{
	return m_isAlive;
}
bool barrier::isCollidWithPlayer(Player*player)
{
	Rect entityRect = player->getBoundingBox();
	Point barrierPos = getPosition();
	return entityRect.containsPoint(barrierPos);
}