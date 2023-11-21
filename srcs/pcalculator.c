/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcalculator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:53:00 by uwywijas          #+#    #+#             */
/*   Updated: 2023/11/21 19:19:50 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pcalculator.h"
#include "../includes/colors.h"

void	ft_header()
{
	printf("\n%s・━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━・%s\n", BLUE, RESET);
	printf("%s              Weclcome on PCalculator !%s", BOLD, RESET);
	printf("\n%s・━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━・%s\n\n", BLUE, RESET);
}

void	ft_finput(char *str, float *variable)
{
	printf("%s%s%s", BOLD, str, RESET);
	scanf("%f", variable);
}

void	ft_dinput(char *str, int *variable)
{
	printf("%s%s%s", BOLD, str, RESET);
	scanf("%d", variable);
}

int	ft_getxp(float current_lvl)
{
	float	floating_lvl;
	int		base_lvl;
	int		total[] = {0, 462, 2688, 5885, 11777, 29217, 46255, 63559, 74340, 85483, 95000};
	int		xps[] = {0, 462, 2226, 3197, 5892, 17440, 17038, 17304, 10781, 11143, 9517};

	base_lvl = floor(current_lvl);
	floating_lvl = current_lvl - base_lvl;
	return (total[base_lvl] + (xps[base_lvl + 1] * floating_lvl));
}

float	ft_getlvl(int gxp)
{
	float	result;
	int		total[] = {0, 462, 2688, 5885, 11777, 29217, 46255, 63559, 74340, 85483, 95000};
	int		i;

	i = 0;
	result = -1;
	while (i < 9)
	{
		if (gxp >= total[i] && gxp < total[i + 1])
		{
			result = i;
			result += (float) gxp / total[i + 1];
		}
		i++;
	}
	return (result);
}

int	ft_error(void)
{
	printf("\n%s%sSomething bad appened.%s\n", BOLD, RED, RESET);
	return (-1);
}

int	main(void)
{
	float	current_lvl;
	float	current_xp;
	float	project_xp;
	int		is_bonus;
	int		result;

	current_xp = 0;
	project_xp = 0;
	is_bonus = 0;
	result = 0;
	ft_header();
	ft_finput("Current level [0.0/10.0]: ", &current_lvl);
	ft_finput("Project xp [0/63000]: ", &project_xp);
	ft_dinput("Bonus [0/1]: ", &is_bonus);
	if ((current_lvl < 0 || current_lvl > 10)|| (project_xp < 0 || project_xp > 63000) || (is_bonus < 0 || is_bonus > 1))
		return (ft_error());
	current_xp = ft_getxp(current_lvl);
	if (is_bonus)
		project_xp += project_xp * 0.25;
	result = (powf(((current_xp + project_xp) / 49980), 0.45) - powf((current_xp / 49980), 0.45)) * 483;
	printf("\n%sYou will be lvl %s%f%s\n", BOLD, GREEN, ft_getlvl(current_xp + project_xp), RESET);
	printf("%sYou will earn %s%d%s%s days of blackhole.%s\n", BOLD, GREEN, result, RESET, BOLD, RESET);
	return (0);
}
