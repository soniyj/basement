//
//  Creature.hpp
//  CocosProject1
//
//  Created by Marco Matascioli on 05/01/2016.
//
//

#ifndef __Creature_hpp__
#define __Creature_hpp__

#include "cocos2d.h"

class Creature : public cocos2d::Sprite
{
public:
    
    CREATE_FUNC(Creature);
    
    bool init() override;

    void setLivingNeighborsCount(int livingNeighborsCount);
    int getLivingNeighborsCount();
    
    void setIsAlive(bool isAlive);
    bool getIsAlive();
    
protected:
    
    int livingNeighborsCount;
    bool isAlive;
};

#endif /* Creature_hpp */
