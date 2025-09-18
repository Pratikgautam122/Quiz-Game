CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SOURCES = src/main.cpp src/Question.cpp src/Player.cpp src/QuizGame.cpp
TARGET = quiz

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean