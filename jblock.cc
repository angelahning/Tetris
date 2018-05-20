#include <algorithm>
#include "jblock.h"

using namespace std;

//JBlock Constructor
JBlock::JBlock(int level):Block('J', level) {}

//JBlock rotate
void JBlock::rotate(char dir) {
  const int wide = 11;
  if(dir == 'r') {
    int size = component.size();
    if(size == 2) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      int end1 = 0;
      int end2 = 0;
      int numCell1 = 0;
      int numCell2 = 0;
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if((cells1[i + 1]->isEmpty()) && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if(!(cells1[i]->isEmpty())) {
          numCell1++;
        }
      }
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if((cells2[i + 1]->isEmpty()) && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if(!(cells2[i]->isEmpty())) {
          numCell2++;
        }
      }
      int start1 = end1 - (numCell1 - 1);
      int start2 = end2 - (numCell2 - 1);
      if(start1 == start2) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent(start1, start1 + 1, 'J');
        (component[1])->setContent(start1, start1, 'J');
        auto l = make_shared<Line>();
        l->setContent(start1, start1, 'J');
        component.emplace_back(l);
        topPos -= 1;
        rightEnd -= 1;
      } else if(end1 == end2) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent(start1 + 1, start1 + 1, 'J');
        (component[1])->setContent(start1 + 1, start1 + 1, 'J');
        auto l = make_shared<Line>();
        l->setContent(start1, start1 + 1, 'J');
        component.emplace_back(l);
        topPos -= 1;
        rightEnd -= 1;
      }
    } else if(size == 3) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
      int end1 = 0;
      int end2 = 0;
      int end3 = 0;
      int numCell1 = 0;
      int numCell2 = 0;
      int numCell3 = 0;
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if((cells1[i + 1]->isEmpty()) && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if(!(cells1[i]->isEmpty())) {
          numCell1++;
        }
      }
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if((cells2[i + 1]->isEmpty()) && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if(!(cells2[i]->isEmpty())) {
          numCell2++;
        }
      }
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells3[i]->isEmpty()))) {
          end3 = i;
          numCell3++;
          break;
        } else if((cells3[i + 1]->isEmpty()) && (!(cells3[i]->isEmpty()))) {
          end3 = i;
          numCell3++;
          break;
        } else if(!(cells3[i]->isEmpty())) {
          numCell3++;
        }
      }
      int start1 = end1 - (numCell1 - 1);
      int start2 = end2 - (numCell2 - 1);
      int start3 = end3 - (numCell3 - 1);
      if(start1 == start2 && start2 == start3) {
        if(end1 < 10) {
          (component[0])->clearContent();
          (component[1])->clearContent();
          (component[2])->clearContent();
          component.pop_back();
          (component[0])->setContent(start1, start1 + 2, 'J');
          (component[1])->setContent(start1 + 2, start1 + 2, 'J');
          topPos += 1;
          rightEnd += 1;
        } else {
          return;
        }
      } else if(end1 == end2 && end2 == end3) {
        if(end1 < 10) {
          (component[0])->clearContent();
          (component[1])->clearContent();
          (component[2])->clearContent();
          component.pop_back();
          (component[0])->setContent(start3, start3, 'J');
          (component[1])->setContent(start3, start3 + 2, 'J');
          topPos += 1;
          rightEnd += 1;
        } else {
          return;
        }
      }
    }
  } else if(dir == 'l') {
    int size = component.size();
    if(size == 2) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      int end1 = 0;
      int end2 = 0;
      int numCell1 = 0;
      int numCell2 = 0;
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if((cells1[i + 1]->isEmpty()) && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if(!(cells1[i]->isEmpty())) {
          numCell1++;
        }
      }
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if((cells2[i + 1]->isEmpty()) && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if(!(cells2[i]->isEmpty())) {
          numCell2++;
        }
      }
      int start1 = end1 - (numCell1 - 1);
      int start2 = end2 - (numCell2 - 1);
      if(start1 == start2) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent(start1 + 1, start1 + 1, 'J');
        (component[1])->setContent(start1 + 1, start1 + 1, 'J');
        auto l = make_shared<Line>();
        l->setContent(start1, start1 + 1, 'J');
        component.emplace_back(l);
        topPos -= 1;
        rightEnd -= 1;
      } else if(end1 == end2) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent(start1, start1 + 1, 'J');
        (component[1])->setContent(start1, start1, 'J');
        auto l = make_shared<Line>();
        l->setContent(start1, start1, 'J');
        component.emplace_back(l);
        topPos -= 1;
        rightEnd -= 1;
      }
    } else if(size == 3) {
      vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
      vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
      vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
      int end1 = 0;
      int end2 = 0;
      int end3 = 0;
      int numCell1 = 0;
      int numCell2 = 0;
      int numCell3 = 0;
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if((cells1[i + 1]->isEmpty()) && (!(cells1[i]->isEmpty()))) {
          end1 = i;
          numCell1++;
          break;
        } else if(!(cells1[i]->isEmpty())) {
          numCell1++;
        }
      }
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if((cells2[i + 1]->isEmpty()) && (!(cells2[i]->isEmpty()))) {
          end2 = i;
          numCell2++;
          break;
        } else if(!(cells2[i]->isEmpty())) {
          numCell2++;
        }
      }
      for(int i = 0; i < wide; i++) {
        if(i == 10 && (!(cells3[i]->isEmpty()))) {
          end3 = i;
          numCell3++;
          break;
        } else if((cells3[i + 1]->isEmpty()) && (!(cells3[i]->isEmpty()))) {
          end3 = i;
          numCell3++;
          break;
        } else if(!(cells3[i]->isEmpty())) {
          numCell3++;
        }
      }
      int start1 = end1 - (numCell1 - 1);
      int start2 = end2 - (numCell2 - 1);
      int start3 = end3 - (numCell3 - 1);
      if(start1 == start2 && start2 == start3) {
        if(end1 < 10) {
          (component[0])->clearContent();
          (component[1])->clearContent();
          (component[2])->clearContent();
          component.pop_back();
          (component[0])->setContent(start1, start1, 'J');
          (component[1])->setContent(start1, start1 + 2, 'J');
          topPos += 1;
          rightEnd += 1;
        } else {
          return;
        }
      } else if(end1 == end2 && end2 == end3) {
        if(end1 < 10) {
          (component[0])->clearContent();
          (component[1])->clearContent();
          (component[2])->clearContent();
          component.pop_back();
          (component[0])->setContent(start3, start3 + 2, 'J');
          (component[1])->setContent(start3 + 2, start3 + 2, 'J');
          topPos += 1;
          rightEnd += 1;
        } else {
          return;
        }
      }
    }
  } else {
    return;
  }
}

//JBlock move
void JBlock::move(char dir) {
  const int wide = 11;
  int size = component.size();
  if(size == 2) {
    vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
    vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
    int end1 = 0;
    int end2 = 0;
    int numCell1 = 0;
    int numCell2 = 0;
    for(int i = 0; i < wide; i++) {
      if(i == 10 && (!(cells1[i]->isEmpty()))) {
        end1 = i;
        numCell1++;
        break;
      } else if((cells1[i + 1]->isEmpty()) && (!(cells1[i]->isEmpty()))) {
        end1 = i;
        numCell1++;
        break;
      } else if(!(cells1[i]->isEmpty())) {
        numCell1++;
      }
    }
    for(int i = 0; i < wide; i++) {
      if(i == 10 && (!(cells2[i]->isEmpty()))) {
        end2 = i;
        numCell2++;
        break;
      } else if((cells2[i + 1]->isEmpty()) && (!(cells2[i]->isEmpty()))) {
        end2 = i;
        numCell2++;
        break;
      } else if(!(cells2[i]->isEmpty())) {
        numCell2++;
      }
    }
    int start1 = end1 - (numCell1 - 1);
    int start2 = end2 - (numCell2 - 1);
    int start = min(start1, start2);
    int end = max(end1, end2);
    if(dir == 'l') {
      if((start - 1) >= 0) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent((start1 - 1), (end1 - 1), 'J');
        (component[1])->setContent((start2 - 1), (end2 - 1), 'J');
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if((end + 1) < wide) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[0])->setContent((start1 + 1), (end1 + 1), 'J');
        (component[1])->setContent((start2 + 1), (end2 + 1), 'J');
        leftEnd += 1;
        rightEnd += 1;
      } else {
        return;
      }
    } else {
      return;
    }
  } else {
    vector<shared_ptr<Cell>> cells1 = (component[0])->getContent();
    vector<shared_ptr<Cell>> cells2 = (component[1])->getContent();
    vector<shared_ptr<Cell>> cells3 = (component[2])->getContent();
    int end1 = 0;
    int end2 = 0;
    int end3 = 0;
    int numCell1 = 0;
    int numCell2 = 0;
    int numCell3 = 0;
    for(int i = 0; i < wide; i++) {
      if(i == 10 && (!(cells1[i]->isEmpty()))) {
        end1 = i;
        numCell1++;
        break;
      } else if((cells1[i + 1]->isEmpty()) && (!(cells1[i]->isEmpty()))) {
        end1 = i;
        numCell1++;
        break;
      } else if(!(cells1[i]->isEmpty())) {
        numCell1++;
      }
    }
    for(int i = 0; i < wide; i++) {
      if(i == 10 && (!(cells2[i]->isEmpty()))) {
        end2 = i;
        numCell2++;
        break;
      } else if((cells2[i + 1]->isEmpty()) && (!(cells2[i]->isEmpty()))) {
        end2 = i;
        numCell2++;
        break;
      } else if(!(cells2[i]->isEmpty())) {
        numCell2++;
      }
    }
    for(int i = 0; i < wide; i++) {
      if(i == 10 && (!(cells3[i]->isEmpty()))) {
        end3 = i;
        numCell3++;
        break;
      } else if((cells3[i + 1]->isEmpty()) && (!(cells3[i]->isEmpty()))) {
        end3 = i;
        numCell3++;
        break;
      } else if(!(cells3[i]->isEmpty())) {
        numCell3++;
      }
    }
    int start1 = end1 - (numCell1 - 1);
    int start2 = end2 - (numCell2 - 1);
    int start3 = end3 - (numCell3 - 1);
    int start = min3(start1, start2, start3);
    int end = max3(end1, end2, end3);
    if(dir == 'l') {
      if((start - 1) >= 0) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        (component[0])->setContent((start1 - 1), (end1 - 1), 'J');
        (component[1])->setContent((start2 - 1), (end2 - 1), 'J');
        (component[2])->setContent((start3 - 1), (end3 - 1), 'J');
        leftEnd -= 1;
        rightEnd -= 1;
      } else {
        return;
      }
    } else if(dir == 'r') {
      if((end + 1) < wide) {
        (component[0])->clearContent();
        (component[1])->clearContent();
        (component[2])->clearContent();
        (component[0])->setContent((start1 + 1), (end1 + 1), 'J');
        (component[1])->setContent((start2 + 1), (end2 + 1), 'J');
        (component[2])->setContent((start3 + 1), (end3 + 1), 'J');
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
