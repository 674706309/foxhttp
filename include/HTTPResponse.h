#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "string"
#include "vector"
#include "http.h"

using std::string;
using std::vector;

class HTTPResponse
{
    public:
        HTTPResponse();
        virtual ~HTTPResponse();
	void setVersion(HTTPVersion&);
	void setStatus(size_t&);
	void setHeader(vector<HTTPHeader>&);
	void setData(string&);
	void addHeader(HTTPHeader&);
	void addHeaders(vector<HTTPHeader>&);
	void addData(string&);
	HTTPVersion getVersion();
	size_t getStatus();
	vector<HTTPHeader> getHeader();
	string getData();
	string getResponse();
    protected:

    private:
    	HTTPVersion version;
	size_t status;
	string message;
	vector<HTTPHeader> header;
	string data;
};

#endif // HTTPRESPONSE_H
