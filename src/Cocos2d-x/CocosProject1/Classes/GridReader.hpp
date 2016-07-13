//
//  GridReader.hpp
//  CocosProject1
//
//  Created by Marco Matascioli on 05/01/2016.
//
//

#ifndef __GridReader_hpp__
#define __GridReader_hpp__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class GridReader : public cocostudio::NodeReader
{
public:
    static GridReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* GridReader_hpp */
