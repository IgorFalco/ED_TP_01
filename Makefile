CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp1.o $(OBJ)/Pilha.o $(OBJ)/Arvore.o $(OBJ)/TipoItem.o $(OBJ)/FuncoesSatisfabilidade.o $(OBJ)/FuncoesAvaliacao.o
HEADERS = $(INC)/Arvore.hpp $(INC)/FuncoesAvaliacao.hpp $(INC)/TipoCelula.hpp  $(INC)/TipoItem.hpp  $(INC)/TipoNo.hpp  $(INC)/Pilha.hpp  $(INC)/FuncoesSatisfabilidade.hpp 
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/tp1.out

$(BIN)/tp1.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/tp1.o: $(HEADERS) $(SRC)/tp1.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp1.o $(SRC)/tp1.cpp 	

$(OBJ)/Pilha.o: $(HEADERS) $(SRC)/Pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Pilha.o $(SRC)/Pilha.cpp 	

$(OBJ)/Arvore.o: $(HEADERS) $(SRC)/Arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Arvore.o $(SRC)/Arvore.cpp 	

$(OBJ)/TipoItem.o: $(HEADERS) $(SRC)/TipoItem.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoItem.o $(SRC)/TipoItem.cpp 	

$(OBJ)/FuncoesSatisfabilidade.o: $(HEADERS) $(SRC)/FuncoesSatisfabilidade.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FuncoesSatisfabilidade.o $(SRC)/FuncoesSatisfabilidade.cpp 

$(OBJ)/FuncoesAvaliacao.o: $(HEADERS) $(SRC)/FuncoesAvaliacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FuncoesAvaliacao.o $(SRC)/FuncoesAvaliacao.cpp

all: $(EXE)
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
