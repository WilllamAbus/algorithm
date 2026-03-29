CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

TARGET = mainW3

SRCS = mainW3.cpp \
       arrayPartition.cpp \
       containDuplicate.cpp \
       deleteNode.cpp \
       largestNumber.cpp \
       missingNumber.cpp \
		partitionList.cpp \
       removeNthNode.cpp \
      	sortColor.cpp \
       squareOfASortedArray.cpp \
 		thirdMaximumNumber.cpp \
		utils/list_utils.cpp \
		utils/vector_utils.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET) all

clean:
	rm -f $(OBJS) $(TARGET)