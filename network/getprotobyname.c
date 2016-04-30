#include <netdb.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
   struct protoent *p = getprotobyname("PF_INET");

	if ( p ) 
		printf("s");

	return 1;
}
