TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
FLAGS= -Wall -g

${TRGDIR}/main: ${OBJ} ${OBJ}/main.o ${OBJ}/package.o\
                     ${OBJ}/node.o ${OBJ}/dequeue.o ${OBJ}/sort.o
	g++ -o ${TRGDIR}/main ${OBJ}/main.o ${OBJ}/package.o\
                     ${OBJ}/node.o ${OBJ}/dequeue.o ${OBJ}/sort.o 
                   
${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp inc/sort.h 
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/package.o: ${SRC}/package.cpp inc/package.h
	g++ -c ${FLAGS} -o ${OBJ}/package.o ${SRC}/package.cpp

${OBJ}/node.o: ${SRC}/node.cpp inc/node.h
	g++ -c ${FLAGS} -o ${OBJ}/node.o ${SRC}/node.cpp

${OBJ}/sort.o: ${SRC}/sort.cpp inc/sort.h
	g++ -c ${FLAGS} -o ${OBJ}/sort.o ${SRC}/sort.cpp

${OBJ}/dequeue.o: ${SRC}/dequeue.cpp inc/dequeue.h
	g++ -c ${FLAGS} -o ${OBJ}/dequeue.o ${SRC}/dequeue.cpp

run:
	${TRGDIR}/main

clean:
	rm -f ${TRGDIR}/main ${OBJ}/*
