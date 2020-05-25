


#include <stdio.h>
#include <stdlib.h>
#include "../libs/netconf.h"
#include <pthread.h>
#include <string.h>


netconf_t servObj;
pthread_t tid[3];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;




void usage() {

	printf("\n ");
	printf("\n Usage: mainApp -m [MODE] -i [IP_ADDRESS] -p [PORT]");
	printf("\n [MODE]: 'server' or 'client' ");
	printf("\n [IP_ADDRESS] :if client then IP to connect to");
	printf("\n [PORT]: port no to connect or to host" );

	printf("\n");
	exit(1);
}


void *cliThread(void *args) {
	int cSock = *((int *)args);
	char message[80] = "Authenticated";
	//Sending message to client, telling we have recieved your connection
	pthread_mutex_lock(&lock);
	write(cSock, message, sizeof(message));
	pthread_mutex_unlock(&lock);

	for(;;){}


}

int main(int argc, char **argv) {


	char c;
	int err;
	char *mode, *ip;
	int mflag=0, pflag=0, iflag=0, errflag=0;
	int modeflag = 0;
	char *port;
	int cliSock[3];
	char clientname[100];

	if (argc < 3) {
		usage();
		exit(1);
	}

	while ((c = getopt(argc, argv, ":m:p:i:")) != -1) {
		switch(c) {
			case 'm':
				mflag = 1;
				if (strcmp ("server", optarg) == 0) {
					iflag = 1;
					modeflag = 1;
				}
				else if (strcmp ("client", optarg) == 0) {
					iflag = 0;
				}
				else {
					errflag = 1;
				}
				mode = optarg;
				break;
			case 'p':
				pflag = 1;
				port = optarg;
				break;
			case 'i':
				if (!iflag) {
					iflag = 1;
					ip = optarg;
				}
				break;
			case '?':
				errflag = 1;
				printf("\n Unknown argument");
				usage();
				break;
		}

	}
		
	if (mflag == 0 || pflag == 0) {
		printf("\n Missing arguments");
		usage();
	}

	if (iflag == 0) {
		printf("\n Missing IP");
		usage();
	}
		
	if (errflag == 1) {
		printf("\n Wrong arguments, please check");
		usage();
	}


	printf("\n m=%s \n p=%s \n i =%s \n err=%d", mode, port, ip, err);



	if (modeflag == 1) {
	/* Server Code Implemetation */
	

	servObj.port = atoi(port);



	
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


else {
	/* Client Code (not yet implemeted)*/
	printf("\n Not yet implemented");

}

}