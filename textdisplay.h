#ifndef _TD_H
#define _TD_H

#include "observer.h"
#include "line.h"
#include <vector>
#include <iostream>

class TextDisplay: public Observer {
	std::vector<std::vector<char>> theDisplay;
	void notify(Subject& whoNotified) override; //as an observer, TextDisplay keep track the line and send the notification to the display
public:
	TextDisplay(int height, int width); //TextDisplay constructor
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td); //overload function opreator<< in order to cout a TextDisplay
};

#endif
