#ifndef _barrier_H_
#define _barrier_H_
#include"cocos2d.h"
#include"Entity.h"
#include"Player.h"
using namespace cocos2d;
class barrier :public Entity
{
	public:
		barrier();
		~barrier();
		CREATE_FUNC(barrier);
		virtual bool init();
		bool isCollidWithPlayer(Player*player);
	public:
		void show();
		void hide1();
		void hide2();
		void hide3();
		void hide4();
		void reset1();
		void reset2();
		void reset3();
		void reset4();
		bool isAlive();

	private:
		bool m_isAlive;
};
#endif