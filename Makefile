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

CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/programa1



# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome

.PHONY: all init clean debug doxy doc



# Define o alvo (target) para a compilacao completa e os alvos de dependencia.

# Ao final da compilacao, remove os arquivos objeto.

all:	palindromo


debug: CFLAGS += -g -O0

debug: all




palindromo: $(OBJ_DIR)/programa1/main.o $(OBJ_DIR)/programa1/trata_string.o

	@echo "============="

	@echo "Ligando o alvo $@"

	@echo "============="

	$(CC) $(CFLAGS) -o $(BIN_DIR)/programa1/palindromo $^

	@echo "+++ [Executavel palindromo criado em  $(BIN_DIR)/programa1] +++"

	@echo "============="




$(OBJ_DIR)/programa1/trata_string.o: $(SRC_DIR)/programa1/trata_string.cpp $(INC_DIR)/programa1/trata_string.h

	$(CC) -c $(CFLAGS) -o $@ $<



# Alvo (target) para a construcao do objeto build/programa1/main.o

# Define os arquivos src/programa1/main.cpp e os arquivos de cabecalho como dependencias.

$(OBJ_DIR)/programa1/main.o: $(SRC_DIR)/programa1/main.cpp $(INC_DIR)/programa1/pilha.h  $(INC_DIR)/programa1/trata_string.h

	$(CC) -c $(CFLAGS) -o $@ $<




###########programa 2 ###


# Opcoes de compilacao

CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/programa2



# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome

.PHONY: all init clean debug doxy doc



# Define o alvo (target) para a compilacao completa e os alvos de dependencia.

# Ao final da compilacao, remove os arquivos objeto.

all:	duplamente


debug: CFLAGS += -g -O0

debug: all




duplamente: $(OBJ_DIR)/programa2/main.o
	@echo "============="

	@echo "Ligando o alvo $@"

	@echo "============="

	$(CC) $(CFLAGS) -o $(BIN_DIR)/programa2/duplamente $^

	@echo "+++ [Executavel duplamente criado em $(BIN_DIR)/programa2] +++"

	@echo "============="




# Alvo (target) para a construcao do objeto build/programa2/main.o

# Define os arquivos src//programa2main.cpp e os arquivos de cabecalho como dependencias.

$(OBJ_DIR)/programa2/main.o: $(SRC_DIR)/programa2/main.cpp $(INC_DIR)/programa2/lista.h

	$(CC) -c $(CFLAGS) -o $@ $<



########## programa 3 #####

# Opcoes de compilacao

CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/programa3



# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome

.PHONY: all init clean debug doxy doc


# Define o alvo (target) para a compilacao completa e os alvos de dependencia.

# Ao final da compilacao, remove os arquivos objeto.

all:	turmas


debug: CFLAGS += -g -O0

debug: all




turmas: $(OBJ_DIR)/programa3/main.o $(OBJ_DIR)/programa3/openarquivo.o

	@echo "============="

	@echo "Ligando o alvo $@"

	@echo "============="

	$(CC) $(CFLAGS) -o $(BIN_DIR)/programa3/turmas $^

	@echo "+++ [Executavel turmas criado em $(BIN_DIR)/programa3] +++"

	@echo "============="




$(OBJ_DIR)/programa3/openarquivo.o: $(SRC_DIR)/programa3/openarquivo.cpp $(INC_DIR)/programa3/alunos.h $(INC_DIR)/programa3/openarquivo.h

	$(CC) -c $(CFLAGS) -o $@ $<



# Alvo (target) para a construcao do objeto build/programa3/main.o

# Define os arquivos src/programa3/main.cpp e os arquivos de cabecalho como dependencias.

$(OBJ_DIR)/programa3/main.o: $(SRC_DIR)/programa3/main.cpp $(INC_DIR)/programa3/alunos.h $(INC_DIR)/programa3/openarquivo.h

	$(CC) -c $(CFLAGS) -o $@ $<



# Alvo (target) para a geração automatica de documentacao usando o Doxygen.

# Sempre remove a documentacao anterior (caso exista) e gera uma nova.

doxy:
	
	doxygen -g

doc:

	$(RM) $(DOC_DIR)/programa1/*

	$(RM) $(DOC_DIR)/programa2/*

	$(RM) $(DOC_DIR)/programa3/*

	doxygen



# Alvo (target) usado para limpar os arquivos temporarios (objeto)

# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean:

	$(RM) $(BIN_DIR)/programa1/palindromo

	$(RM) $(OBJ_DIR)/programa1/*

	$(RM) $(BIN_DIR)/programa2/duplamente

	$(RM) $(OBJ_DIR)/programa2/*

	$(RM) $(BIN_DIR)/programa3/turmas

	$(RM) $(OBJ_DIR)/programa3/*


