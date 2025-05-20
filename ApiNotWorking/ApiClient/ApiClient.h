#ifndef ApiClient_h
#define ApiClient_h
#include<string>
using namespace std;


class ApiClient{
    public :

    static string Get(const string & endpoint , const string & token ="");
    static string Post(const string& endpoint , const string & jsondata , const string & token ="");
    static string Del(const string & endpoint , const string & token ="");
    static string extract(const string & json ,const string & key);

};









#endif