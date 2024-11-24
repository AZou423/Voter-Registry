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

$(BIN)/$(EXE): $(OBJ)/RegisteredVotersVector.o $(OBJ)/RegisteredVotersABL.o $(OBJ)/Voter.o $(OBJ)/register.o
	$(CC) $(FLAGS) $(OBJ)/RegisteredVotersVector.o $(OBJ)/RegisteredVotersABL.o $(OBJ)/Voter.o \
		$(OBJ)/register.o -o $@

$(BIN)/$(EXE2): $(OBJ)/RegisteredVotersVector.o $(OBJ)/RegisteredVotersABL.o $(OBJ)/Voter.o $(OBJ)/driver.o
	$(CC) $(FLAGS) $(OBJ)/RegisteredVotersVector.o $(OBJ)/RegisteredVotersABL.o $(OBJ)/Voter.o \
		$(OBJ)/driver.o -o $@

# Specify how the object files should be created from source files
$(OBJ)/Voter.o: Voter.cpp Voter.h
	$(CC) $(FLAGS) -c Voter.cpp -o $@

$(OBJ)/RegisteredVotersVector.o: RegisteredVotersVector.cpp RegisteredVotersVector.h RegisteredVotersBase.h Voter.h
	$(CC) $(FLAGS) -c RegisteredVotersVector.cpp -o $@

$(OBJ)/RegisteredVotersABL.o: RegisteredVotersABL.cpp RegisteredVotersABL.h RegisteredVotersBase.h Voter.h
	$(CC) $(FLAGS) -c RegisteredVotersABL.cpp -o $@

$(OBJ)/register.o: register.cpp RegisteredVotersBase.h RegisteredVotersVector.h Voter.h
	$(CC) $(FLAGS) -c register.cpp -o $@

$(OBJ)/driver.o: driver.cpp RegisteredVotersBase.h RegisteredVotersVector.h Voter.h
	$(CC) $(FLAGS) -c driver.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(TARFILE)".gz"

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(BIN)/$(EXE2) *.tar.gz