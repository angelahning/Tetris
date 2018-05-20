#ifndef _LT_H
#define _LT_H
#include <memory>
#include "block.h"
#include "level.h"

class LevelTwo: public Level{
	std::shared_ptr<Block> generateBlock() override;
	std::shared_ptr<Block> generateBlock(char) override;
public:
	LevelTwo();
	LevelTwo(int);
};

#endif
