#ifndef HTTP_H_INCLUDED
#define HTTP_H_INCLUDED

#define CR '\r'
#define LF '\n'
#define CRLF "\r\n"
#include "string"

using std::string;

struct HTTPHeader
{
	string key, value;
};
enum HTTPMethod
{
	GET, POST, PUT, HEAD
};
enum HTTPVersion
{
	HTTP0_9, HTTP1_0, HTTP1_1, HTTP2_0
};

#endif // HTTP_H_INCLUDED
