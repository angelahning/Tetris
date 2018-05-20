#include "levelone.h"
#include "iblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "lblock.h"

using namespace std;

LevelOne::LevelOne() {
}

LevelOne::LevelOne(int seed): Level{seed} {
}

shared_ptr<Block> LevelOne:: generateBlock() {
	int rand = randGen()%12;
	if(rand == 0) return make_shared<ZBlock>(1);
	else if(rand == 1) return make_shared<SBlock>(1);
	else if(rand == 2 || rand == 3) return make_shared<TBlock>(1);
	else if(rand == 4 || rand == 5) return make_shared<IBlock>(1);
	else if(rand == 6 || rand == 7) return make_shared<LBlock>(1);
	else if(rand == 8 || rand == 9) return make_shared<OBlock>(1);
	else return make_shared<JBlock>(1);
}

shared_ptr<Block> LevelOne:: generateBlock(char input) {
	switch (input) {
		case 'I': return make_shared<IBlock>(1);
		case 'J': return make_shared<JBlock>(1);
		case 'O': return make_shared<OBlock>(1);
		case 'S': return make_shared<SBlock>(1);
		case 'Z': return make_shared<ZBlock>(1);
		case 'T': return make_shared<TBlock>(1);
		case 'L': return make_shared<LBlock>(1);
		default: return nullptr;
	}
}
