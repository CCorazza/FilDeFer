# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/04/22 02:46:42 by ccorazza          #+#    #+#              #
#    Updated: 2014/04/27 21:25:14 by ccorazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

include Makefile.sources

OBJ = $(SRC:.c=.o)
GW = @gcc -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@printf "Début de la compilation...\r"
	$(GW) -LLibft -lft -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME) $(OBJ)
	@echo "... Compilation de fdf [\033[38;5;34mDone\033[0m].\n"
	@echo "\t\033[36m- Usage -\n\033[0m"
	@echo "./fdf nom_de_la_map.fdf\n"
	@printf '\033[1;33m%s \t\t\033[0m⇒ %s\n' "Esc" "Quitter le programme."
	@printf '\033[1;33m%s \t\033[0m⇒ %s\n' "R, G, B, ou D" "Changer la couleur à Rouge, Vert, Bleu, ou en couleur par défaut."
	@printf '\033[1;33m%s \t\t\033[0m⇒ %s\n' "+ ou -" "Zoomer ou Dézoomer sur la map."
	@printf '\033[1;33m%s \t\t\033[0m⇒ %s\n' "Espace" "Remettre la map à zéro."


$(OBJ):
	$(GW) -c $(SRC) -I/usr/X11/include -ILibft

clean:
	@echo "Suppression des .o"
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "Suppression de l'exécutable"
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
	@echo "Tout frais, tout propre !"

.PHONY: all, clean, fclean, re

help:
	@printf '\033[1;33m%6s \033[0m⇒ %s\n' "clean"	"Suppression des .o"
	@printf '\033[1;33m%6s \033[0m⇒ %s\n' "fclean"	"Rappelle 'clean' && supprime l'exécutable"
	@printf '\033[1;33m%6s \033[0m⇒ %s\n' "re"		"Appelle clean, fclean, et recompile"
