LIBS=-I/usr/local/include/
CFLAGS=-l bcm2835
objects=main.o

RaspiPWMTest: $(objects) 
	g++ $(objects) -o RaspiPWMTest $(LIBS) $(CFLAGS)

main.o: main.cpp
	g++ main.cpp -c
	
.PHONY: clean
clean:
	rm RaspiPWMTest $(objects)