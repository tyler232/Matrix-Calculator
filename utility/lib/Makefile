CXX = clang++
CFLAGS = -std=c++14 -Wall -Wextra -g
LIBS = -lm

SRCS = src/matrix.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = matrix

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp src/matrix.h 
	$(CXX) $(CFLAGS) -c main.cpp

src/matrix.o: src/matrix.cpp src/matrix.h
	$(CXX) $(CFLAGS) -c src/matrix.cpp -o src/matrix.o

clean:
	rm -f $(OBJS) $(TARGET)
