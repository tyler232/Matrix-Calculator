CXX = clang++
CFLAGS = -std=c++14 -Wall -Wextra -g
LIBS = -lm

SRCS = main.cpp matrix_calculator.cpp lib/matrix.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = matrix_calculator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp matrix_calculator.h lib/matrix.h
	$(CXX) $(CFLAGS) -c main.cpp

matrix_calculator.o: matrix_calculator.cpp matrix_calculator.h lib/matrix.h
	$(CXX) $(CFLAGS) -c matrix_calculator.cpp

lib/matrix.o: lib/matrix.cpp lib/matrix.h
	$(CXX) $(CFLAGS) -c lib/matrix.cpp -o lib/matrix.o

clean:
	rm -f $(OBJS) $(TARGET)
