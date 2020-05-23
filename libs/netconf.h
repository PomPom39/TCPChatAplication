#ifndef _NETCONF_H_
#define _NETCONF_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define PORT 12345
#define MAXSIZE 1024


typedef struct netconf {
	int sockfd;
	struct sockaddr_in servAddr;
	struct sockaddr_in cliAddr;
	int port;

}netconf_t;



extern void netInit(struct netconf *servObj);



#endif