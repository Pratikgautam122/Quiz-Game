CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,obj/%.o,$(SRC))
TARGET = quizgame

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj:
	mkdir -p obj

clean:
	rm -f obj/*.o $(TARGET)