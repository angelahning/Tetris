#ifndef _LEVELONE_H
#define _LEVELONE_H

#include "level.h"
#include "block.h"

class LevelOne: public Level {
	std::shared_ptr<Block> generateBlock() override;
	std::shared_ptr<Block> generateBlock(char) override;
public:
	LevelOne(int seed);
	LevelOne();	
};
#endif

