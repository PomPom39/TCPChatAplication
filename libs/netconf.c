
#include "netconf.h"


void netInit(struct netconf *servObj, int debug) {

	printf("\n Value of debug = %d", debug);
	dbgprint(("Inside netInit"));
	dbgprint(("Server PORT = %d", servObj->port));
	
	int retVal;
	
	char *welcomeMsg = "Welcome to the TCP server";
	struct sockaddr_in servAddr, cliAddr;


	//Creating the socket 
	if ((servObj->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("\n Creation of socket failed");
		exit(EXIT_FAILURE);
	}
	dbgprint(("Server socket created succesfully..."));
	
	//Initializing the server and client sockaddr structures
	memset(&servObj->servAddr, 0, sizeof(servObj->servAddr));
	memset(&servObj->cliAddr, 0, sizeof(servObj->cliAddr));
	dbgprint(("Initialized structures..."));
	
	//Filling the server information
	servObj->servAddr.sin_family	= AF_INET; //IPv4 Protocol
	servObj->servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servObj->servAddr.sin_port = htons(servObj->port);

}


void netBind(struct netconf *servObj) {	
	//Binding the socket with the server address
	if (bind(servObj->sockfd, (const struct sockaddr *)&servObj->servAddr, sizeof(servObj->servAddr)) < 0) {
		perror("\n Binding Failed");
		exit(EXIT_FAILURE);
	}
	dbgprint(("Binding succesfull..."));

}

void netListen(struct netconf *servObj) {
	if ((listen(servObj->sockfd, 3)) != 0) {
		perror("\n Listen Failed...");
		exit(EXIT_FAILURE);
	}
	dbgprint(("Server listening... "));
}

void netAccept(struct netconf *servObj) {

	int cliSize = sizeof(servObj->cliAddr);
	if ((servObj->connfd = accept(servObj->sockfd, (struct sockaddr *)&servObj->cliAddr, &cliSize)) < 0) {
		perror("\n Server accept failed");
	}
}
	#if 0

	//Recieve a connection and output details regarding the connection
	retVal = recvfrom(sockfd, (char *)buff, MAXSIZE, MSG_WAITALL, (struct sockaddr *)&cliAddr, sizeof(cliAddr));
	buff[sizeof(cliAddr)] = '\0';
	dbgprint("Client : %s \n", buff);
	sendto(sockfd, (const char *)welcomeMsg, strlen(welcomeMsg), MSG_CONFIRM, (struct sockaddr *)&cliAddr, sizeof(cliAddr));
	dbgprint("Hello message sent");
	#endif

