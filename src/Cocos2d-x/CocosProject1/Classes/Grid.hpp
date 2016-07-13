//
//  Grid.hpp
//  CocosProject1
//
//  Created by Marco Matascioli on 05/01/2016.
//
//

#ifndef __Grid_hpp__
#define __Grid_hpp__

#include "cocos2d.h"
#include "Creature.hpp"

class Grid : public cocos2d::Node
{
public:
    CREATE_FUNC(Grid);
    
    bool init() override;
    
    void onEnter() override;
    
    void evolveStep();
    
    int getGenerationCount();
    
    int getPopulationCount();
    
protected:
    int generationCount;
    int populationCount;
    float cellWidth;
    float cellHeight;
    cocos2d::Vector<Creature*> gridArray;
    
    void setupGrid();
    void setupTouchHandling();
    void updateNeighborCount();
    void updateCreatures();
    Creature* creatureForTouchLocation(cocos2d::Vec2 touchLocation);
    bool isValidIndex(int row, int col);
    int indexForRowColumn(int row, int col);
};

#endif /* Grid_hpp */
