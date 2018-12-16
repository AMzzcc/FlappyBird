#include"TollgateScene.h"
#include"Player.h"
#include"barrierManager.h"
#include"gameOverScene.h"
#include"SimpleAudioEngine.h"

float play_x;
float play_y;

int gameStatus;
const int GAMESTART = 10;

int GameScore1 = 0;
int GameScore2 = 0;
int times=0;
bool TollgateScene::init()
{
	

	
	if (!Layer::init()) { return false; }
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("The xx - Intro.mp3", true);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	
	initBG();
	
	auto gameScoreLabel = CCLabelTTF::create("SCORE:", "fonts/Marker Felt.ttf", 24);
	gameScoreLabel->setColor(Color3B::GREEN);
	gameScoreLabel->retain();
	gameScoreLabel->setPosition(Point(visibleSize.width / 4, visibleSize.height * 5/ 6));
	this->addChild(gameScoreLabel, 5);
	

	

	Sprite*titleSprite = Sprite::create("title.png");
	titleSprite->setPosition(Point(visibleSize.width /2, visibleSize.height *3/ 4));
	this->addChild(titleSprite, 1);

	//auto gameScoreLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 30);
	
	this->scheduleUpdate();

	loadUI();


	m_player = Player::create();
	m_player->bindSprite(Sprite::create("bird2.png"));
	m_player->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	m_player->setTag(1);
	//创建刚体
	auto body1 = PhysicsBody::createCircle(m_player->getContentSize().width / 2);
	//刚体相关设置
	body1->setContactTestBitmask(1);

								   //绑定刚体
	m_player->setPhysicsBody(body1);
	this->addChild(m_player, 3);
	auto an = createAnimatel();
	m_player->getSprite()->runAction(an);

	play_x = m_player->getPositionX();
	play_y = m_player->getPositionY();


	

	barrierManager * barrierMgr = barrierManager::create();
	this->addChild(barrierMgr, 3);

	barrierMgr->bindPlayer(m_player);

	
	

	return true;

}
void TollgateScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();


	m_bgSprite1 = Sprite::create("land.png");
	m_bgSprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 12));
	
	auto body2 = PhysicsBody::create();
	body2->addShape(PhysicsShapeBox::create(m_bgSprite1->getContentSize()));
	
	body2->setDynamic(false);
	body2->setCategoryBitmask(1);
	body2->setCollisionBitmask(1);
	body2->setContactTestBitmask(1);

	m_bgSprite1->setPhysicsBody(body2);
	
	this->addChild(m_bgSprite1, 4);

	m_bgSprite2 = Sprite::create("day.png");
	m_bgSprite2->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(m_bgSprite2, 0);

	m_bgSprite3 = Sprite::create("land.png");      //第二张地图
	m_bgSprite3->setPosition(Point(visibleSize.width / 2*3, visibleSize.height / 12));
	
	auto body3 = PhysicsBody::create();
	body3->addShape(PhysicsShapeBox::create(m_bgSprite3->getContentSize()));
	body3->setCategoryBitmask(1);
	body3->setCollisionBitmask(1);
	body3->setContactTestBitmask(1);

	body3->setDynamic(false);

	
	m_bgSprite3->setPhysicsBody(body3);
	this->addChild(m_bgSprite3,4);

	m_bgSprite4 = Sprite::create("day.png");
	m_bgSprite4->setPosition(Point(visibleSize.width / 2*3, visibleSize.height / 2));
	this->addChild(m_bgSprite4, 0);

}
void TollgateScene::update(float delta)  //地图滚动
{
	int posX1 = m_bgSprite1->getPositionX();
	int posX2 = m_bgSprite2->getPositionX();
	int posX3 = m_bgSprite3->getPositionX();
	int posX4 = m_bgSprite4->getPositionX();
	
	times++;
	if (times == 180)
	{
		add(gameScoreLabel);
		
		times = 0;
	}
	

	int iSpeed = 1;

	posX1 -= iSpeed;
	posX2 -= iSpeed;
	posX3 -= iSpeed;
	posX4 -= iSpeed;

	Size mapSize = m_bgSprite1->getContentSize(); //地图大小

	if (posX1 <= -mapSize.width / 2)
	{
		posX1 = mapSize.width + mapSize.width / 2;
	}
	if (posX2 <= -mapSize.width / 2)
	{
		posX2 = mapSize.width + mapSize.width / 2;
	}
	if (posX3 <= -mapSize.width / 2)
	{
		posX3 = mapSize.width + mapSize.width / 2;
	}
	if (posX4 <= -mapSize.width / 2)
	{
		posX4 = mapSize.width + mapSize.width / 2;
	}

	m_bgSprite1->setPositionX(posX1);
	m_bgSprite2->setPositionX(posX2);
	m_bgSprite3->setPositionX(posX3);
	m_bgSprite4->setPositionX(posX4);


	
}

void TollgateScene::loadUI()  //跳跃按钮
{
	
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Button* jumpBtn = Button::create("jump.png");
	jumpBtn->setPosition(Point(visibleSize.width / 2, visibleSize.height / 10));
	this->addChild(jumpBtn,5);

	jumpBtn->addTouchEventListener(this, toucheventselector(TollgateScene::jumpEvent));

}
void TollgateScene::jumpEvent(Ref*, TouchEventType type)  //跳跃事件
{
	switch (type)
	{
		case TouchEventType::TOUCH_EVENT_ENDED:
			
			this->m_player->getPhysicsBody()->setVelocity(Vect(0, 300));
			break;
	}
}
void TollgateScene::startEvent(Ref*, TouchEventType type)
{
	
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_ENDED:
		gameStatus = GAMESTART;
		
		break;
	}
}
cocos2d::Animate*TollgateScene::createAnimatel() //小鸟动画
{
	int iFrameNum = 4;
	SpriteFrame*frame = NULL;
	Vector<SpriteFrame*>frameVec;

	for (int i = 2; i <= iFrameNum; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("bird%d.png", i), Rect(0, 0, 48, 48));
		frameVec.pushBack(frame);
	}
	

	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);

	Animate*action = Animate::create(animation);

	return action;
}
void TollgateScene::gameOver() 
{
	Director::getInstance()->replaceScene((TransitionFade::create(3.0f, gameOverScene::createScene())));
	
}

void TollgateScene::add(CCLabelTTF*oldLabel)
{
		GameScore2++;
		Size visibleSize = Director::getInstance()->getVisibleSize();
		this->removeChild(oldLabel);
		
		char str[100] = { '0' };
		sprintf(str, "%d", GameScore2);
		

		auto gameScoreLabe2 = CCLabelTTF::create(str, "fonts/Marker Felt.ttf", 24);
		gameScoreLabe2->setColor(Color3B::WHITE);
		gameScoreLabe2->retain();
		gameScoreLabe2->setPosition(Point(visibleSize.width /3, visibleSize.height *5/6));
		gameScoreLabel = gameScoreLabe2;
		this->addChild(gameScoreLabel, 5);
	
}
