DIR = `basename $(PWD)`

CXX			= g++
CXXFLAGS 	= -Wall -Wextra -g -pedantic -std=c++11 -I../include/ 
LFLAGS 		= ../libgtest.a -lpthread
APP	 		= main

DEP_FLAGS	= -MMD -MP
CXXFLAGS	+= $(DEP_FLAGS)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(APP)

$(APP): $(OBJ)
		$(CXX) -o $@ $^ $(LFLAGS)

%.o: %.cpp
		$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(APP)
		./$(APP)

clean:
		rm -f $(APP) $(OBJ) $(DEP) ./*~

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

.PHONY: all run clean cleanall tar backup val

-include $(DEP)
