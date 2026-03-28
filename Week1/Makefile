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

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)