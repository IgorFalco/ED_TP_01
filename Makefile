CC = g++
LIBS = -lm
SRC = src
OBJ = obj
TADSCPP = include/TADS/Lista/src
TADSHPP = include/TADS/Lista/include
INC = include
BIN = bin
OBJS = $(OBJ)/TP1.o $(OBJ)/Lista.o $(OBJ)/ListaDinamica.o $(OBJ)/ListaEstatica.o $(OBJ)/TipoItem.o  $(OBJ)/TipoCelula.o  
TADS = $(TADSHPP)/Lista.hpp $(TADSHPP)/ListaDinamica.hpp $(TADSHPP)/ListaEstatica.hpp $(TADSHPP)/TipoItem.hpp $(TADSHPP)/TipoCelula.hpp 
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/TP1

$(BIN)/TP1: $(OBJS)
	$(CC) -pg -g -o $(BIN)/TP1 $(OBJS) $(LIBS)

$(OBJ)/TP1.o: $(TADS) $(SRC)/TP1.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TP1.o $(SRC)/TP1.cpp 	

$(OBJ)/TipoCelula.o: $(TADS) $(TADSCPP)/TipoCelula.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoCelula.o $(TADSCPP)/TipoCelula.cpp 

$(OBJ)/Lista.o: $(TADS) $(TADSCPP)/Lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Lista.o $(TADSCPP)/Lista.cpp 

$(OBJ)/ListaDinamica.o: $(TADS) $(TADSCPP)/ListaDinamica.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ListaDinamica.o $(TADSCPP)/ListaDinamica.cpp

$(OBJ)/ListaEstatica.o: $(TADS) $(TADSCPP)/ListaEstatica.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ListaEstatica.o $(TADSCPP)/ListaEstatica.cpp

$(OBJ)/TipoItem.o: $(TADS) $(TADSCPP)/TipoItem.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoItem.o $(TADSCPP)/TipoItem.cpp

run: $(EXE)
	$(EXE)
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
