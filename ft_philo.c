/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:06:36 by mafissie          #+#    #+#             */
/*   Updated: 2022/08/24 20:35:13 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"
#include <stdio.h>
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

void	ft_mutex(t_thread *philosopher)
{
	t_args *all_args;

	all_args = philosopher->args;
	pthread_mutex_lock(&(all_args->lock[philosopher->frk_l]));
	printf("l = %d \n", philosopher->pos);
	pthread_mutex_lock(&(all_args->lock[philosopher->frk_r]));
	printf("r = %d \n", philosopher->pos);
	pthread_mutex_unlock(&(all_args->lock[philosopher->frk_l]));
	pthread_mutex_unlock(&(all_args->lock[philosopher->frk_r]));
	return ;
}

void	*ft_thread_start(void *philosopher)
{
	t_thread	*philo;
	/* t_args		*all_args; */

	philo = philosopher;
	printf("%d\n", philo->args->nbr_ph);
	if (philo->pos % 2 == 0)
		usleep(1000);
	/* printf("???"); */
	/* ft_mutex(philo); */
	/* ft_putnbr_fd(all_args->nbr_ph, 1); */
	ft_mutex(philo);
	/* pthread_mutex_unlock(&mutex); */
	/* ft_mutex(&tmp->philo[tmp->pos]); */
	/* pthread_mutex_lock(&tmp->philo[tmp->pos].lock); */
	/* ft_putnbr_fd(tmp->m_rules->x, 1); */
	/* ft_putnbr_fd(tmp->pos, 1); */
	/* pthread_mutex_unlock(&tmp->philo[tmp->pos].lock); */
	return (NULL);
}

int	main(int ac, char **av)
{
	t_args args;
	t_thread *philo;

	philo = args.philo;
	(void)philo;
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
	int i = 0;
	if (ac == 5)
		ft_init(&args, av, ac);
	else if (ac == 6)
		ft_init(&args, av, ac);
	else
		ft_error("Numbers of args is wrong !");
	ft_init_philo(&args);
	for (i = 0; i < args.nbr_ph; i++)
		pthread_mutex_init(&args.lock[i], NULL);
	for (i = 0; i < args.nbr_ph; i++)
	{
		printf("%d\n", args.philo[i].pos);
		printf("???\n");
		pthread_create(&(args.philo[i].thread), NULL, &ft_thread_start, &args.philo[i]);
	}
	for (i = 0; i < args.nbr_ph; i++)
		pthread_join(args.philo[i].thread, NULL);
	/* for (i = 0; i < args.nbr_ph; i++) */
	/* 	pthread_mutex_destroy(&args.lock[i]); */
	/* pthread_mutex_destroy(&args.lock[i]); */
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

