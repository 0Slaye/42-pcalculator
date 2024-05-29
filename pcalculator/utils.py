# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaye <slaye@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 21:44:22 by slaye             #+#    #+#              #
#    Updated: 2024/05/29 21:57:25 by slaye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import color

def	perror(value:str):
	print(f"{color.RED}Error{color.RESET}: {value}")

def	sheader():
	print(f"{color.BLUE}╭───────────────────────────────╮{color.RESET}");
	print(f"{color.BLUE}│    {color.RESET}{color.BOLD}Weclcome on PCalculator{color.RESET}    {color.BLUE}│");
	print(f"{color.BLUE}╰───────────────────────────────╯{color.RESET}\n");

def	sinput(value:str):
	result = 0;

	try:
		result = int(input(f"{value}: "))
	except:
		return (-1)
	return (result)