#include "HelloWorldScene.h"

USING_NS_CC;

// Just for testing sholud be read from a config file
char *Images[] = {"Coin.png","Leefy-Happy.png","Petal-Happy.png"};

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	// Init game varialbes
	this->numEnemy = 10;
	this->numCoin = 5;
	this->coinSpeed = 2.5;
	this->enemySpeed = 3;
	this->coinsGot = 0;
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin      = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

	this->addLabelTitle("*** Catch the Coins ***", 24);
	this->addLabelText("Coins 0", Vec2(origin.x, origin.y), 24);
	
	// Event Listener
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	
	// Sprite Update
	sprite4 = Sprite::create(Images[0]);
	sprite4->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	sprite4->setScale(0.5f);
	this->addChild(sprite4, 0);
	this->scheduleUpdate();
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite4);

	this->addSimpleButton("menu/ButtonGreenLong.png", Vec2(320, 120), 0.2);

	// Sprite creation
	for (unsigned int i = 0; i < this->numEnemy ; i++)
		this->addSprite(Vec2(0, 0), kTagSprite2);

	for (unsigned int i = 0; i < this->numCoin; i++)
		this->addSpriteCoin(Vec2(0, 0), kTagSprite1);

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::update(float delta)
{
	auto position = sprite4->getPosition();
	position.y -= 250 * delta;
	if (position.y  < 0 - (sprite4->getBoundingBox().size.width / 2))
		position.y = this->getBoundingBox().getMaxX() + sprite4->getBoundingBox().size.width / 2;
	sprite4->setPosition(position);
}

// Title goes in the middle of the screen and generally doesn't change
void HelloWorld::addLabelTitle(const std::string& lbl, float size)
{
	auto label = Label::createWithTTF(lbl, "fonts/Marker Felt.ttf", size);

	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
		
	this->addChild(label, 1);
}

void HelloWorld::addLabelText(const std::string& lbl, Vec2 pos, float size)
{
	lblCoins = Label::createWithTTF(lbl, "fonts/Marker Felt.ttf", size);

	lblCoins->setPosition(Vec2(pos.x + lblCoins->getContentSize().width,
		pos.y + visibleSize.height - lblCoins->getContentSize().height));

	this->addChild(lblCoins, 1);
}

void HelloWorld::addSimpleButton(const std::string& fileName, Vec2 pos, float scale)
{
	auto sprite = Sprite::create(fileName);
	sprite->setScale(scale);
	sprite->setPosition(Vec2(pos.x + sprite->getContentSize().width,
		pos.y + visibleSize.height - sprite->getContentSize().height));

	this->addChild(sprite, 1, kTagSprite5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite);
}

void HelloWorld::addSpriteCoin(Vec2 p, int tag)
{
	auto sprite = Sprite::create(Images[0]);

	float x = 20 + (rand() % (int)(visibleSize.width - sprite->getBoundingBox().size.width / 2));
	//float y = (sprite->getBoundingBox().size.height / 2) + (rand() % (int)(visibleSize.height - sprite->getBoundingBox().size.height / 2));
	float y = visibleSize.height/2 + (rand() % (int)(visibleSize.height - sprite->getBoundingBox().size.height / 2));

	sprite->setPosition(Vec2(x, y));
	sprite->setScale(0.5f);

	auto moveTo = MoveTo::create(this->coinSpeed, Vec2(x, y));
	sprite->runAction(moveTo);
	
	auto moveBy = MoveBy::create(this->coinSpeed, Vec2(y - visibleSize.height, x - visibleSize.width));
	sprite->runAction(moveBy);

	auto move4e = RepeatForever::create(moveBy);
	sprite->runAction(move4e);

	this->addChild(sprite, 4, tag);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite);
}

void HelloWorld::addSprite(Vec2 p, int tag)
{
	float random = CCRANDOM_0_1();
	//output = min + (rand() % (int)(max - min + 1))
	int img = 1 + (rand() % (int)(2 - 1 + 1));
	auto sprite = Sprite::create(Images[img]);
		
	float x = 20 + (rand() % (int)(visibleSize.width - sprite->getBoundingBox().size.width / 2));
	float y = (sprite->getBoundingBox().size.height / 2) + (rand() % (int)(visibleSize.height - sprite->getBoundingBox().size.height / 2));
	
	sprite->setPosition(Vec2(x, y));
	sprite->setScale(0.3f);

	if (random < 0.60) {
		auto rotateBy = RotateBy::create(2.0f, 40.0f);
		sprite->runAction(rotateBy);
	}

	this->addChild(sprite, 5, tag);

	auto moveTo = MoveTo::create(this->enemySpeed, Vec2(x, y));
	sprite->runAction(moveTo);

	auto moveBy = MoveBy::create(this->enemySpeed, Vec2(y - visibleSize.height, x - visibleSize.width));
	sprite->runAction(moveBy);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite);

}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	//Get the position of the current point relative to the button
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	//Check the click area
	if (rect.containsPoint(locationInNode))
	{
		switch (target->getTag())
		{
		case kTagSprite1:
			log("Coin");
			this->coinsGot += 1;
			{
				std::stringstream sb;
				sb << "Coins " << this->coinsGot;
				lblCoins->setString(sb.str());
			}
			break;
		case kTagSprite2:
			log("No Coin!");
			break;
		case kTagSprite5:
			this->restartScene();
			break;
		default:
			break;
		}
		return true;
	}
	return false;
} /* onTouchBegan() */

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	//Todo
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	//Todo
}

void HelloWorld::keyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
	// Restart the scene when pressing key space
	if (EventKeyboard::KeyCode::KEY_SPACE == keyCode) {
		this->restartScene();
	}
}

void HelloWorld::restartScene()
{
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);
}