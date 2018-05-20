#include "zblock.h"

using namespace std;

//ZBlock constructor
ZBlock::ZBlock(int level):Block('Z', level) {}

//ZBlock rotate
void ZBlock::rotate(char dir) {
  //const int wide = 11;
  if(dir == 'r') {
    int size = component.size();
    if(size == 2) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      int start1 = leftEnd;
      (component[0])->clearContent();
      (component[1])->clearContent();
      (component[0])->setContent(start1 + 1, start1 + 1, 'Z');
      (component[1])->setContent(start1, start1 + 1, 'Z');
      auto l = make_shared<Line>();
      l->setContent(start1, start1, 'Z');
      component.emplace_back(l);
      topPos -= 1;
      rightEnd -= 1;
    } else if(size == 3) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
      int start1 = leftEnd + 1;
      int end1 = start1;
      int start2 = leftEnd;
      int end2 = rightEnd;
      if(end1 < 10) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        component.pop_back();
        (component[0])->setContent(start2, end2, 'Z');
        (component[1])->setContent(end2, end2 + 1, 'Z');
        topPos += 1;
        rightEnd += 1;
      } else {
        return;
      }
    }
  } else if(dir == 'l') {
    int size = component.size();
    if(size == 2) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      int start1 = leftEnd;
      (component[0])->clearContent();
      (component[1])->clearContent();
      (component[0])->setContent(start1 + 1, start1 + 1, 'Z');
      (component[1])->setContent(start1, start1 + 1, 'Z');
      auto l = make_shared<Line>();
      l->setContent(start1, start1, 'Z');
      component.emplace_back(l);
      topPos -= 1;
      rightEnd -= 1;
    } else if(size == 3) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
      int start1 = leftEnd + 1;
      int end1 = start1;
      int start2 = leftEnd;
      int end2 = rightEnd;
      if(end1 < 10) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        component.pop_back();
        (component[0])->setContent(start2, end2, 'Z');
        (component[1])->setContent(end2, end2 + 1, 'Z');
        topPos += 1;
        rightEnd += 1;
      } else {
        return;
      }
    }
  }
}

//ZBlock move
void ZBlock::move(char dir) {
  const int wide = 11;
  int size = component.size();
  if(size == 2) {
    vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
    vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
    int start1 = leftEnd;
    int end1 = start1 + 1;
    int start2 = end1;
    int end2 = rightEnd;
    if(dir == 'l') {
      if(start1 - 1 >= 0) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent((start1 - 1), (end1 - 1), 'Z');
        (component[1])->setContent((start2 - 1), (end2 - 1), 'Z');
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if(end2 + 1 < wide) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent((start1 + 1), (end1 + 1), 'Z');
        (component[1])->setContent((start2 + 1), (end2 + 1), 'Z');
        leftEnd += 1;
        rightEnd += 1;
      } else {
        return;
      }
    } else {
      return;
    }
  } else if(size == 3) {
    vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
    vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
    vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
    int start1 = leftEnd + 1;
    int end1 = start1;
    int start2 = leftEnd;
    int end2 = rightEnd;
    int start3 = leftEnd;
    int end3 = start3;
    if(dir == 'l') {
      if((start2 - 1) >= 0) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        (component[0])->setContent((start1 - 1), (end1 - 1), 'Z');
        (component[1])->setContent((start2 - 1), (end2 - 1), 'Z');
        (component[2])->setContent((start3 - 1), (end3 - 1), 'Z');
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if((end2 + 1) < wide) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        (component[0])->setContent((start1 + 1), (end1 + 1), 'Z');
        (component[1])->setContent((start2 + 1), (end2 + 1), 'Z');
        (component[2])->setContent((start3 + 1), (end3 + 1), 'Z');
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
