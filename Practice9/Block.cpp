//
// Created by cocol on 02/05/2022.
//

#include "Block.h"
#include "sstream"

std::string Block::getDescription() {
    std::stringstream ss;
    ss<< getNumberOfPiledElements();
    std::string a = "Building block (" + ss.str() +')';
    return a;
}

Block::Block(): ItemApilable() {}

Block::Block(int numberOfElements) : ItemApilable(numberOfElements) {}

Block::Block(const std::string &description) : _description(description) {}

Block::Block(const std::string &description,int numberOfElements ) : ItemApilable(numberOfElements),
                                                                     _description(description) {}

Block::~Block() {

}
