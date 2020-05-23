#include <stdio.h>
#include <stdlib.h>
#include "../libs/netconf.h"

netconf_t servObj;

int main(int argc, char* argv[]) {

	printf("\n Hello World");

	servObj.port = 12345;
	netInit(&servObj); 		//Initialize the server

	printf("\n port changed to %d", servObj.port);

}