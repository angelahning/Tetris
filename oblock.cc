#include "oblock.h"

using namespace std;

//OBlock consturctor
OBlock::OBlock(int level):Block('O', level) {}

//OBlock rotate
void OBlock::rotate(char dir) {
  return;
}

//OBlock move
void OBlock::move(char dir) {
  const int wide = 11;
  vector<shared_ptr<Cell>> cells = (component[0])->getContent();
  int start = 0;
  for(int i = 0; i < wide; i++) {
    if(!(cells[i]->isEmpty())) {
      start = i;
      break;
    }
  }
  int end = start + 1;
  if(dir == 'l') {
    if((start - 1) >= 0) {
      for(int i = 0; i < 2; i++) {
        (component[i])->clearContent();
        (component[i])->setContent(start - 1, end - 1, 'O');
      }
    } else {
      return;
    }
  } else if(dir == 'r') {
    if((end + 1) < wide) {
      for(int i = 0; i < 2; i++) {
        (component[i])->clearContent();
        (component[i])->setContent(start + 1, end + 1, 'O');
      }
    } else {
      return;
    }
  } else {
    return;
  }
}
