#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include "netinet/in.h"
#include "string"

class HTTPServer
{
    public:
        HTTPServer(u_short);
        virtual ~HTTPServer();
        int startUp();
        void error(const char*);
    protected:

    private:
        u_short port;
};


#endif // HTTPSERVER_H
