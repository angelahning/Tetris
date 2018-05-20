#ifndef _LEVEL_H
#define _LEVEL_H
#include <memory>

//forward declarate related class
class Block;

class Level {
    int seed;
    virtual std::shared_ptr<Block> generateBlock() = 0;
    virtual std::shared_ptr<Block> generateBlock(char) = 0;
public:
    Level(); //level constructor
    std::shared_ptr<Block> doGenerate(); //public generate Block function
    std::shared_ptr<Block> doGenerate(char); //overload public generate Block function based on input
    Level(int num); //level constructor based on num
    int randGen(); //random generate seed
    virtual ~Level(); //default level destructor
};

#endif
