#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int x = 2 ;

void* routine()
{
	x++;
	sleep(2);
	printf("Incrementation with processes: %d\n", x);
}

void* routine2()
{
	sleep(2);
	printf("Incrementation with processes: %d\n", x);
}

int main(int agrc, char* argv[]) 
{ 
	pthread_t t1, t2;
	
	// Explain, why we don't do if (pthread_create()!= )  { return 1; } Like we do with if (pthread_join()) !=0 { return 3; };
	// Explain, why we need &resources and not resources?
	if (pthread_create(&t1, NULL, &routine, NULL))  {
		return 1;
	};
	if (pthread_create(&t2, NULL, &routine2, NULL))  {
		return 2;
	};
	if (pthread_join(t1, NULL)) {
		return 3;
	};
	if (pthread_join(t2, NULL)) {
		return 4;
	};
    return 0;
}

