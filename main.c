#include "hdr/json_parse.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>


void error(const char *msg)
{
    perror(msg);
    exit(1);
}

//In the main there is a simple example!

int main(int argc, char** argv){

	int nid=2323;
	char *message;
	message = malloc(1024*sizeof(char));
	json_message(nid, "stored", &message);	//creates json message with nid and of type "stored", and store it to message;
	puts(message);				//print the result
}

