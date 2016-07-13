//
//  GridReader.cpp
//  CocosProject1
//
//  Created by Marco Matascioli on 05/01/2016.
//
//

#include "GridReader.hpp"
#include "Grid.hpp"

using namespace cocos2d;

//This is all boilerplate code whenever Reader class code will be the same

static GridReader* _instanceGridReader = nullptr;

GridReader* GridReader::getInstance()
{
    if (!_instanceGridReader)
    {
        _instanceGridReader = new GridReader();
    }
    return _instanceGridReader;
}

void GridReader::purge()
{
    CC_SAFE_DELETE(_instanceGridReader);
}

Node* GridReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    Grid* node = Grid::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}