SRCS =	checker_pushswap.hs		\
		operation.hs

NAME = pushswap_checker

all : $(NAME)

$(NAME) :
		ghc $(SRCS) -o $(NAME)

clean :
	find . -name "*.hi" -delete
	find . -name "*.o" -delete


fclean : clean
	rm -f $(NAME)

re : fclean all

x : re
	./$(NAME)
