CC = g++
CFLAGS = -Wall -std=c++11
TARGET = main
OBJS = main.o Demos.o pointers.o util.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Demos.o: Demos.cpp pointers.h
	$(CC) $(CFLAGS) -c Demos.cpp

pointers.o: pointers.cpp pointers.h util.h
	$(CC) $(CFLAGS) -c pointers.cpp

util.o: util.cpp util.h
	$(CC) $(CFLAGS) -c util.cpp

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

