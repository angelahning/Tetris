#include "levelfour.h"
#include "starblock.h"
#include "iblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "lblock.h"


using namespace std;

//level four constructor
LevelFour::LevelFour(){}

 //level four constructor based on seed
LevelFour::LevelFour(int seed): Level{seed}{}


shared_ptr<Block> LevelFour::generateBlock() {
	int rand = randGen()%9;
	switch (rand) {
		case 0: return make_shared<IBlock>(4);
		case 1: return make_shared<JBlock>(4);
		case 2: return make_shared<OBlock>(4);
		case 3: return make_shared<SBlock>(4);
		case 4: return make_shared<SBlock>(4);
		case 5: return make_shared<ZBlock>(4);
		case 6: return make_shared<ZBlock>(4);
		case 7: return make_shared<TBlock>(4);
		case 8: return make_shared<LBlock>(4);
		default: return nullptr;
		}
}


shared_ptr<Block> LevelFour::genStarBlock() {
	return make_shared<StarBlock>(0);
}


shared_ptr<Block> LevelFour::generateBlock(char input) {
	switch (input) {
		case 'I': return make_shared<IBlock>(4);
		case 'J': return make_shared<JBlock>(4);
		case 'O': return make_shared<OBlock>(4);
		case 'S': return make_shared<SBlock>(4);
		case 'Z': return make_shared<ZBlock>(4);
		case 'T': return make_shared<TBlock>(4);
		case 'L': return make_shared<LBlock>(4);
		default: return nullptr;
	}
}
