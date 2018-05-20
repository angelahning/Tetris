#include "levelthree.h"
#include "iblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "lblock.h"

using namespace std;

LevelThree::LevelThree(){
}

LevelThree::LevelThree(int seed): Level{seed}{}

shared_ptr<Block> LevelThree::generateBlock() {
	int rand = randGen()%9;
	switch (rand) {
		case 0: return make_shared<IBlock>(3);
		case 1: return make_shared<JBlock>(3);
		case 2: return make_shared<OBlock>(3);
		case 3: return make_shared<SBlock>(3);
		case 4: return make_shared<SBlock>(3);
		case 5: return make_shared<ZBlock>(3);
		case 6: return make_shared<ZBlock>(3);
		case 7: return make_shared<TBlock>(3);
		case 8: return make_shared<LBlock>(3);
		default: return nullptr;
		}
}

shared_ptr<Block> LevelThree::generateBlock(char input) {
	switch (input) {
		case 'I': return make_shared<IBlock>(3);
		case 'J': return make_shared<JBlock>(3);
		case 'O': return make_shared<OBlock>(3);
		case 'S': return make_shared<SBlock>(3);
		case 'Z': return make_shared<ZBlock>(3);
		case 'T': return make_shared<TBlock>(3);
		case 'L': return make_shared<LBlock>(3);
		default: return nullptr;
	}
}
