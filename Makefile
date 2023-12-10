###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -MD -MP -Ofast -march=native 
LINKS	= -L. -lmlx -lXext -lX11 -lm

###############################################################################
######                               LIBFT                               ######
###############################################################################

LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libft.a

###############################################################################
######                             MANDATORY                             ######
###############################################################################

NAME		= connect4
SRCSDIR		= srcs
SRCS		= ${SRCSDIR}/ai.c \
			${SRCSDIR}/read_mapfile.c \
			${SRCSDIR}/main.c

OBJSDIR		= ${SRCSDIR}/objs
DEPS		= $(SRCS:${SRCSDIR}/%.c=${OBJSDIR}/%.d)
OBJS		= $(SRCS:${SRCSDIR}/%.c=${OBJSDIR}/%.o)



all		: $(NAME)


$(NAME)	: ${OBJS}
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $@ $^ $(LINKS) -L. ${LIBFT}

${OBJSDIR}/%.o		: ${SRCSDIR}/%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I ./includes


clean	:
		make --no-print-directory -C ${LIBDIR} clean
		$(RM) $(OBJSDIR) $(OBJSDIR_B)

fclean	:
		make --no-print-directory -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR) $(OBJSDIR_B) $(NAME) $(NAME_B)


re		: fclean all

-include $(DEPS_B) $(DEPS)

.PHONY: all clean fclean bonus re t