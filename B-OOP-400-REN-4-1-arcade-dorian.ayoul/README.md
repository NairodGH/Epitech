# Introduction

## What is Arcade ?

The Arcade is the 2nd project of the Object-Oriented Programming (OOP) module.
It's written in C++ by 2-3 2nd year students (Dorian AYOUL and Xavier TONNELLIER).
This gaming platform (should) allow you to:
- enter and save your username
- choose game and graphical dynamic libraries to play with through a starting menu
- play those games with an updated score
- create the game map you want
- be able to change graphic libraries mid-game
- save your best score (highscore)
- implement your own games and/or graphics in it

## What's special about it ?

To make sure the program stays general and allows anyone to implement their own games/graphics easily, this project required the
students to design its architecture by pairs of groups (at the end, one group's games should work on the other group's arcade even if they chose
different graphical libraries). We did the architecture with pierre.hamel@epitech.eu (Pierre HAMEL and Pierre MAUGER).
The architecture can be summarized to:
- the core loads the current game/graphical library
- the graphical library gets the user inputs
- the core receives them, converts them into generic enum inputs and gives them to the game library
- the game library changes the map according to the inputs
- the core receives it and, for each map tile, asks the graphical to draw the according form/letter

## Our arcade

Is a buggy mess since we focused other projects/had IRL issues but the key components code is here. Here's the steps:
- Compile with 'make re' at the root
- Start with './arcade ./libs/arcade_ncurses.so' or './arcade ./libs/arcade_sfml.so' (sdl2 code is here but too unfinished)
- At any point you can press escape to quit the arcade
- Write your desired username (lowercase letters or numpad numbers) then press enter
- Select the game/graphic you want by navigating with up or down arrow then pressing enter
- You can also, from the menu or any other game, press F5/F6 for the previous/next graphic and F7/F8 for the previous/next game
- Tip: try to stay on Nibbler :)

## How do you implement new games/graphics ?

To implement a new game/graphic you should:
- copy an existing game/graphic folder without its .hpp and .cpp files except entryPoint.cpp (used for loading/using/unloading the lib)
- change the names accordingly to the name of the libary you want to implement to avoid multiple definitions (Ctrl+H is useful)
- make sure to modify your folder's  Makefile with the correct compilation flag(s) and library name (arcade_nameofyourlib.so)
- add the rules for your folder to the general compiling Makefile in ./games or ./graphicals
- add the new library name in ./lib/libs.config under "graphicals:" or "games:"
- .cpp sourcecode files go in your folder's ./src and .hpp headers go in your folder's ./include
- make sure the classes you create are in the arc namespace and inherit from arc::IGame or arc::IDisplay (graphics)

## Example: adding the game pacman

./games:
> - pacman
>     - **include**
>         - pacman.hpp
>     - **ressources**
>         - map1.txt
>     - **games**
>         - pacman.cpp
>         - entryPoint.cpp
>     - Makefile

./games/pacman/include/Pacman.hpp:

```c++
#include "IGame.hpp"

namespace arc
{
    class Pacman : public arc::IGame
    {
        public:
            ~Pacman() = default;
            void init_game(void);
            void destroy_game(void);
            void update(std::vector<arc::GameKey>);
            void setGameState(arc::State state);
            arc::State getGameState(void);
            std::vector<std::vector<int>> getMap(void);
            std::size_t getScore(void);
            std::string getPlayerName(void);
            std::string getGameName(void);
    };
};
```

./games/pacman/src/entryPoint.cpp:

```c++
#include "Pacman.hpp"

arc::IGame *lib = nullptr;

__attribute__((constructor))
void loadLib()
{
	lib = new arc::Pacman;
}

__attribute__((destructor))
void unloadLib()
{
	delete lib;
}

extern "C" arc::IGame *entryPoint()
{
	return lib;
}
```

./games/pacman/ressources/map1.txt:

```
xxxxxxxxxxxxxxxxxxxxxxxxxxxx
x            xx            x
x xxxx xxxxx xx xxxxx xxxx x
x xxxx xxxxx xx xxxxx xxxx x
x                          x
x xxxx xx xxxxxxxx xx xxxx x
x      xx    xx    xx      x
xxxxxx xxxxx xx xxxxx xxxxxx
xxxxxx xx          xx xxxxxx
xxxxxx xx xxx  xxx xx xxxxxx
x         x      x         x
x         x      x         x
xxxxxx xx xxxxxxxx xx xxxxxx
xxxxxx xx          xx xxxxxx
xxxxxx xx xxxxxxxx xx xxxxxx
x            xx            x
x xxxx xxxxx xx xxxxx xxxx x
x   xx                xx   x
xxx xx x xxxxxxxxxx x xx xxx
x      x     xx     x      x
x xxxxxxxxxx xx xxxxxxxxxx x
x                          x
xxxxxxxxxxxxxxxxxxxxxxxxxxxx
```

./games/pacman/Makefile:

```
SRC = src/pacman.cpp 		\
	  src/entryPoint.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = arcade_pacman.so

CPPFLAGS = -fno-gnu-unique -W -Wall -Wextra -fPIC -shared -rdynamic -I ./include -I ../../include

all: $(OBJ)
	g++ -o ../../lib/$(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re
```

./games/Makefile:

```
all:
    make -C ./menu
	make -C ./pacman

clean:
    make clean -C ./menu
	make clean -C ./pacman

fclean: clean
    make fclean -C ./menu
	make fclean -C ./pacman

re: fclean all

.PHONY: all clean fclean re
```

./lib/libs.config:

```
graphicals:
arcade_ncurses.so
arcade_sdl2.so
arcade_sfml.so
games:
arcade_menu.so
arcade_pacman.so
```

Now implement your pacman in Pacman.cpp according to Pacman.hpp and you're good to go !

## What's after ?

The following doxygen-generated documentation provides more infos on the different base classes in place.