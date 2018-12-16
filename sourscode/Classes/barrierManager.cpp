#include"barrierManager.h"
#include"Player.h"
#include"barrier.h"
#include"cocos2d.h"
#include"TollgateScene.h"
#include"g:\Cocos\CocosProjects\FlappyBird\proj.win32\gameOverScene.h"

using namespace cocos2d;

//extern int GameScore1;

bool barrierManager::init()
{
	createBarrier();
	this->scheduleUpdate();
	//barrierMgr->bindPlayer(m_player);
	return true;
}

void barrierManager::createBarrier()
{
	barrier*barrier1 = NULL;
	Sprite *sprite = NULL;
	barrier*barrier2 = NULL;
	/*barrier*barrier3 = NULL;
	barrier*barrier4 = NULL;*/
	
	for (int i = 0; i < (MAX_BARRIER_NUM/2 ); i++)
	{
		barrier1 = barrier::create();
		barrier1->bindSprite(Sprite::create("pipe_up.png"));
		barrier1->reset1();
		auto body4 = PhysicsBody::create();
		body4->addShape(PhysicsShapeBox::create(barrier1->getContentSize()));

		body4->setDynamic(false);
		body4->setCategoryBitmask(1);
		body4->setCollisionBitmask(1);
		body4->setContactTestBitmask(1);

		barrier1->setPhysicsBody(body4);
		

		barrier2 = barrier::create();
		barrier2->bindSprite(Sprite::create("pipe_down.png"));
		barrier2->reset2();
		auto body5 = PhysicsBody::create();
		body5->addShape(PhysicsShapeBox::create(barrier2->getContentSize()));

		body5->setDynamic(false);
		body5->setCategoryBitmask(1);
		body5->setCollisionBitmask(1);
		body5->setContactTestBitmask(1);

		barrier2->setPhysicsBody(body5);

		/*barrier3 = barrier::create();
		barrier3->bindSprite(Sprite::create("pipe2_up.png"));
		barrier3->reset3();

		barrier4 = barrier::create();
		barrier4->bindSprite(Sprite::create("pipe2_down.png"));
		barrier4->reset4();*/

		this->addChild(barrier1,3);
		this->addChild(barrier2,3);
		/*this->addChild(barrier3);
		this->addChild(barrier4);*/

		m_barrierArr1.pushBack(barrier1);
		m_barrierArr2.pushBack(barrier2);
		/*m_barrierArr3.pushBack(barrier3);
		m_barrierArr4.pushBack(barrier4);*/
	}
}
void barrierManager::update(float dt)
{
	/*switch (GAME_STATUS)
	{
	case GAME_STATUS_PLAYING:*/
	/*if (m_player->getPositionY() > 0)
	{
		m_player->setPositionY(m_player->getPositionY() - 0.5);

	}*/
	
	for (auto barrier1 : m_barrierArr1)
	{
		if (barrier1->isAlive())
		{	
			//if (barrier1->getPositionX() == 183.5)
			//{
			//	GameScore1++; // 
			//	
			//}
			barrier1->setPositionX(barrier1->getPositionX() - 2);
			if (barrier1->getPositionX() < 0)
			{
				barrier1->hide1();
			}

			/*if ((m_player->getPositionX() >= barrier1->getPositionX() - 56.5) && (m_player->getPositionX() <= barrier1->getPositionX() + 56.5))
			{
				if (m_player->getPositionY() <= barrier1->getPositionY() + 384)
				{
					Director::getInstance()->replaceScene(TransitionFade::create(3.0f, gameOverScene::createScene()));
				}
			}*/
				
			else if (barrier1->isCollidWithPlayer(m_player))
			{
				Director::getInstance()->replaceScene(TransitionFade::create(3.0f, gameOverScene::createScene()));
			}
		}
		else
		{
			barrier1->show();
		}

	}
	for (auto barrier2 : m_barrierArr2)
	{
		if (barrier2->isAlive())
		{
			barrier2->setPositionX(barrier2->getPositionX() - 2);
			if (barrier2->getPositionX() < 0)
			{
				barrier2->hide2();
			}
			/*if ((m_player->getPositionX() >= barrier2->getPositionX() - 56.5) && (m_player->getPositionX() <= barrier2->getPositionX() + 56.5))
			{
				if (m_player->getPositionY() >= barrier2->getPositionY() - 384)
				{
					Director::getInstance()->replaceScene(TransitionFade::create(3.0f, gameOverScene::createScene()));
					
				}
			}*/
			else if (barrier2->isCollidWithPlayer(m_player))
			{
				Director::getInstance()->replaceScene(TransitionFade::create(3.0f, gameOverScene::createScene()));
			}
		}
		else
		{
			barrier2->show();
		}

	}
	/*for (auto barrier3 : m_barrierArr3)
	{
		if (barrier3->isAlive())
		{
			barrier3->setPositionX(barrier3->getPositionX() - 4);
			if (barrier3->getPositionX() < 0)
			{
				barrier3->hide3();
			}
		}
		else
		{
			barrier3->show();
		}


	}

	for (auto barrier4 : m_barrierArr4)
	{
		if (barrier4->isAlive())
		{
			barrier4->setPositionX(barrier4->getPositionX() - 4);
			if (barrier4->getPositionX() < 0)
			{
				barrier4->hide4();
			}
		}
		else
		{
			barrier4->show();
		}

	}*/
}
void barrierManager::bindPlayer(Player*player)
{
	m_player = player;
}