//
//  Creature.cpp
//  CocosProject1
//
//  Created by Marco Matascioli on 05/01/2016.
//
//

#include "Creature.hpp"

using namespace cocos2d;

bool Creature::init()
{
    if (! Sprite::initWithFile("Assets/SpriteImages/bubble.png"))
    {
        return false;
    }
    
    this->setLivingNeighborsCount(0);
    this->setIsAlive(false);
    
    return true;
}

void Creature::setLivingNeighborsCount(int livingNeighborsCount)
{
    this->livingNeighborsCount = livingNeighborsCount;
}

int Creature::getLivingNeighborsCount()
{
    return this->livingNeighborsCount;
}

void Creature::setIsAlive(bool isAlive)
{
    this->isAlive = isAlive;
    this->setVisible(isAlive);
}

bool Creature::getIsAlive()
{
    return this->isAlive;
}