#ifndef _barrierManager_H_
#define _barrierManager_H_
#include"cocos2d.h"
#include"barrier.h"
USING_NS_CC;

#define MAX_BARRIER_NUM 2
class barrierManager :public Node
{
	public:
		CREATE_FUNC(barrierManager);
		virtual bool init();
		void bindPlayer(Player*player);//°ó¶¨Íæ¼Ò

		virtual void update(float dt);
	private:
		void createBarrier();
		Player * m_player;
	private:
		Vector<barrier*>m_barrierArr1;
		Vector<barrier*>m_barrierArr2;
		Vector<barrier*>m_barrierArr3;
		Vector<barrier*>m_barrierArr4;
};
#endif
