#ifndef _LTH_H
#define _LTH_H
#include "block.h"
#include "level.h"
#include <memory>

class LevelThree: public Level {
	std::shared_ptr<Block> generateBlock() override;
	std::shared_ptr<Block> generateBlock(char) override;
public:
	LevelThree();
	LevelThree(int);
};
#endif
