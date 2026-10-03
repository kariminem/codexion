#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


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
	printf("current time in seconds --> %ld\n", time_container.tv_sec);
	printf("current time in milliseconds --> %ld\n", ((time_container.tv_sec * 1000) + (time_container.tv_usec / 1000)));
    printf("current time in micro seconds --> %d\n", time_container.tv_usec);

	return(((time_container.tv_sec * 1000) + (time_container.tv_usec / 1000)) - *curr_time);
}
int main()
{
    long curr_time = init_time();

    // do smth
    sleep(5);

    printf("time --> %lu\n", get_time_ms(&curr_time));


}