


#include <stdio.h>
#include <stdlib.h>
#include "../libs/netconf.h"
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <string.h>


netconf_t servObj;
pthread_t tid[3];
pthread_t cltid[2];

char gRBuffer[256];
char gWBuffer[256];
char tmp[256];

int readok = 0;
int writeok = 0;


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t thread1 = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t thread2 = PTHREAD_MUTEX_INITIALIZER;



void sigHandler(int signum) {

	if (signum == SIGUSR1) {
		printf("\n Caught SIGUSR1 Signal");
	}
}


void welcomeMessage() {
printf("\n Welcome to experimental TCP Based Chat Application" );
printf("\n Your are connected");
printf("\n");
}


void usage() {

	printf("\n ");
	printf("\n Usage: mainApp -m [MODE] -i [IP_ADDRESS] -p [PORT]");
	printf("\n [MODE]: 'server' or 'client' ");
	printf("\n [IP_ADDRESS] :if client then IP to connect to");
	printf("\n [PORT]: port no to connect or to host" );

	printf("\n");
	exit(1);
}


void *Thread1(void *args) { //Client side read thread

	int cSock = *((int *)args);
	int readBytes = 0;

  

	while(1) {
	if ((readBytes = read(cSock, gRBuffer, sizeof(gRBuffer))) < 0) {
		printf("\n Read Failed");
	}
	//dbgprint(("\n %d bytes read", readBytes));
	pthread_mutex_lock(&thread1);
	readok = 1;
	pthread_mutex_unlock(&thread1);

	}	

}

void *Thread2(void *args) { //Client side write thread

	int cSock = *((int *)args);
	int writeBytes = 0;

  	//strcpy(gWBuffer, "Hello from client");

	while(writeok) {
		pthread_mutex_lock(&thread2);
		writeok = 0;
		if ((writeBytes = write(cSock, gWBuffer, sizeof(gWBuffer))) < 0) {
			printf("\n Write Failed");
		}
		dbgprint(("\n %d bytes written", writeBytes));
		//sleep(5);
		pthread_mutex_unlock(&thread2);

	}	

}

void *Thread3(void *args) { //Server side read thread
	int cSock = *((int *)args);
	int readBytes = 0;
	printf("\n Inside thread 3");
	fflush(stdout);
	while(1) {
		if ((readBytes = read(cSock, tmp ,sizeof(tmp))) < 0) {
		printf("\n Read Failed");
	}
	printf("\n read bytes %d", readBytes);
	printf("\n %s", tmp);
	fflush(stdout);
	}



}


void *Thread4(void *args) {



	
}





void *cliThread(void *args) {
	int cSock = *((int *)args);
	int fp[2];
	char pipeDir[50];
	char buff[128];
	//A very simple authentication for now
	char message[80] = "Authenticated";
	//Sending message to client, telling we have recieved your connection

	while(1) {
	//write(cSock, message, sizeof(message));
	sleep(5);
	}


	system("clear");
	printf("\n SERVER MODE");
    printf("\n ");
	welcomeMessage();
	//read(cSock, buff, sizeof(buff));
	printf("\n %s", buff);

	
	for(;;){}


}

int main(int argc, char **argv) {

		int temp;
		int clientpid;
	char c;
	int err;
	char *mode, *ip;
	int mflag=0, pflag=0, iflag=0, errflag=0;
	int modeflag = 0;
	char *port;
	int cliSock[3];
	char clientname[100];
	char usrMsg[128];
	char usrBuff[128];

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

	//Assigning server IP to connect for client
	


	if (modeflag == 1) {
	/* Server Code Implemetation */
	servObj.ip = "0";
	servObj.port = atoi(port);

	printf("\n SERVER MODE");
	printf("\n Initializing TCP Server Network Parameters");
	netInit(&servObj); 		//Initialize the server

	printf("\n Binding the server...");
	netBind(&servObj);

	printf("\n Listening for conenctions");
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
		if (pthread_create(&tid[i], NULL, Thread3, (void *)&cliSock[i]) != 0) {
			printf("\n Failed to create thread");
		}
		/*
		if (pthread_create(&tid[i], NULL, Thread2, (void *)&cliSock[i]) != 0) {
			printf("\n Failed to create thread");
		}*/
		printf("\n Thread %d created", i);
		fflush(stdout);
	}


	fflush(stdout);


	while (1) {
		//sleep(1);	/* While loop spo that it doesnt exit*/
	}

}


else {
	/* Client Code (not yet implemeted)*/
	//printf("\n Not yet implemented");

	servObj.ip = ip;
	servObj.port = atoi(port);
	printf("\n Initializing TCP Client Network Parameters");
	netInit(&servObj); 	

	printf("\n Connecting to server...");
	/*if (connect(servObj.sockfd, (const struct sockaddr *)&servObj.servAddr, sizeof(servObj.servAddr)) != 0) { 
        perror("\n Connection with the server failed...\n"); 
        exit(0); 
    } */
    netConnect(&servObj);
    printf("\n Connected");
    printf("\n Clearning screen and opening chat");
    printf("\n CLIENT MODE");
    printf("\n ");
    welcomeMessage();

  	if (pthread_create(&cltid[0], NULL, Thread1, (void *)&servObj.connfd )!= 0) {
		printf("\n Thread creating failed");
	}

	if (pthread_create(&cltid[1], NULL, Thread2, (void *)&servObj.connfd )!= 0) {
		printf("\n Thread creating failed");
	}


	while(1) {
		while (readok) {

			pthread_mutex_lock(&thread1);
			printf("USER1>>>%s", gRBuffer);
			fflush(stdout);
			readok = 0;
			pthread_mutex_unlock(&thread1);

		}

		while(!writeok) {
			pthread_mutex_lock(&thread2);
			gWBuffer[0] = '\0';
			scanf("%s", gWBuffer);
			writeok = 1;;
			pthread_mutex_unlock(&thread2);

		}
	}




	/*
    read(servObj.connfd, usrBuff, sizeof(usrBuff));
    printf("\n %s", usrMsg);
    

    fflush(stdout);
    printf("\n User1>");
    scanf("%s", usrMsg);
    //write(servObj.connfd, usrMsg, sizeof(usrMsg));
    //printf("\n Spawning recieve message thread");
    fflush(stdout);
	*/

}

}