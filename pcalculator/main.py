# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaye <slaye@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 21:32:09 by slaye             #+#    #+#              #
#    Updated: 2024/05/29 22:18:02 by slaye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import math
import color
import debug
import utils

def	get_xp(current_lvl):
	base_lvl = 0
	floating_lvl = 0
	total_xp = [0, 462, 2688, 5885, 11777, 29217, 46255, 63559, 74340, 85483, 95000]
	xps = [0, 462, 2226, 3197, 5892, 17440, 17038, 17304, 10781, 11143, 9517]

	base_lvl = math.floor(current_lvl);
	floating_lvl = current_lvl - base_lvl;
	return (total_xp[base_lvl] + (xps[base_lvl + 1] * floating_lvl));

def	get_lvl(gxp):
	result = 0
	total_xp = [0, 462, 2688, 5885, 11777, 29217, 46255, 63559, 74340, 85483, 95000]

	for i in range(len(total_xp) - 1):
		if (gxp >= total_xp[i] and gxp < total_xp[i + 1]):
			result = i
			result += gxp / total_xp[i + 1]
	return (result)

def execute():
	current_lvl = 0
	project_xp = 0
	bonus = False
	current_xp = 0
	project_xp = 0
	result = 0

	utils.sheader()
	current_lvl = utils.sinput(debug.DEB_CUR_LVL)
	if (current_lvl == -1 or current_lvl < 0 or current_lvl > 10):
		utils.perror(debug.ERR_INPUT)
		return
	project_xp = utils.sinput(debug.DEB_PROJ_XP)
	if (project_xp == -1 or project_xp < 0 or project_xp > 63000):
		utils.perror(debug.ERR_INPUT)
		return
	bonus = utils.sinput(debug.DEB_BONUS)
	if (bonus == -1 or bonus < 0 or bonus > 1):
		utils.perror(debug.ERR_INPUT)
		return
	if (bonus):
		project_xp += project_xp * 0.25;
	current_xp = get_xp(current_lvl)
	result = round((math.pow(((current_xp + project_xp) / 49980), 0.45) - math.pow((current_xp / 49980), 0.45)) * 483);
	print(f"You will be lvl {color.GREEN}{round(get_lvl(current_xp + project_xp), 2)}{color.RESET} and earn {color.GREEN}{result}{color.RESET} days of blackhole.")

if __name__ == "__main__":
	execute()