/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:48:05 by mafissie          #+#    #+#             */
/*   Updated: 2022/08/24 00:13:01 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H 
# define PHILO_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

struct	s_args;

typedef struct	s_thread
{
	int				pos;
	int				frk_l;
	int				frk_r;
	struct s_args	*args;
	pthread_t		thread;
}				t_thread;

typedef struct	s_args
{
	int					nbr_ph;
	int 				t_die;
	int 				t_eat;
	int					t_sleep;
	int					t_opt;
	int					index;
	pthread_mutex_t 	lock[62407];
	t_thread			philo[62407];
}				t_args;

void	ft_init_philo(t_args *args);

void	ft_error(char *str);
void	ft_init(t_args *args, char **sstr, int ac);
void	ft_display_args(t_args *args, int ac);
void	*ft_thread_start(void *args);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

#endif
