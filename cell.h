#ifndef _CELL_H_
#define _CELL_H_

class Cell{
  char type;
  bool active;
  bool hint;
public:
  Cell(); //cell constructor
  Cell(const Cell &other); //cell copy constructor
  Cell(Cell &&other); //cell move consturctor
  Cell &operator=(const Cell &other); //cell copy assignment
  Cell &operator=(Cell &&other); //cell move assignment
  void setType(char type); //setter function that set current cell to type
  void setEmpty(); //clear(empty) the current cell
  char getType(); //getter function that get current cell type
  bool isEmpty(); //predicate function that check if the current cell is empty or not
  void setHint(); //setter function that set current cell to hint type
  bool isHint(); //preticate function that check if cell is hint cell
  void setActive(); //set current cell active
  bool isActive(); //predicate function that check if the current cell is active or not
  void setInactive(); //set current cell inactive
};

#endif
