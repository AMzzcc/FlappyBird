#include "startScene.h"
#include"cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "g:\Cocos\CocosProjects\FlappyBird\proj.win32\Entity.h"
#include"g:\Cocos\CocosProjects\FlappyBird\proj.win32\TollgateScene.h"


using namespace cocostudio::timeline;

USING_NS_CC;

using namespace cocos2d::extension;  
using namespace cocostudio::timeline;

Scene* startScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = startScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool startScene::init()
{
	//  you can create scene with following comment code instead of using csb file.
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object

	auto rootNode = CSLoader::createNode("Scene1.csb");

	this->addChild(rootNode);

	//auto UI = cocostudio::GUIReader::getInstance()->widgetFromBinaryFile("button_play.png");
	//this->addChild(UI);
	//Button*Start = (Button*)Helper::seekWidgetByName(UI, "startBtn");
	//Button*startBtn = (Button*)Helper::seekWidgetByName(UI, "startBtn");
	//startBtn->addTouchEventListener(this, toucheventselector(startScene::onClick));

	 auto closeItem = MenuItemImage::create(
	                                          "button_play.png",
	                                          "text_ready.png",
	                                          CC_CALLBACK_1(startScene::menuCloseCallback, this));
	   
	closeItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	   // create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//   /////////////////////////////
	//   // 3. add your codes below...

	//   // add a label shows "Hello World"
	//   // create and initialize a label
	//   
	//   auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	//   
	//   // position the label on the center of the screen
	//   label->setPosition(Vec2(origin.x + visibleSize.width/2,
	//                           origin.y + visibleSize.height - label->getContentSize().height));

	//   // add the label as a child to this layer
	//   this->addChild(label, 1);

	//   // add "startScene" splash screen"
	//auto sprite = Sprite::create("bird1.png");

	////   // position the sprite on the center of the screen
	//sprite->setPosition(Vec2(471.09, 164.04));

	////   // add the sprite as a child to this layer
	//this->addChild(sprite, 0);


	//////////////////////////////
	// 1. super init first
	//Button* PlayBtn = (Button*)Helper::seekWidgetByName(UI, "button_play.png");




	return true;
}

void startScene::menuCloseCallback(Ref* sender)
{
	Director::getInstance()->replaceScene((TransitionFade::create(3.0f,TollgateScene::createScene())));


}

/*void startScene::onClick(Ref*, TouchEventType type)
{
switch (type)
{
case TouchEventType::TOUCH_EVENT_BEGAN:
break;
case TouchEventType::TOUCH_EVENT_MOVED:
break;
case TouchEventType::TOUCH_EVENT_ENDED:
if (startBtn->isVisible())
{
startBtn->setVisible(false);
}
else
{
startBtn->setVisible(true);
}
break;

}

}*/
