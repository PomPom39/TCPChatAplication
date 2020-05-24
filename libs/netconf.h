#ifndef _NETCONF_H_
#define _NETCONF_H_

#define DEBUG


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


#ifdef DEBUG
#define dbgprint(x) \
	printf("\n [DEBUG]:%s:%d: ", __FUNCTION__, __LINE__); \
	printf x
#else
	#define dbgprint(x) asm("nop")
#endif


typedef struct netconf {
	int sockfd;
	int connfd;
	struct sockaddr_in servAddr;
	struct sockaddr_in cliAddr;
	int port;

}netconf_t;



extern void netInit(struct netconf *servObj, int debug);
extern void netBind(struct netconf *servObj);
extern void netListen(struct netconf *servObj);



#endif