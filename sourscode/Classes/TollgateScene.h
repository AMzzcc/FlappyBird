#ifndef _TollgateScene_H_
#define _TollgateScene_H_
#include"cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
//#include"HelloWorldScene.h"
using namespace cocos2d;

class Player;
class TollgateScene :public Layer
{
	public:
		static Scene * createScene() 
		{
			//创建物理世界场景
			auto scene = Scene::createWithPhysics();
			//对物理世界场景进行需要的设置（略，根据需要添加）
			scene->getPhysicsWorld();//->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
			scene->getPhysicsWorld()->setGravity(Vec2(0.0f, -450.0f));
			Size visibleSize = Director::getInstance()->getVisibleSize();
			auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	
			//物理世界边框
			auto node= Node::create();

			node->setPosition(Point(visibleSize.width/ 2, visibleSize.height/ 2));

			node->setPhysicsBody(body);

			scene->addChild(node);
			
			//创建层
			auto layer = TollgateScene::create();
			//设置层的物理世界
			//layer->setPhyWorld(scene->getPhysicsWorld);
			scene->addChild(layer);
			//返回场景
			return scene;
		}

		//virtual void removeChild(Node * child, bool cleanup);
		virtual void update(float delta);
		void TollgateScene::onEnter()
		{
			Layer::onEnter();
			//物理碰撞
			auto contactListener = EventListenerPhysicsContact::create();

			contactListener->onContactBegin = CC_CALLBACK_1(TollgateScene::onContactBegin, this);
			_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
		}
		bool TollgateScene::onContactBegin(cocos2d::PhysicsContact& contact)
		{
			
			this->gameOver();
			return true;
		}
		void add(CCLabelTTF*oldLabel);
		void TollgateScene::gameOver();
		CCLabelTTF*gameScoreLabel;
		Label*gameScoreLabel2;
		virtual bool init();
		CREATE_FUNC(TollgateScene);
		void setPhyWorld(PhysicsWorld* world) {
			m_world = world;
		}
	private:
		void initBG();
		void loadUI();
		
		void jumpEvent(Ref*, TouchEventType type);
		void startEvent(Ref*, TouchEventType type);

		PhysicsWorld* m_world;
		

		cocos2d::Animate*createAnimatel();
	private:
		Sprite * m_bgSprite1;
		Sprite * m_bgSprite2;
		Sprite * m_bgSprite3;
		Sprite * m_bgSprite4;
		
		 Player*m_player;
		 
};
#endif

