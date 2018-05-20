#ifndef _LEVELZERO_H
#define _LEVELZERO_H

#include "level.h"
#include <memory>
class Block;

class LevelZero: public Level {
    std::shared_ptr<Block> generateBlock() override;
    std::shared_ptr<Block> generateBlock(char) override;
public:
    LevelZero();
};
#endif

