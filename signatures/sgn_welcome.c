/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgn_welcome.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:17:00 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 17:57:27 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void print_welcome()
{
	printf(" %s%s_____                                                                                            _____\n", FONT_BOLD, FONT_BLU);
	printf("( ___ )                                                                                          ( ___ )\n");
	printf(" |   |%s%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s%s%s|   |\n", FONT_NRM, FONT_BLU, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s  _____ ______   ___  ________   ___  ________  ___  ___  _______   ___       ___           %s%s%s|   | \n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s |\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\  \\|\\   ____\\|\\  \\|\\  \\|\\  ___ \\ |\\  \\     |\\  \\          %s%s%s|   | \n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s \\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\___|\\ \\  \\\\\\  \\ \\   __/|\\ \\  \\    \\ \\  \\         %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s  \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\ \\_____  \\ \\   __  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\        %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s   \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|____|\\  \\ \\  \\ \\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____   %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s    \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\____\\_\\  \\ \\__\\ \\__\\ \\_______\\ \\_______\\ \\_______\\ %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s     \\|__|     \\|__|\\|__|\\|__| \\|__|\\|__|\\_________\\|__|\\|__|\\|_______|\\|_______|\\|_______| %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s                                        \\|_________|                                        %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |   |%s%s%s By クリストファ & ファビアン                                                               %s%s%s|   |\n", FONT_NRM, FONT_BOLD, FONT_YEL, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf(" |___|%s%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s%s%s|___|\n", FONT_NRM, FONT_BLU, FONT_NRM, FONT_BLU, FONT_BOLD);
	printf("(_____)                                                                                          (_____)%s\n\n", FONT_NRM);
}