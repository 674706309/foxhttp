#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include "string"
#include "vector"
#include "http.h"

using std::string;
using std::vector;

class HTTPRequest
{
    public:
        HTTPRequest();
        virtual ~HTTPRequest();
        void setMethod(HTTPMethod&);
        void setUrl(string&);
        void setVersion(HTTPVersion&);
        void setHeader(vector<HTTPHeader>&);
        void setData(string&);
        void addHeader(HTTPHeader&);
        void addHeaders(vector<HTTPHeader>&);
        void addData(string&);
        HTTPMethod getMethod();
        string getUrl();
        HTTPVersion getVersion();
        vector<HTTPHeader> getHeader();
        string getData();
        string getRequest();
        void parseRequest(string&);
    protected:

    private:
    	HTTPMethod method;
        string url;
        HTTPVersion version;
        vector<HTTPHeader> header;
        string data;
};

#endif // HTTPREQUEST_H
