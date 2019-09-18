#include "minishell.h" 

void	ft_intro1()
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

void	ft_intro2()
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
void	ft_intro()
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