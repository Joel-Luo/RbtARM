TARGET=RbtARM

CC = g++
CFLAGS = -std=c++11 -Wall -O1 

INC_DIR=-I./include/
Lib_DIR=-L./lib
Lib=-lbcm2835


all: $(TARGET) rmobj

$(TARGET):	*.o 
	$(CC) $(CFLAGS) *.o -o $(TARGET) $(Lib_DIR) $(Lib)

*.o: *.cpp
	$(CC) -c *.cpp $(CFLAGS) $(INC_DIR)

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
rmobj:
	rm -f *.o