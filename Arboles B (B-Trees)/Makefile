CXX = g++
CXXFLAGS = -Wall -I. -std=c++11

SRCS = main.cpp DemoBTree.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = btree_program.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist *.o del *.o
	if exist $(TARGET) del $(TARGET)





