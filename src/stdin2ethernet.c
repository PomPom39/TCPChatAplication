#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

pthread_t tid[2];
pthread_mutex_t lock;
int count = 0;

struct test {

	int a;
	int b;
};



void *server(void *args) {

	struct test *phello = (struct test *)args;
	printf("\n Value of count inside server a:%d", phello->a);

#if 0
	while(1) {
		pthread_mutex_lock(&lock);
		printf("\n Server is running: %d", count);
		
		count++;
		pthread_mutex_unlock(&lock);
		sleep(1);
	}

#endif
}


void *listen(void *args) {
	
	char string[10];
	while(1) {
		sleep(5);
		pthread_mutex_lock(&lock);
		printf("\n Suspending server execution at count:%d", count);
		printf("\n Enter resume to continue");
		scanf("%s", string);
		if (strcmp(string, "resume") == 0) {
			printf("\n Resuming server thread");
			pthread_mutex_unlock(&lock);

		}
		else {

			printf("Valueof count :%d", count);
			printf("\n Exiting");
			pthread_mutex_unlock(&lock);
			exit(0);
		}
	}


}

int main() {

	struct test hello;
	hello.a = 5;
	printf("\n Structure hello a:%d", hello.a);
	
	int error;
	printf("\n Hello World");

	if ( pthread_mutex_init(&lock, NULL) != 0) {
		printf("Mutex init failed");
		return 1;
	}

	if ((error = pthread_create(&tid[0], NULL, &server, (void *)&hello)) != 0){
		printf("\n Thread 1 cannot be satrted: [%s]", strerror(error));
	}

	//if ((error = pthread_create(&tid[1], NULL, &listen, NULL)) != 0) {
	//	printf("\n Thread 2 cannot be satrted: [%s]", strerror(error));
	//}

	pthread_join(tid[0], NULL);
	//pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}