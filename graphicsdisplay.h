#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"
#include "cell.h"
#include "block.h"

class GraphicsDisplay: public Observer {
  //set constant varaible
  const int width = 395;
  const int height = 380;
  const int board_left = 115;
  const int board_right = 280;
  const int cellSize = 15;
  const int row = 18;
  const int colomn = 11;
  const int boardWidth = cellSize * colomn;
  const int boardHeight = cellSize * colomn;
  //link the window
  Xwindow xw;
  //remember the line
  std::vector<std::vector<char>> theDisplay;
  void notify(Subject &whoNotified) override; //as an observer, GraphicsDisplay keep track the line and send the notification to the display
 public:
  GraphicsDisplay(); //GraphicsDisplay constructor
  void drawLevel(int level); //draw the up current Level on the display
  void drawScore(int score); //draw the up current Score on the display
  void drawHighScore(int high_score); //draw the up current High Score on the display
  void drawHold(std::shared_ptr<Block> b); //Extra feature: draw the holding block on the display
  void drawNext(std::shared_ptr<Block> b); //draw the up comming block on the display
  void endGame(); //print endGame message
};


#endif
