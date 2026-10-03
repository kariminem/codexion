#include "codexion.h"

long	init_time()
{
	struct timeval start;
	gettimeofday(&start,NULL);
	return((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

long	get_time_ms(long *curr_time)
{
    // long curr_time = init_time();
	struct timeval time_container;
	gettimeofday(&time_container,NULL);
	
	return(((time_container.tv_sec * 1000) + (time_container.tv_usec / 1000)) - *curr_time);
}