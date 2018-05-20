#include <iostream>
#include "graphicsdisplay.h"
#include "subject.h"

using namespace std;

//GraphicsDisplay constructor
GraphicsDisplay::GraphicsDisplay(): xw{width, height} {
  vector<char> row(11, ' ');
	for(int i = 0 ; i < 18; i++) {
		theDisplay.emplace_back(row);
	}
  //init the play interface on the display at the first time
  xw.fillRectangle(0, 0, 110, height, Xwindow::Orange);
  xw.fillRectangle(110, 0, 5, height, Xwindow::White);
  xw.fillRectangle(115, 0, boardWidth, 70, Xwindow::Orange);
  xw.fillRectangle(115, 70, boardWidth, 5, Xwindow::White);
  xw.fillRectangle(115, 75, boardWidth, boardHeight, Xwindow::White);
  xw.fillRectangle(110, 345, 5 + boardWidth + 5, 45, Xwindow::Orange);
  xw.fillRectangle(280, 0, 5, 340, Xwindow::White);
  xw.fillRectangle(285, 0, 110, height, Xwindow::Orange);
  xw.drawString(125, 20, "Level: ", Xwindow::Black);
  xw.drawString(125, 40, "Score: ", Xwindow::Black);
  xw.drawString(125, 60, "Hi Score: ", Xwindow::Black);
  xw.drawBigString(18, 100, "HOLD", Xwindow::Black);
  xw.drawBigString(305, 100, "NEXT", Xwindow::Black);
  xw.fillRectangle(10, 105, 90, 90, Xwindow::White);
  xw.fillRectangle(295, 105, 90, 90, Xwindow::White);
}

//Extra feature: draw the holding block on the display
void GraphicsDisplay::drawHold(std::shared_ptr<Block> b) {
  xw.fillRectangle(10, 105, 90, 90, Xwindow::White);
  char character = b->getType();
  switch(character) {
   case 'I':
    xw.fillRectangle(25, 135, cellSize * 4, cellSize, Xwindow::Blue);
    break;
   case 'J':
    xw.fillRectangle(40, 135, cellSize, cellSize, Xwindow::Yellow);
    xw.fillRectangle(40, 150, cellSize * 3, cellSize, Xwindow::Yellow);
    break;
   case 'L':
    xw.fillRectangle(70, 135, cellSize, cellSize, Xwindow::Magenta);
    xw.fillRectangle(40, 150, cellSize * 3, cellSize, Xwindow::Magenta);
    break;
   case 'O':
    xw.fillRectangle(40, 135, cellSize * 2, cellSize * 2, Xwindow::Green);
    break;
   case 'S':
    xw.fillRectangle(55, 135, cellSize * 2, cellSize, Xwindow::Red);
    xw.fillRectangle(40, 150, cellSize * 2, cellSize, Xwindow::Red);
    break;
   case 'Z':
    xw.fillRectangle(40, 135, cellSize * 2, cellSize, Xwindow::Cyan);
    xw.fillRectangle(55, 150, cellSize * 2, cellSize, Xwindow::Cyan);
    break;
   case 'T':
    xw.fillRectangle(40, 135, cellSize * 3, cellSize, Xwindow::Brown);
    xw.fillRectangle(55, 150, cellSize, cellSize, Xwindow::Brown);
    break;
  }
}

//draw the up comming block on the display
void GraphicsDisplay::drawNext(shared_ptr<Block> b) {
  xw.fillRectangle(295, 105, 90, 90, Xwindow::White);
  char character = b->getType();
  switch(character) {
   case 'I':
    xw.fillRectangle(310, 135, cellSize * 4, cellSize, Xwindow::Blue);
    break;
   case 'J':
    xw.fillRectangle(310, 135, cellSize, cellSize, Xwindow::Yellow);
    xw.fillRectangle(310, 150, cellSize * 3, cellSize, Xwindow::Yellow);
    break;
   case 'L':
    xw.fillRectangle(340, 135, cellSize, cellSize, Xwindow::Magenta);
    xw.fillRectangle(310, 150, cellSize * 3, cellSize, Xwindow::Magenta);
    break;
   case 'O':
    xw.fillRectangle(325, 135, cellSize * 2, cellSize * 2, Xwindow::Green);
    break;
   case 'S':
    xw.fillRectangle(325, 135, cellSize * 2, cellSize, Xwindow::Red);
    xw.fillRectangle(310, 150, cellSize * 2, cellSize, Xwindow::Red);
    break;
   case 'Z':
    xw.fillRectangle(310, 135, cellSize * 2, cellSize, Xwindow::Cyan);
    xw.fillRectangle(325, 150, cellSize * 2, cellSize, Xwindow::Cyan);
    break;
   case 'T':
    xw.fillRectangle(310, 135, cellSize * 3, cellSize, Xwindow::Brown);
    xw.fillRectangle(325, 150, cellSize, cellSize, Xwindow::Brown);
    break;
  }
}

//draw the up current Level on the display
void GraphicsDisplay::drawLevel(int level) {
  xw.fillRectangle(200, 10, 70, 20, Xwindow::Orange);
  string s = to_string(level);
  xw.drawString(220, 20, s, Xwindow::Black);
}

//draw the up current Score on the display
void GraphicsDisplay::drawScore(int score) {
  xw.fillRectangle(200, 30, 70, 20, Xwindow::Orange);
  string s = to_string(score);
  xw.drawString(220, 40, s, Xwindow::Black);
}

//draw the up current High Score on the display
void GraphicsDisplay::drawHighScore(int high_score) {
  xw.fillRectangle(200, 50, 70, 20, Xwindow::Orange);
  string s = to_string(high_score);
  xw.drawString(220, 60, s, Xwindow::Black);
}

//as an observer, GraphicsDisplay keep track the line
//    and send the notification to the display
void GraphicsDisplay::notify(Subject& whoNotified) {
  int judge = 0;
  auto cells = whoNotified.getContent();
  int lineNum = whoNotified.getLineNumber();
  int index = whoNotified.getLineNumber();
  //check the difference between current line and whoNotified
  //if they are the same, return immediatly to save time
  for(int i = 0; i < 11; i++) {
    if(theDisplay[index + 3][i] != cells[i]->getType()) {
      judge++;
    }
  }
  if(judge == 0) {
    return;
  }
  //otherwise, draw the block on the display by different type of Block
  for(int i = 0; i < 11; i++) {
    char character = cells[i]->getType();
    if(theDisplay[index + 3][i] != character) {
      switch(character) {
       case 'I':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Blue);
        break;
       case 'J':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Yellow);
        break;
       case 'L':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Magenta);
        break;
       case 'O':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Green);
        break;
       case 'S':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Red);
        break;
       case 'Z':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Cyan);
        break;
       case 'T':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Brown);
        break;
       case '*':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Orange);
        break;
       case '?':
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::Black);
        break;
       default:
        xw.fillRectangle(i * cellSize + 115, (lineNum + 3) * cellSize + 75, cellSize, cellSize, Xwindow::White);
      }
    }
  }
  //remember the current line
	for(int i = 0; i < 11; i++) {
		theDisplay[index + 3][i] = whoNotified.getContent()[i]->getType();
	}
}

//print the end game message
void GraphicsDisplay::endGame() {
	xw.fillRectangle(0, 0, width, height, Xwindow::Black);
	xw.drawBigString(width / 4, height / 2, "Sorry, you lost.", Xwindow::White);
	xw.drawBigString(width / 4, height / 2 + 30, "Please try again.", Xwindow::White);
}
