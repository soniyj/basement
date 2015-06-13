#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <sstream>

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	// Update the Scene
	void update(float) override;

	void addLabelTitle(const std::string&, float);
	void addLabelText(const std::string&, cocos2d::Vec2, float);
	void addSimpleButton(const std::string&, cocos2d::Vec2, float);
	void addSpriteCoin(cocos2d::Vec2, int);
	void addSprite(cocos2d::Vec2, int);

	// Touch Events
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	// Key Events
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite *sprite4;
	cocos2d::EventListenerTouchOneByOne *listener;
	cocos2d::EventListenerKeyboard *keyListener;
	cocos2d::Label *lblCoins;

	// Simple Game variables (could be set from a file)
	unsigned int numEnemy;
	unsigned int numCoin;
	float coinSpeed;
	float enemySpeed;

	unsigned int coinsGot;

	enum
	{
		kTagSprite1 = 1, //Coin
		kTagSprite2,     //Other Images
		kTagSprite5      //Button
	};

	void restartScene();
};

#endif // __HELLOWORLD_SCENE_H__
