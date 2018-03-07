#include "HTTPRequest.h"

HTTPRequest::HTTPRequest()
{
}
HTTPRequest::~HTTPRequest()
{
}
void HTTPRequest::setMethod(HTTPMethod &method)
{
	this->method = method;
}
void HTTPRequest::setUrl(string &url)
{
	this->url = url;
}
void HTTPRequest::setVersion(HTTPVersion &version)
{
	this->version = version;
}
void HTTPRequest::setHeader(vector<HTTPHeader> &header)
{
	this->header = header;
}
void HTTPRequest::setData(string &data)
{
	this->data = data;
}
void HTTPRequest::addHeader(HTTPHeader &header)
{
	this->header.push_back(header);
}
void HTTPRequest::addHeaders(vector<HTTPHeader>& header)
{
	this->header.insert(this->header.end(),header.begin(),header.end());
}
void HTTPRequest::addData(string &data)
{
	this->data += data;
}
HTTPMethod HTTPRequest::getMethod()
{
	return method;
}
string HTTPRequest::getUrl()
{
	return url;
}
HTTPVersion HTTPRequest::getVersion()
{
	return version;
}
vector<HTTPHeader> HTTPRequest::getHeader()
{
	return header;
}
string HTTPRequest::getData()
{
	return data;
}
string HTTPRequest::getRequest()
{
	string request="";
	switch (method)
	{
	case GET:
		request += "GET";
		break;
	case POST:
		request += "POST";
		break;
	case PUT:
		request += "PUT";
		break;
	case HEAD:
		request += "HEAD";
		break;
	default:
		break;
	}
	request += " "+url+" ";
	switch (version)
	{
	case HTTP0_9:
		request += "HTTP/0.9";
		break;
	case HTTP1_0:
		request += "HTTP/1.0";
		break;
	case HTTP1_1:
		request += "HTTP/1.1";
		break;
	case HTTP2_0:
		request += "HTTP/2.0";
		break;
	default:
		break;
	}
	request += CRLF;
	for (auto &i:header) {
		request += i.key + ": " + i.value + CRLF;
	}
	request += CRLF + data;
	return request;
}
