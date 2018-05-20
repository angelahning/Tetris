#include "levelzero.h"
#include "iblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "lblock.h"

using namespace std;

LevelZero:: LevelZero() {}

shared_ptr<Block> LevelZero::generateBlock(char input) {
	switch (input) {
		case 'I': return make_shared<IBlock>(0);
		case 'J': return make_shared<JBlock>(0);
		case 'O': return make_shared<OBlock>(0);
		case 'S': return make_shared<SBlock>(0);
		case 'Z': return make_shared<ZBlock>(0);
		case 'T': return make_shared<TBlock>(0);
		case 'L': return make_shared<LBlock>(0);
		default: return nullptr;
	}
}
shared_ptr<Block> LevelZero::generateBlock() {
	return nullptr;
};
