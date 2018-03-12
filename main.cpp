#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include "HTTPServer.h"

using namespace std;

int main()
{
    u_short port= 500;
	int server_sock = -1, client_sock = -1;
	HTTPServer server(port);
	sockaddr_in client_name;
	    pthread_t newthread;
    socklen_t  client_name_len = sizeof(client_name);

	server_sock=server.startUp();
	printf("httpd running on port %d",port);
	while (1)
	{
		client_sock = accept(server_sock,
			(sockaddr *)&client_name,
			&client_name_len);
		if (client_sock == -1)
        server.error("accept");
		/* accept_request(client_sock); */
		if (pthread_create(&newthread, NULL, accept_request, client_sock) != 0)
			perror("pthread_create");
	}

	close(server_sock);
    return 0;
    return 0;
}
