#ifndef Evaluator_h
#define Evaluator_h
#include "../User/User.h"

class Evaluator
{
private:
    User user;

public:
    void boot();
    void bootstrap();
    void shutDown(const int & );
    void auth();
};

#endif
