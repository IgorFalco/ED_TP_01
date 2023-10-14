CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp1.o  
HEADERS = $(INC)/Arvore.hpp $(INC)/Funcoes.hpp $(INC)/TipoCelula.hpp  $(INC)/TipoItem.hpp  $(INC)/TipoNo.hpp  $(INC)/Pilha.hpp 
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/tp1

$(BIN)/tp1: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp1 $(OBJS) $(LIBS)

$(OBJ)/tp1.o: $(HEADERS) $(SRC)/tp1.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp1.o $(SRC)/tp1.cpp 	

all: $(EXE)
	$(EXE) 
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
