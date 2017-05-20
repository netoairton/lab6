RM =	cmd //C del



# Compilador

CC=g++ 



# Variaveis para os subdiretorios

LIB_DIR=lib

INC_DIR=include

SRC_DIR=src

OBJ_DIR=build

BIN_DIR=bin

DOC_DIR=doc

TEST_DIR=test
 


# Opcoes de compilacao

CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)



# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome

.PHONY: all init clean debug doxy doc



# Define o alvo (target) para a compilacao completa e os alvos de dependencia.

# Ao final da compilacao, remove os arquivos objeto.

all:	duplamente


debug: CFLAGS += -g -O0

debug: all




duplamente: $(OBJ_DIR)/main.o
	@echo "============="

	@echo "Ligando o alvo $@"

	@echo "============="

	$(CC) $(CFLAGS) -o $(BIN_DIR)/duplamente $^

	@echo "+++ [Executavel duplamente criado em $(BIN_DIR)] +++"

	@echo "============="




# Alvo (target) para a construcao do objeto build/main.o

# Define os arquivos src/main.cpp e os arquivos de cabecalho como dependencias.

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/lista.h

	$(CC) -c $(CFLAGS) -o $@ $<



# Alvo (target) para a geração automatica de documentacao usando o Doxygen.

# Sempre remove a documentacao anterior (caso exista) e gera uma nova.

doxy:
	
	doxygen -g

doc:

	$(RM) $(DOC_DIR)/*

	doxygen



# Alvo (target) usado para limpar os arquivos temporarios (objeto)

# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean:

	$(RM) $(BIN_DIR)/duplamente

	$(RM) $(OBJ_DIR)/*
