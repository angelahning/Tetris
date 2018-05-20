#include "iblock.h"

using namespace std;

//IBlock constructor
IBlock::IBlock(int level):Block('I', level) {}

//IBlock rotate
void IBlock::rotate(char dir) {
  const int wide = 11;
  int size = component.size();
  int start = 0;
  vector<shared_ptr<Cell>> cells = (component[0])->getContent();
  for(int i = 0; i < wide; i++) {
    if(!(cells[i]->isEmpty())) {
      start = i;
      break;
    }
  }
  if(size == 1) {
    if(dir == 'r') {
      (component[0])->clearContent();
      (component[0])->setContent(start, start, 'I');
      auto l1 = make_shared<Line>();
      l1->setContent(start, start, 'I');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(start, start, 'I');
      component.emplace_back(l2);
      auto l3 = make_shared<Line>();
      l3->setContent(start, start, 'I');
      component.emplace_back(l3);
      topPos -= 3;
      bottomPos = bottomPos;
      leftEnd = leftEnd;
      rightEnd = leftEnd;
    } else if(dir == 'l') {
      (component[0])->clearContent();
      (component[0])->setContent(start, start, 'I');
      auto l1 = make_shared<Line>();
      l1->setContent(start, start, 'I');
      component.emplace_back(l1);
      auto l2 = make_shared<Line>();
      l2->setContent(start, start, 'I');
      component.emplace_back(l2);
      auto l3 = make_shared<Line>();
      l3->setContent(start, start, 'I');
      component.emplace_back(l3);
      topPos -= 3;
      bottomPos = bottomPos;
      leftEnd = leftEnd;
      rightEnd = leftEnd;
    } else {
      return;
    }
  } else {
    if(dir == 'r') {
      if(0 <= start && start < 8) {
        for(int i = 0; i < 4; i++) {
          component.pop_back();
        }
        auto l1 = make_shared<Line>();
        l1->setContent(start, start + 3, 'I');
        component.emplace_back(l1);
        topPos = bottomPos;
        bottomPos = bottomPos;
        leftEnd = leftEnd;
        rightEnd = leftEnd + 3;
      } else {
        return;
      }
    } else if(dir == 'l') {
      if(0 <= start && start < 8) {
        for(int i = 0; i < 4; i++) {
          component.pop_back();
        }
        auto l1 = make_shared<Line>();
        l1->setContent(start, start + 3, 'I');
        component.emplace_back(l1);
        topPos = bottomPos;
        bottomPos = bottomPos;
        leftEnd = leftEnd;
        rightEnd = leftEnd + 3;
      } else {
        return;
      }
    } else {
      return;
    }
  }
}

//IBlock move
void IBlock::move(char dir) {
  const int wide = 11;
  int size = component.size();
  int start = 0;
  int end = 0;
  vector<shared_ptr<Cell>> cells = (component[0])->getContent();
  for(int i = 0; i < wide; i++) {
    if(!(cells[i]->isEmpty())) {
      start = i;
      break;
    }
  }
  if(size == 1) {
    end += (start + 3);
    if(dir == 'l') {
      if((start - 1) >= 0) {
        (component[0])->clearContent();
        (component[0])->setContent((start - 1), (end - 1), 'I');
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if((end + 1) < wide) {
        (component[0])->clearContent();
        (component[0])->setContent((start + 1), (end + 1), 'I');
        leftEnd += 1;
        rightEnd += 1;
      } else {
        return;
      }
    } else {
      return;
    }
  } else {
    end = start;
    if(dir == 'l') {
      if((start - 1) >= 0) {
        for(int i = 0; i < size; i++) {
          (component[i])->clearContent();
        }
        for(int i = 0; i < size; i++) {
          (component[i])->setContent((start - 1), (end - 1), 'I');
        }
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if((end + 1) < wide) {
        for(int i = 0; i < size; i++) {
          (component[i])->clearContent();
        }
        for(int i = 0; i < size; i++) {
          (component[i])->setContent((start + 1), (end + 1), 'I');
        }
        leftEnd += 1;
        rightEnd += 1;
      } else {
        return;
      }
    } else {
      return;
    }
  }
}
