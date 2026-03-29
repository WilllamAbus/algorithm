CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

TARGET = mainW1

SRCS = mainW1.cpp \
       checkIfTwoStringArray.cpp \
       findDifference.cpp \
       groupAnagram.cpp \
       kidCandies.cpp \
       longestSubString.cpp \
       maximumSubArrAvgI.cpp \
       merArray.cpp \
       ransomeNote.cpp \
       robotReturn.cpp \
       validParenthese.cpp
OBJS = $(SRCS:.cpp=.o)



all: $(TARGET)

run: $(TARGET)
	./$(TARGET) check
	./$(TARGET) diff
	./$(TARGET) anagram
	./$(TARGET) kids
	./$(TARGET) longest
	./$(TARGET) avg
	./$(TARGET) merge
	./$(TARGET) ransom
	./$(TARGET) circle
	./$(TARGET) valid

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)