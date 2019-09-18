/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:19:56 by keverett          #+#    #+#             */
/*   Updated: 2019/09/18 09:20:10 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_intro1(void)
{
	ft_putstr("	* * * * * * * * * * * * * * * * * * * * * * * * ");
	ft_putendl("* * * * * * * * * * * * * * * * * * * * * * * * *  *");
	ft_putstr("	*                                              ");
	ft_putendl("                                                    *");
	ft_putstr("	*                                              ");
	ft_putendl("                                                    *");
	ft_putstr("	*                                              ");
	ft_putendl("                                                    *");
	ft_putstr("	*   ▄▄▄▄███▄▄▄▄    ▄█  ███▄▄▄▄    ▄█     ▄████████    ");
	ft_putstr("\033[0;31m");
	ft_putstr("▄█    █▄       ▄████████  ▄█        ▄█");
	ft_putstr("\033[0m");
	ft_putendl("       *");
	ft_putstr("	* ▄██▀▀▀███▀▀▀██▄ ███  ███▀▀▀██▄ ███    ███    ███   ");
	ft_putstr("\033[0;31m");
	ft_putstr("███    ███     ███    ███ ███       ███");
	ft_putstr("\033[0m");
	ft_putendl("       *");
	ft_putstr("	* ███   ███   ███ ███▌ ███   ███ ███▌   ███    █▀    ");
	ft_putstr("\033[0;31m");
	ft_putstr("███    ███     ███    █▀  ███       ███");
	ft_putstr("\033[0m");
	ft_putendl("       *");
	ft_putstr("	* ███   ███   ███ ███▌ ███   ███ ███▌   ███         ");
}

void	ft_intro2(void)
{
	ft_putstr("\033[0;31m");
	ft_putstr("▄███▄▄▄▄███▄▄  ▄███▄▄▄     ███       ███");
	ft_putstr("\033[0m");
	ft_putendl("       *");
	ft_putstr("	* ███   ███   ███ ███▌ ███   ███ ███▌ ▀███████████ ");
	ft_putstr("\033[0;31m");
	ft_putstr("▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ███       ███");
	ft_putstr("\033[0m");
	ft_putendl("       *");
	ft_putstr("	* ███   ███   ███ ███  ███   ███ ███           ███   ");
	ft_putstr("\033[0;31m");
	ft_putstr("███    ███     ███    █▄  ███       ███");
	ft_putstr("\033[0m");
	ft_putendl("       *");
	ft_putstr("	* ███   ███   ███ ███  ███   ███ ███     ▄█    ███   ");
	ft_putstr("\033[0;31m");
	ft_putstr("███    ███     ███    ███ ███▌    ▄ ███▌    ▄");
	ft_putstr("\033[0m");
	ft_putendl(" *");
	ft_putstr("	*  ▀█   ███   █▀  █▀    ▀█   █▀  █▀    ▄████████▀    ");
	ft_putstr("\033[0;31m");
	ft_putstr("███    █▀      ██████████ █████▄▄██ █████▄▄██");
	ft_putstr("\033[0m");
}

void	ft_intro(void)
{
	ft_putstr("													");
	ft_putendl("													");
	ft_intro1();
	ft_intro2();
	ft_putendl(" *");
	ft_putstr("	*                                              ");
	ft_putendl("                                                    *");
	ft_putstr("	*                                              ");
	ft_putendl("                                                    *");
	ft_putstr("	*                                              ");
	ft_putendl("                                                    *");
	ft_putstr("	* * * * * * * * * * * * * * * * * * * * * * * * * ");
	ft_putendl("* * * * * * * * * * * * * * * * * * * * * * * *  *");
}
