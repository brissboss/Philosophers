NAME	=	philosophers

SRCS	=	main.c src/utils.c src/philo.c src/time.c src/itoa.c src/init.c

OBJS	= $(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread
			@echo "\033[1;32mCompilation complete ✅"

clean:
			@$(RM) $(OBJS)
			@echo "\033[1;32mCleaning complete 🧽\033[0;37m"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[1;32mFull cleaning complete 🧹\033[0;37m"

re:			fclean all
			@echo "\033[1;32mRebuild complete 🔨\033[0;37m"

.PHONY:		all fclean clean re
