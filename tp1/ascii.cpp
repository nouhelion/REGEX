//Using a type declaration
//union, write a CTOA function, which reads a
//character and returns the corresponding ascii code.
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
//structure ???? 
union {
    char c;
    unsigned i;
}p;
void CTOA(){
    p.i=0;
    cout << "Enter the phrase :" << endl;
    cin>>p.c;
    cout<<"ASCII code : "<<p.i<< endl;
}

int main(int argc, char **argv)
{
    CTOA();
    system("pause");
    return 0;
}