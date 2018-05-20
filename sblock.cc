#include "sblock.h"

using namespace std;

//SBlock constructor
SBlock::SBlock(int level):Block('S', level) {}

//SBlock rotate
void SBlock::rotate(char dir) {
  if(dir == 'r') {
    int size = component.size();
    if(size == 2) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      int start1 = leftEnd + 1;
      int start2 = leftEnd;
      int end2 = start2 + 1;
      (component[0])->clearContent();
      (component[1])->clearContent();
      (component[0])->setContent(start2, start2, 'S');
      (component[1])->setContent(start2, end2, 'S');
      auto l = make_shared<Line>();
      l->setContent(start1, start1, 'S');
      component.emplace_back(l);
      topPos -= 1;
      rightEnd -= 1;
    } else if(size == 3) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
      int start2 = leftEnd;
      int end2 = rightEnd;
      if(end2 < 10) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        component.pop_back();
        (component[0])->setContent(end2, end2 + 1, 'S');
        (component[1])->setContent(start2, end2, 'S');
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
      int start1 = leftEnd + 1;
      int start2 = leftEnd;
      (component[0])->clearContent();
      (component[1])->clearContent();
      (component[0])->setContent(start2, start2, 'S');
      (component[1])->setContent(start2, start2 + 1, 'S');
      auto l = make_shared<Line>();
      l->setContent(start1, start1, 'S');
      component.emplace_back(l);
      topPos -= 1;
      rightEnd -= 1;
    } else if(size == 3) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
      int start1 = leftEnd;
      int end2 = rightEnd;
      int start3 = leftEnd + 1;
      if(end2 < 10) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        component.pop_back();
        (component[0])->setContent(start3, start3 + 1, 'S');
        (component[1])->setContent(start1, start1 + 1, 'S');
        topPos += 1;
        rightEnd += 1;
      } else {
        return;
      }
    }
  } else {
    return;
  }
}

//SBlock move
void SBlock::move(char dir) {
  const int wide = 11;
  int size = component.size();
  if(size == 2) {
    vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
    vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
    int start1 = leftEnd + 1;
    int end1 = start1 + 1;
    int start2 = leftEnd;
    int end2 = start2 + 1;
    if(dir == 'l') {
      if(start2 - 1 >= 0) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent((start1 - 1), (end1 - 1), 'S');
        (component[1])->setContent((start2 - 1), (end2 - 1), 'S');
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if(end1 + 1 < wide) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent((start1 + 1), (end1 + 1), 'S');
        (component[1])->setContent((start2 + 1), (end2 + 1), 'S');
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
    int start1 = leftEnd;
    int end1 = start1;
    int start2 = leftEnd;
    int end2 = rightEnd;
    int start3 = leftEnd + 1;
    int end3 = leftEnd + 1;
    if(dir == 'l') {
      if((start2 - 1) >= 0) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        (component[0])->setContent((start1 - 1), (end1 - 1), 'S');
        (component[1])->setContent((start2 - 1), (end2 - 1), 'S');
        (component[2])->setContent((start3 - 1), (end3 - 1), 'S');
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
        (component[0])->setContent((start1 + 1), (end1 + 1), 'S');
        (component[1])->setContent((start2 + 1), (end2 + 1), 'S');
        (component[2])->setContent((start3 + 1), (end3 + 1), 'S');
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
