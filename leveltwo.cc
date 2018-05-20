#include "leveltwo.h"
#include "iblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "lblock.h"

using namespace std;

LevelTwo::LevelTwo(){
}

LevelTwo::LevelTwo(int seed): Level{seed}{}

shared_ptr<Block> LevelTwo::generateBlock() {
	int rand = randGen()%7;
	switch (rand) {
		case 0: return make_shared<IBlock>(2);
		case 1: return make_shared<JBlock>(2);
		case 2: return make_shared<OBlock>(2);
		case 3: return make_shared<SBlock>(2);
		case 4: return make_shared<ZBlock>(2);
		case 5: return make_shared<TBlock>(2);
		case 6: return make_shared<LBlock>(2);
		default: return nullptr;
		}
}

shared_ptr<Block> LevelTwo::generateBlock(char input) {
	switch (input) {
		case 'I': return make_shared<IBlock>(2);
		case 'J': return make_shared<JBlock>(2);
		case 'O': return make_shared<OBlock>(2);
		case 'S': return make_shared<SBlock>(2);
		case 'Z': return make_shared<ZBlock>(2);
		case 'T': return make_shared<TBlock>(2);
		case 'L': return make_shared<LBlock>(2);
		default: return nullptr;
	}
}
