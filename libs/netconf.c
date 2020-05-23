
#include "netconf.h"


void netInit(struct netconf *servObj) {

	printf("\n Inside netInit");
	printf("\n Server PORT = %d", servObj->port);
	servObj->port = 6666;
	
	
	int retVal;
	
	char *welcomeMsg = "Welcome to the UDP server";
	struct sockaddr_in servAddr, cliAddr;


	//Creating the socket 
	if ((servObj->sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("\n Creation of socket failed");
		exit(EXIT_FAILURE);
	}
	printf("\n Server socket created succesfully...");
	
	//Initializing the server and client sockaddr structures
	memset(&servObj->servAddr, 0, sizeof(servObj->servAddr));
	memset(&servObj->cliAddr, 0, sizeof(servObj->cliAddr));
	printf("\n Initialized structures...");
	
	//Filling the server information
	servObj->servAddr.sin_family	= AF_INET; //IPv4 Protocol
	servObj->servAddr.sin_addr.s_addr = INADDR_ANY;
	servObj->servAddr.sin_port = htons(servObj->port);

	
	//Binding the socket with the server address
	if (bind(servObj->sockfd, (const struct sockaddr *)&servObj->servAddr, sizeof(servObj->servAddr)) < 0) {
		perror("\n Binding Failed");
		exit(EXIT_FAILURE);
	}
	printf("\n Binding succesfull...");
	#if 0

	//Recieve a connection and output details regarding the connection
	retVal = recvfrom(sockfd, (char *)buff, MAXSIZE, MSG_WAITALL, (struct sockaddr *)&cliAddr, sizeof(cliAddr));
	buff[sizeof(cliAddr)] = '\0';
	printf("Client : %s \n", buff);
	sendto(sockfd, (const char *)welcomeMsg, strlen(welcomeMsg), MSG_CONFIRM, (struct sockaddr *)&cliAddr, sizeof(cliAddr));
	printf("Hello message sent");
	#endif

}