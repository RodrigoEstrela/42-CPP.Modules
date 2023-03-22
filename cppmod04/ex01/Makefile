SRCS	=	main.cpp Animal.cpp Cat.cpp Dog.cpp \
			Brain.cpp \

OBJS	=	$(addprefix objs/,$(SRCS:.cpp=.o))

CPPFLAGS	=	c++ -Wall -Wextra -Werror -std=c++98 -g

RM		=	rm -f

NAME	=	animal_brain

all:	$(NAME)

objs/%.o: srcs/%.cpp
	@mkdir -p objs
	$(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all
