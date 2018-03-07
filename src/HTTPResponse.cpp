#include "HTTPResponse.h"

using std::to_string;

HTTPResponse::HTTPResponse()
{
}
HTTPResponse::~HTTPResponse()
{
}
void HTTPResponse::setVersion(HTTPVersion& version)
{
	this->version = version;
}
void HTTPResponse::setStatus(size_t& status)
{
	this->status = status;
	switch (status) {
	case 200:
		message = "OK";
		break;
	case 201:
		message = "Created";
		break;
	case 400:
		message = "Bad Request";
		break;
	case 403:
		message = "Forbidden";
		break;
	case 404:
		message = "Not Found";
		break;
	case 411:
		message = "Length Required";
		break;
	case 500:
		message = "Internal Server Error";
		break;
	case 501:
		message = "Not Implemented";
		break;
	case 502:
		message = "Bad Gateway";
		break;
	case 505:
		message = "HTTP Version Not Supported";
		break;
	default:
		break;
	}
}
void HTTPResponse::setHeader(vector<HTTPHeader>& header)
{
	this->header = header;
}
void HTTPResponse::setData(string& data)
{
	this->data = data;
}
void HTTPResponse::addHeader(HTTPHeader& header)
{
	this->header.push_back(header);
}
void HTTPResponse::addHeaders(vector<HTTPHeader>& header)
{
	this->header.insert(this->header.end(), header.begin(), header.end());
}
void HTTPResponse::addData(string& data)
{
	this->data += data;
}
HTTPVersion HTTPResponse::getVersion()
{
	return version;
}
size_t HTTPResponse::getStatus()
{
	return status;
}
vector<HTTPHeader> HTTPResponse::getHeader()
{
	return header;
}
string HTTPResponse::getData()
{
	return data;
}
string HTTPResponse::getResponse()
{
	string response="";
	switch (version)
	{
	case HTTP0_9:
		response += "HTTP/0.9";
		break;
	case HTTP1_0:
		response += "HTTP/1.0";
		break;
	case HTTP1_1:
		response += "HTTP/1.1";
		break;
	case HTTP2_0:
		response += "HTTP/2.0";
		break;
	default:
		break;
	}
	response += " "+to_string(status)+" "+message+CRLF;
	for (auto &i : header) {
		response += i.key + ": " + i.value + CRLF;
	}
	response += CRLF + data;
	return response;
}
