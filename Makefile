# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 19:17:03 by hyeonsok          #+#    #+#              #
#    Updated: 2022/02/21 23:47:20 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

INCLUDES	=	-I include/ -I$(shell brew --prefix readline)/include/ \
				-I lib/libft/include/

LIBS		=	-L $(shell brew --prefix readline)/lib/ -lreadline \
				-L lib/libft -lfthx

LIBFTHX		=	lib/libft/libfthx.a

OBJDIR := ./obj

# ./src
OBJS		=	$(addprefix $(OBJDIR)/, \
				main.o)

# ./src/mush
OBJS		+=	$(addprefix $(OBJDIR)/, \
				front_signal.o \
				front_prompt.o \
				parser.o \
				parser_buffer.o \
				parser_iofile.o \
				parser_pipeline.o \
				parser_token.o \
				parser_error.o \
				exec.o \
				exec_expn_word.o \
				exec_expn_cmd.o \
				exec_redir.o \
				exec_poll.o \
				exec_builtin.o \
				exec_cleanup.o)

# ./src/builtin
OBJS		+=	$(addprefix $(OBJDIR)/, \
				builtin_cd.o \
				builtin_echo.o \
				builtin_env.o \
				builtin_exit.o \
				builtin_export.o \
				builtin_pwd.o \
				builtin_unset.o)

# ./src/utils
OBJS		+=	$(addprefix $(OBJDIR)/, \
				mush_valid_name.o \
				mush_error.o \
				mush_env.o)

SRC_DIR = ./src
SRC_UTILS_DIR = ./src/utils
SRC_BUILTIN_DIR = ./src/builtin
SRC_MUSH_DIR = ./src/mush

NAME = minishell

.PHONY:		all
all:		libfthx $(NAME)

libfthx:		$(LIBFTHX)

$(LIBFTHX):
			make -C lib/libft/

$(NAME):	$(OBJDIR) $(OBJS)
			$(CC) $(INCLUDES) $(OBJS) $(DEBUG) -o $(NAME) $(LIBS)

$(OBJDIR)/%.o : $(SRC_MUSH_DIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(SRC_DIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(SRC_BUILTIN_DIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(SRC_UTILS_DIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)
$(OBJDIR):
			mkdir $(OBJDIR)

.PHONY:		clean
clean:
			make clean -C lib/libft/
			$(RM) -r $(OBJDIR)

.PHONY:		fclean
fclean:		clean
			make fclean -C lib/libft/
			$(RM) -r $(NAME)

.PHONY:		re
re: fclean all
