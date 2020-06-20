


#include <stdio.h>
#include <stdlib.h>
//#include "../libs/netconf.h"
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <string.h>
#include "s2e_ess.c"
#include <getopt.h>

//netconf_t servObj;
pthread_t tid[3];
pthread_t cltid[2];

char netRBuff[256];
char netWBuff[256];
char tmp[256];

int readok = 0;
int writeok = 0;


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t thread1 = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t thread2 = PTHREAD_MUTEX_INITIALIZER;


struct s2e_conf net_conf;
fd_set READSET, WRITESET;
struct timeval timeout; 



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



int main(int argc, char **argv) {

	int ret;
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


	//printf("\n m=%s \n p=%s \n i =%s \n err=%d", mode, port, ip, err);
	

	if (modeflag == 1) {
		net_conf.net_mode = NET_MODE_SERVER;
		net_conf.net_proto = NET_PROTO_TCP;
		net_conf.net_port = atoi(port);
		net_open(&net_conf);

	}


	else {


	net_conf.net_mode = NET_MODE_CLIENT;
	net_conf.net_proto = NET_PROTO_TCP;
	net_conf.net_port = atoi(port);
	strcpy(net_conf.net_remote_ip, ip);
	net_open(&net_conf);

	}
	printf("\n Address of structure is 0x%x", &net_conf);
	if ((ret = Authenticate(&net_conf)) < 0) 
		printf("\n Authentication failed");
	else
		printf("\n Authenticqation OK");





}



void Authenticate(struct s2e_conf *conf) {

	int net_write_size = 0;
	int net_read_size = 0;
	char password[] = "PASS";
	int ret;
	int retry = 5;
	int sock_fd;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	printf("\n Address of structure inside func is 0x%x", conf);

	sock_fd = conf->sock_fd;
	FD_ZERO(&READSET);
	FD_ZERO(&WRITESET);
	if (conf->net_mode == NET_MODE_SERVER) 
		FD_SET(sock_fd, &WRITESET);
	else
		FD_SET(sock_fd, &READSET);

	while (retry) {
		if ((ret = select(sock_fd + 1, &READSET, &WRITESET, NULL, &timeout)) < 0) {
			perror("\n Select failed");
			return -1;
		}

		if (ret == 0) {
			perror("Timed Out(5 secs), retrying...");
			timeout.tv_sec = 5;
			retry--;
			continue;
		}

		if (FD_ISSET(sock_fd, &WRITESET)) {
			if((ret = net_write(conf, password, sizeof(password))) < 0) {
				perror("\n write failed");
				return -1;
			}
			return 0;
		}

		if(FD_ISSET(sock_fd, &READSET)) {
			if ((ret = net_read(conf, netRBuff, sizeof(netRBuff))) < 0) {
				perror("\n read failed");
				return -1;
			}
			printf("\n Read string = %s", netRBuff);	
		}
	
		//Checking Authentication(/Simple authnetication for now)
		if((ret = strcmp(netRBuff, password)) == 0) {
			printf("\n Authneticated....");
			return 0;
			retry = 0;
			continue;
		}
		return -1;
	}


}