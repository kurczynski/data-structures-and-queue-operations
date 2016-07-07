CC=g++
SRC_PATH=src
BIN_PATH=bin
OPTS=-std=c++11

all:
	$(CC) ${OPTS} ${SRC_PATH}/user_interface.h ${SRC_PATH}/kernel.h ${SRC_PATH}/test1.cpp -o ${BIN_PATH}/kernel1

clean:
	rm ${BIN_PATH}/* ${SRC_PATH}/*.o

