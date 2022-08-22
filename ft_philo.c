/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:06:36 by mafissie          #+#    #+#             */
/*   Updated: 2022/08/22 01:37:07 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"
#include <pthread.h>
/*  */
/* #define NUM_THREADS	5 */
/*  */
/* void *PrintHello(void *threadid){ */
/* 	long tid; */
/* 	tid = (long)threadid; */
/* 	printf("Hello World! It's me, thread #%ld!\n", tid); */
/* 	pthread_exit(NULL); */
/* } */
/*  */
/* int main(int argc, char *argv[]){ */
/* 	pthread_t threads[NUM_THREADS]; */
/* 	int rc; */
/* 	long t; */
/* 	for(t=0;t<NUM_THREADS;t++){ */
/* 		printf("In main: creating thread %ld\n", t); */
/* 		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t); */
/* 		if (rc){ */
/* 			printf("ERROR; return code from pthread_create() is %d\n", rc); */
/* 			exit(-1); */
/* 		} */
/* 	} */
/* 	pthread_exit(NULL); */
/* } */
/*  */

void	*ft_thread_start(void *args)
{
	t_args *tmp;

	tmp = args;
	/* ft_putnbr_fd(tmp->m_rules->x, 1); */
	(void)tmp;
	ft_putstr_fd("philo\n", 1);
	return (NULL);
}

void	ft_init_mutex(t_args *args)
{
	int i;

	i = args->nbr_ph;

	/* while (i--) */
	/* { */
		/* pthread_mutex_init(&(args->philo[i]), NULL); */
	/* } */
}

int	main(int ac, char **av)
{
	t_args args;
	/* t_mutex *mutex; */
    /*  */
	/* pthread_t	*t_philo; */
	/* args = malloc(sizeof(t_args) * 1); */
	/* mutex = malloc(sizeof(t_mutex)); */
	/* args->m_rules = mutex; */
	/* t_philo = malloc(sizeof(pthread_t) * 4); */
	/* (void)mutex; */
	/* int i; */
	/* for (i = 0; i < 4; i++) */
	/* { */
	/* 	pthread_create(t_philo + i, NULL, &ft_thread_start, args); */
	/* 	pthread_join(t_philo[i], NULL); */
	/* } */
	/* for (i = 0; i < 4; i++) */
	/* { */
	/* 	ft_putstr_fd("thread end\n", 1); */
	/* 	pthread_join(t_philo[i], NULL); */
	/* } */
	/* free(t_philo); */
	/* free(mutex); */
	/* free(args); */
	/* (void)av; */
	/* return(0); */
    /*  */
	int i = 0;
	if (ac == 5)
	{
		ft_init(&args, av, ac);
		ft_display_args(&args, ac);
	}
	else if (ac == 6)
	{
		ft_init(&args, av, ac);
		ft_display_args(&args, ac);
	}
	else
		ft_error("Numbers of args is wrong !");
	for (i = 0; i < args.nbr_ph; i++)
	{
		pthread_create(&(args.philo[i].thread), NULL, &ft_thread_start, &args);
		pthread_join(args.philo[i].thread, NULL);
	}
	/* for (i = 0; i < 4; i++) */
	/* { */
	/* 	ft_putstr_fd("thread end\n", 1); */
	/* 	pthread_join(t_philo[i], NULL); */
	/* } */
	
	/* free(args); */
	/* (void)t_philo; */
	return (0);
}

/* 
 * 1 number_of_philosophers 
 * 2 time_to_die 
 * 3 time_to_eat 
 * 4 time_to_sleep 
*/
/* 
 * OPT 4
 * [number_of_times_each_philosopher_must_eat] 
 * 
*/

