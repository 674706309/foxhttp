#ifndef HTTP_H_INCLUDED
#define HTTP_H_INCLUDED

#define CR '\r'
#define LF '\n'
#define CRLF "\r\n"
#include "string"
#include "vector"

using std::string;
using std::vector;

struct HTTPHeader
{
	string key, value;
	HTTPHeader(string& s1,string& s2){
        key=s1;
        value=s2;
	}
};
enum HTTPMethod
{
	GET, POST, PUT, HEAD
};
enum HTTPVersion
{
	HTTP0_9, HTTP1_0, HTTP1_1, HTTP2_0
};
vector<string> split(const string& s, const string& c)
{
    vector<string> result;
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        result.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        result.push_back(s.substr(pos1));
    return result;
}
#endif // HTTP_H_INCLUDED
