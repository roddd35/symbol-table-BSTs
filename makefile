PP=g++
CPPFLAGS= -Wall -g
OTHERS= item.cpp abb.cpp vetorOrdenado.cpp treap.cpp 23tree.cpp rubroNegra.cpp

################################

OBJS=item.o abb.o vetorOrdenado.o treap.o 23tree.o rubroNegra.o
MAIN=ep2.cpp

################################

.PHONY: clean

all: ep

item.o: item.h
abb.o: abb.h
vetorOrdenado.o: vetorOrdenado.h
treap.o: treap.h
23tree.o: 23tree.h
rubroNegra.o: rubroNegra.h
ep2.o: ep2.cpp

ep: ${OBJS} 
		${PP} ${CPPFLAGS} -o ep2 ${MAIN} ${OTHERS}
		@rm -rf *.o

clean:
	@rm -rf ep2