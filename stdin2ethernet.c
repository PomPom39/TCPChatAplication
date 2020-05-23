#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

pthread_t tid[2];
pthread_mutex_t lock;
int count = 0;

void *server(void *args) {

	while(1) {
		pthread_mutex_lock(&lock);
		printf("\n Server is running: %d", count);
		count++;
		pthread_mutext_unlock(&lock);
	}


}


void *listen(void *args) {
	sleep(5);
	char string[10];
	while(1) {
		pthread_mutex_lock(&lock);
		printf("\n Suspending server execution at count:%d", count);
		printf("\n Enter resume to continue");
		scanf("%s", string);
		if (strcmp(string, "resume") == 0) {
			printf("\n Resuming server thread");
			pthread_mutext_unlock(&lock)

		}
		else {
			printf("Valueof count :%d", count);
			printf("\n Exiting");
			pthread_mutext_unlock(&lock)
			exit();
		}
	}


}

int main() {

	
	int error;
	printf("Hello World");

	if ( pthread_mutex_init(&lock, NULL) != 0) {
		printf("Mutex init failed");
		return 1;
	}

	if ((error = pthread_create(&tid[0], NULL, &server, NULL)) != 0) {
		printf("\n Thread 1 cannot be satrted: [%s]", strerror(error));
	}

	if ((error = pthread_create(&tid[1], NULL, &listen, NULL)) != 0) {
		printf("\n Thread 2 cannot be satrted: [%s]", strerror(error));
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}