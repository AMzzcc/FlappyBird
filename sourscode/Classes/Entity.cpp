#include"Entity.h"
#include"barrierManager.h"
#include"TollgateScene.h"
#include"cocos2d.h"
#include"Player.h"

extern float play_x;
extern float play_y;
using namespace cocos2d;
Entity::Entity()
{
	m_sprite = NULL;
}
Entity::~Entity()
{

}
Sprite*Entity::getSprite()
{
	return this->m_sprite;
}
void Entity::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);

	Size size = m_sprite->getContentSize();
	m_sprite->setPosition(Point(size.width*0.5f, size.height*0.5f));
	this->setContentSize(size);
}