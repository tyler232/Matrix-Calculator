CXX = clang++
CFLAGS = -std=c++14 -Wall -Wextra -g
LIBS = -lm

SRCS = main.cpp matrix.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = matrix

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp matrix.h
	$(CXX) $(CFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CFLAGS) -c matrix.cpp

clean:
	rm -f $(OBJS) $(TARGET)
