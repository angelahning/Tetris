#include "textdisplay.h"
#include "subject.h"

using namespace std;

//height and width of the board; default is 15+3 rows and 11 columns
TextDisplay::TextDisplay(int height = 18, int width = 11) {
	vector<char> row(width, ' ');
	for(int i = 0 ; i < height; i++) {
		theDisplay.emplace_back(row);
	}
}

//as an observer, TextDisplay keep track the line
//    and send the notification to the display
void TextDisplay::notify(Subject& whoNotified) {
	//assuming each line has a line number
	int index = whoNotified.getLineNumber();
	for(int i = 0; i < 11; i++) {
		theDisplay[index + 3][i] = whoNotified.getContent()[i]->getType();
	}
}

//overload function opreator<< in order to cout a textdisplay
ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	for(auto row : td.theDisplay) {
        for(auto el : row) {
            out << el;
        }
        out << endl;
    }
    return out;
}
