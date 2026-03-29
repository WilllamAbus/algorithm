CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

TARGET = mainW2

SRCS = mainW2.cpp \
       asteroidColinsion.cpp \
       circularQueue.cpp \
       convertListBinaryTree.cpp \
       dailyTemperture.cpp \
       evaluateReversePolishNotation.cpp \
		implementQueueUsingStack.cpp \
       implementStackUsingQueue.cpp \
      	makeTheStringGreat.cpp \
       removeLinkListNode.cpp \
 		removeStringII.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET) all

clean:
	rm -f $(OBJS) $(TARGET)