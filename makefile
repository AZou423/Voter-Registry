COURSE = cs310
SEMESTER = fall2024
CP_NUMBER = 2
LASTNAME = Choi
GITUSERID = cchoi11
EXE = register 
EXE2 = driver 

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g -std=c++20 #modified
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE) $(BIN)/$(EXE2)

$(BIN)/$(EXE): $(OBJ)/Node.o $(OBJ)/Vector.o $(OBJ)/BST.o $(OBJ)/Heap.o $(OBJ)/Voter.o $(OBJ)/driver.o
	$(CC) $(FLAGS) $(OBJ)/Node.o $(OBJ)/Vector.o $(OBJ)/BST.o $(OBJ)/Heap.o $(OBJ)/Voter.o \
		$(OBJ)/driver.o -o $@

# Specify how the object files should be created from source files
$(OBJ)/Voter.o: Voter.cpp Voter.h
	$(CC) $(FLAGS) -c Voter.cpp -o $@

$(OBJ)/Node.o: Node.cpp Node.h
	$(CC) $(FLAGS) -c Node.cpp -o $@

$(OBJ)/Heap.o: Heap.cpp Heap.h
	$(CC) $(FLAGS) -c Heap.cpp -o $@

$(OBJ)/BST.o: BST.cpp BST.h
	$(CC) $(FLAGS) -c BST.cpp -o $@

$(OBJ)/Vector.o: Vector.cpp Vector.h
	$(CC) $(FLAGS) -c Vector.cpp -o $@

$(OBJ)/driver.o: driver.cpp Vector.h BST.h Heap.h Node.h Voter.h
	$(CC) $(FLAGS) -c driver.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(TARFILE)".gz"

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(BIN)/$(EXE2) *.tar.gz