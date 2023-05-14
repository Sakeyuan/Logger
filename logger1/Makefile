CXX = g++
CXXFLAGS = -std=c++11 -Iutility -g
INCDIR = ./utility

main: main.o logger.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

logger.o: $(INCDIR)/logger.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clear

clear:
	rm -rf main *.o *.txt
