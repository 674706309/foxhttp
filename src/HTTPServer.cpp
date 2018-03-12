#include "HTTPServer.h"


HTTPServer::HTTPServer(u_short &port)
{
	this->port = port;
}


HTTPServer::~HTTPServer()
{
}

int HTTPServer::startUp()
{
	int httpd = 0;
	sockaddr_in name;
	httpd = socket(PF_INET,SOCK_STREAM,0);
	if (httpd == -1)
		error("socket");
	memset(&name, 0, sizeof(name));
	name.sin_family = AF_INET;
	name.sin_port = htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(httpd, (struct sockaddr *)&name, sizeof(name)) < 0)
		error("bind");
	if (port == 0)  /* if dynamically allocating a port */
	{
		int namelen = sizeof(name);
		if (getsockname(httpd, (struct sockaddr *)&name, &namelen) == -1)
			error("getsockname");
		port = ntohs(name.sin_port);
	}
	if (listen(httpd, 5) < 0)
		error("listen");
	return (httpd);
}

void HTTPServer()::accept_request(void *arg){


}

void HTTPServer::error(const char *er)
{
	perror(er);
	exit(1);
}
