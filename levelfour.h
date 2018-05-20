#ifndef _LF_H
#define _LF_H
#include "block.h"
#include "level.h"
#include <memory>

class LevelFour: public Level {
	std::shared_ptr<Block> generateBlock() override;
	std::shared_ptr<Block> generateBlock(char) override;
public:
	LevelFour();
	LevelFour(int);
	std::shared_ptr<Block> genStarBlock();
};
#endif
