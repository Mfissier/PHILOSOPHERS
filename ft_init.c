/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:21:15 by mafissie          #+#    #+#             */
/*   Updated: 2022/08/24 00:04:02 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

void	ft_init(t_args *args, char **sstr, int ac)
{
	args->nbr_ph = ft_atoi(sstr[1]);
	args->t_die = ft_atoi(sstr[2]);
	args->t_eat = ft_atoi(sstr[3]);
	args->t_sleep = ft_atoi(sstr[4]);
	if (ac == 6)
	{
		args->t_opt = ft_atoi(sstr[5]);
		if (!args->t_opt)
			ft_error("Option : args <= 0 !");
	}
	if (args->nbr_ph > 62407)
		ft_error("Number of philo overflow !");
	if (!args->nbr_ph)
		ft_error("Number of philo <= 0 !");
	if (args->t_die < 0)
		ft_error("time die < 0 !");
	if (args->t_eat < 0)
		ft_error("time eat < 0 !");
	if (args->t_sleep < 0)
		ft_error("time sleep < 0 !");
}

void	ft_init_philo(t_args *args)
{
	int i;

	i = args->nbr_ph;
	while (i--)
	{
		args->philo[i].frk_r = (i + 1) % args->nbr_ph;
		args->philo[i].frk_l = i;
		args->philo[i].pos = i;
		args->philo[i].args = args;
	}
}

/*
 * 1 2 3
 * . x x
 *
 */

void	ft_display_args(t_args *args, int ac)
{
	ft_putstr_fd("Number of philo :\n", 1);
	ft_putnbr_fd(args->nbr_ph, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Time to die :\n", 1);
	ft_putnbr_fd(args->t_die, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Time to eat : \n", 1);
	ft_putnbr_fd(args->t_eat, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Time to sleep : \n", 1);
	ft_putnbr_fd(args->t_sleep, 1);
	ft_putchar_fd('\n', 1);
	if (ac == 6)
	{
		ft_putstr_fd("Time option :\n", 1);
		ft_putnbr_fd(args->t_opt, 1);
	}
}
