#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);

	printf("%ld\n", tv.tv_sec);
	printf("%ld\n", tv.tv_usec);
	return (0);
}
