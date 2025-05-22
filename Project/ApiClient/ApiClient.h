#ifndef APICLIENT_H
#define APICLIENT_H

#include <string>
using namespace std;

class ApiClient {
public:
    static string Post(const string& endpoint, const string& jsonData ,const string &);
    static string extract(const string & json ,const string & key);
    static string Get(const string& endpoint, const string& token);

};

#endif
