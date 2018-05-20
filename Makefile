CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = quadris
OBJECTS = command.o cell.o line.o subject.o board.o level.o levelzero.o levelone.o leveltwo.o levelthree.o levelfour.o observer.o textdisplay.o block.o iblock.o jblock.o oblock.o sblock.o zblock.o tblock.o lblock.o starblock.o graphicsdisplay.o window.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
