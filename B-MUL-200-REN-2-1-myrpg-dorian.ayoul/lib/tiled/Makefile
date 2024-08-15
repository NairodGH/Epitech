##
## EPITECH PROJECT, 2021
## rpg - tiled
## File description:
## Makefile
##

SRC = 	src/tiled_layer.c \
		src/tiled_parser.c \
		src/tiled_tileset.c

OBJ = $(SRC:.c=.o)
SRC_COUNT		:= $(words $(SRC))
SRC_ID			= 0
PROGRESS		= python3 ../../build/_make_progress.py

GCC = gcc

C_WARNING_FLAGS = -Wextra -Wall -g

INCLUDE_FLAGS = -I include
INCLUDE_FLAGS += -I ../files/include
INCLUDE_FLAGS += -I ../neptunia-lib/include

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)
NAME = $(notdir $(CURDIR))

.c.o:
	@$(eval SRC_ID=$(shell echo $$(($(SRC_ID)+1))))
	@$(PROGRESS) --stepno=$(SRC_ID) --nsteps=$(SRC_COUNT) [$(NAME)] Compiling $<; true
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: libtiled.a
.PHONY : all

libtiled.a: $(OBJ)
	@ar rc $@ $(OBJ)
	@$(PROGRESS) --stepno=$(SRC_ID) --nsteps=$(SRC_COUNT) --end [$(NAME)] Build success; true
.PHONY : libtiled.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean

TEST_SRC = test/main.c

TEST_OBJ = $(TEST_SRC:.c=.o)

TEST_LIB_FLAGS = -L . -ltiled
TEST_LIB_FLAGS += -L ../files -lfiles
TEST_LIB_FLAGS += -L ../neptunia-lib -lnep

test: libtiled.a $(TEST_OBJ)
	@gcc -o test.out $(TEST_OBJ) $(TEST_LIB_FLAGS)
.PHONY : test