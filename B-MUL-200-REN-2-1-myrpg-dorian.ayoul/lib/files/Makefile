##
## EPITECH PROJECT, 2021
## rpg - files
## File description:
## Makefile
##

SRC = 	src/file_exists.c \
		src/read_file.c \
		src/write_file.c

OBJ = $(SRC:.c=.o)
SRC_COUNT		:= $(words $(SRC))
SRC_ID			= 0
PROGRESS		= python3 ../../build/_make_progress.py

GCC = gcc

C_WARNING_FLAGS = -Wextra -Wall

INCLUDE_FLAGS = -I include
INCLUDE_FLAGS += -I ../neptunia-lib/include

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)
NAME = $(notdir $(CURDIR))

.c.o:
	@$(eval SRC_ID=$(shell echo $$(($(SRC_ID)+1))))
	@$(PROGRESS) --stepno=$(SRC_ID) --nsteps=$(SRC_COUNT) [$(NAME)] Compiling $<; true
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: $(OBJ)
	@ar rc libfiles.a $(OBJ)
	@$(PROGRESS) --stepno=$(SRC_ID) --nsteps=$(SRC_COUNT) --end [$(NAME)] Build success; true

.PHONY : all

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean