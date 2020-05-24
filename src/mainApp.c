


#include <stdio.h>
#include <stdlib.h>
#include "../libs/netconf.h"
#include <pthread.h>



netconf_t servObj;
pthread_t tid[3];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


void *cliThread(void *args) {
	int cSock = *((int *)args);
	char message[80] = "Authenticated";
	//Sending message to client, telling we have recieved your connection
	pthread_mutex_lock(&lock);
	write(cSock, message, sizeof(message));
	pthread_mutex_unlock(&lock);

	for(;;){}


}

int main(int argc, char* argv[]) {

	int cliSock[3];
	printf("\n Hello World");
	char clientname[100];


	servObj.port = 12345;
	
	printf("\n Initializing TCP Network Parameters");
	netInit(&servObj, 1); 		//Initialize the server

	printf("\n Binding the server...");
	netBind(&servObj);
	netListen(&servObj);

	//Accepting the connection
	int cliSize = sizeof(servObj.cliAddr);

	//Creating seperate threads for each client joined, max 3 clients as of now

	for (int i=0; i < 2; i++) {
		if ((cliSock[i] = accept(servObj.sockfd, (struct sockaddr *)&servObj.cliAddr, &cliSize)) < 0) {
		perror("\n Server accept failed");
		}
		printf("\n Server Accept succesfull..");
		printf("\n Connected client : %s", inet_ntop(AF_INET, &servObj.cliAddr.sin_addr, clientname, sizeof(clientname)));
		if (pthread_create(&tid[i], NULL, cliThread, (void *)&cliSock[i]) != 0) {
			printf("\n Failed to create thread");
		}
		printf("\n Thread %d created", i);
		fflush(stdout);
}


fflush(stdout);


	while (1) {
		sleep(1);
	}

}