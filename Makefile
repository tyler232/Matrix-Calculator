CXX = clang++
CFLAGS = -std=c++14 -Wall -Wextra -g -pthread
LIBS = -lm

SRCS = main.cpp tiele.cpp utility/lib/src/matrix.cpp utility/matrix_basic_operation.cpp utility/matrix_basic_type.cpp utility/echelon.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = tiele

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp tiele.h utility/lib/src/matrix.h utility/matrix_basic_operation.h utility/matrix_basic_type.h utility/echelon.h
	$(CXX) $(CFLAGS) -c main.cpp

tiele.o: tiele.cpp tiele.h utility/lib/src/matrix.h utility/matrix_basic_operation.h utility/matrix_basic_type.h utility/echelon.h
	$(CXX) $(CFLAGS) -c tiele.cpp

utility/lib/src/matrix.o: utility/lib/src/matrix.cpp utility/lib/src/matrix.h
	$(CXX) $(CFLAGS) -c utility/lib/src/matrix.cpp -o utility/lib/src/matrix.o

utility/matrix_basic_operation.o: utility/matrix_basic_operation.cpp utility/matrix_basic_operation.h
	$(CXX) $(CFLAGS) -c utility/matrix_basic_operation.cpp -o utility/matrix_basic_operation.o

utility/matrix_basic_type.o: utility/matrix_basic_type.cpp utility/matrix_basic_type.h
	$(CXX) $(CFLAGS) -c utility/matrix_basic_type.cpp -o utility/matrix_basic_type.o

utility/echelon.o: utility/echelon.cpp utility/echelon.h
	$(CXX) $(CFLAGS) -c utility/echelon.cpp -o utility/echelon.o

clean:
	rm -f $(OBJS) $(TARGET)
