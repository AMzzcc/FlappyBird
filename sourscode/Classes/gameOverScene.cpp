#include "gameOverScene.h"
#include"cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "g:\Cocos\CocosProjects\FlappyBird\proj.win32\Entity.h"
#include"g:\Cocos\CocosProjects\FlappyBird\proj.win32\TollgateScene.h"


using namespace cocostudio::timeline;

USING_NS_CC;

using namespace cocos2d::extension;
using namespace cocostudio::timeline;

extern int GameScore2;
Scene* gameOverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = gameOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool gameOverScene::init()
{
	//  you can create scene with following comment code instead of using csb file.
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite1 = Sprite::create("night.png");
	Sprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(Sprite1, 0);

	auto Score = CCLabelTTF::create(StringUtils::format("SCORE:%d",GameScore2), "fonts/Marker Felt.ttf", 24);
	Score->setColor(Color3B::GREEN);
	Score->retain();
	Score->setPosition(Point(visibleSize.width / 2, visibleSize.height /2));
	this->addChild(Score, 5);


	Sprite*titleSprite = Sprite::create("game_over.png");
	titleSprite->setPosition(Point(visibleSize.width / 2, visibleSize.height * 3 / 4));
	this->addChild(titleSprite, 1);

	auto closeItem = MenuItemImage::create(
		"button_ok.png",
		"text_ready.png",
		CC_CALLBACK_1(gameOverScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void gameOverScene::menuCloseCallback(Ref* sender)
{
	Director::getInstance()->end();
}