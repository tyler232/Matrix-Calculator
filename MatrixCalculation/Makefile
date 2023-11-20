CXX = clang++
CFLAGS = -std=c++14 -Wall -Wextra -g
LIBS = -lm

SRCS = main.cpp tiele.cpp lib/matrix.cpp matrix_basic_operation.cpp matrix_basic_type.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = tiele

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp tiele.h lib/matrix.h matrix_basic_operation.h matrix_basic_type.h
	$(CXX) $(CFLAGS) -c main.cpp

tiele.o: tiele.cpp tiele.h lib/matrix.h matrix_basic_operation.h matrix_basic_type.h
	$(CXX) $(CFLAGS) -c tiele.cpp

lib/matrix.o: lib/matrix.cpp lib/matrix.h
	$(CXX) $(CFLAGS) -c lib/matrix.cpp -o lib/matrix.o

matrix_basic_operation.o: matrix_basic_operation.cpp matrix_basic_operation.h
	$(CXX) $(CFLAGS) -c matrix_basic_operation.cpp -o matrix_basic_operation.o

matrix_basic_type.o: matrix_basic_type.cpp matrix_basic_type.h
	$(CXX) $(CFLAGS) -c matrix_basic_type.cpp -o matrix_basic_type.o

clean:
	rm -f $(OBJS) $(TARGET)
