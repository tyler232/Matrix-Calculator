CXX = clang++
CFLAGS = -std=c++14 -Wall -Wextra -g
LIBS = -lm

SRCS = main.cpp tiele.cpp lib/src/matrix.cpp matrix_basic_operation.cpp matrix_basic_type.cpp echelon.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = tiele

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp tiele.h lib/src/matrix.h matrix_basic_operation.h matrix_basic_type.h echelon.h
	$(CXX) $(CFLAGS) -c main.cpp

tiele.o: tiele.cpp tiele.h lib/src/matrix.h matrix_basic_operation.h matrix_basic_type.h echelon.h
	$(CXX) $(CFLAGS) -c tiele.cpp

lib/src/matrix.o: lib/src/matrix.cpp lib/src/matrix.h
	$(CXX) $(CFLAGS) -c lib/src/matrix.cpp -o lib/src/matrix.o

matrix_basic_operation.o: matrix_basic_operation.cpp matrix_basic_operation.h
	$(CXX) $(CFLAGS) -c matrix_basic_operation.cpp -o matrix_basic_operation.o

matrix_basic_type.o: matrix_basic_type.cpp matrix_basic_type.h
	$(CXX) $(CFLAGS) -c matrix_basic_type.cpp -o matrix_basic_type.o

echelon.o: echelon.cpp echelon.h
	$(CXX) $(CFLAGS) -c echelon.cpp -o echelon.o

clean:
	rm -f $(OBJS) $(TARGET)
