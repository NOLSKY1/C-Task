
#include "Output.h"
#include <iostream>
using namespace std;

void Output::Header()
{
    cout << "-- -- --      WELCOME BACK TO     -- -- --" << endl;
    cout << "-- -- -- Restlux Delux Restaurant -- -- --" << endl;
    cout << "              -- -- G37 -- --" << endl;
    cout << "              -- -- --- -- --" << endl;
}
void Output::startUp()
{
    cout << "-> 1. Login" << endl;
    cout << "-> 2. Register" << endl;
    cout << "-> 3. Forgot password" << endl;
    cout << "-> 4. Quite" << endl;
    cout << "===" << endl;
    printInserter();
}
void Output::adminPage(User user)
{
    cout << "=== core.User: " << user.getFirstname() << endl;
    cout << "-> 1. Product managent" << endl;
    cout << "-> 2. Menus management" << endl;
    cout << "-> 3. Categories management" << endl;
    cout << "-> 4. Permissions management" << endl;
    cout << "-> 5. Quit" << endl;
    cout << "-> 6. Logout" << endl;
    cout << "===" << endl;
    printInserter();
}
void Output::printInserter()
{
    cout << "-> " << endl;
}
void Output::clear()
{
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
}