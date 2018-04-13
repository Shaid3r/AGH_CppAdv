DIR = `basename $(PWD)`

CXX			= g++
CXXFLAGS 	= -Wall -Wextra -g -pedantic -std=c++14
LFLAGS 		= 
APP	 		= main

DEP_FLAGS	= -MMD -MP
CXXFLAGS	+= $(DEP_FLAGS)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(APP)

$(APP): $(OBJ)
		$(CXX) -o $@ $(LFLAGS) $^

%.o: %.cpp
		$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(APP)
		./$(APP)

fail: CXXFLAGS+=-DFAIL
fail: $(OBJ)
		$(CXX) -o $@ $(LFLAGS) $^

clean:
		rm -f $(APP) $(OBJ) $(DEP) ./*~ ./fail

cleanall: clean
		(cd ../; rm -f $(DIR).tar.gz)

tar: cleanall
		(cd ../; tar -cvzf $(DIR).tar.gz $(DIR))

backup: clean
		@rm -rf ../backup/$(APP)
		@mkdir -p ../backup/$(APP)
		cp -rv * ../backup/$(APP)

val: $(APP)
		valgrind --leak-check=full ./$<

.PHONY: all run clean cleanall tar backup val fail

-include $(DEP)
