#include "level.h"
#include <cstdlib>

using namespace std;

//level constructor
Level::Level() {
	//srand takes unsigned int as argument(seed); if seed not specified, set to -1
	seed = 1;
}

//level constructor based on seed
Level::Level(int seed): seed{seed} {}

//public generate Block function
shared_ptr<Block> Level::doGenerate() {
	return generateBlock();
}

//overload public generate Block function based on input
shared_ptr<Block> Level::doGenerate(char input) {
	return generateBlock(input);
}

//default level destructor
Level::~Level() {}

//random generate seed
int Level::randGen() {
	srand(seed);
	++seed;
	return rand();
}
