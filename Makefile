CXX = g++
CXXFLAGS = -Wall -Iinclude/

csweeper: Tile.o Board.o Game.o src/play.cpp
	$(CXX) $(CXXFLAGS) Tile.o Board.o Game.o src/play.cpp -g -o csweeper

Tile.o: src/Tile.cpp
	$(CXX) $(CXXFLAGS) src/Tile.cpp -c

Board.o: src/Board.cpp
	$(CXX) $(CXXFLAGS) src/Board.cpp -c

Game.o: src/Game.cpp
	$(CXX) $(CXXFLAGS) src/Game.cpp -c

play:
	./csweeper

clean:
	rm csweeper *.o