#include <iostream>

using namespace std;

int DivFunc(int * iPtr);

int main()
{
    string Str1 = "Ping";
    string Str2 = "Pong";


    for(int i = 1; i <= 100; i++)
    {
        if ((i % 2 == 0) && (i % 3 == 0)) { cout << i << "\t" << Str1 << Str2 << endl; break; }
        if (i % 2 == 0) cout << i << "\t" << Str1 << endl;
        else if (i % 3 == 0) cout << i << "\t" << Str2 << endl;
        else cout << i << "\t" << i << endl;
    }

    return 0;
}

int DivFunc(int * iPtr)

{
    int n = 1;

    if ((*iPtr % 2 == 0) && (*iPtr % 3 == 0)) { n=4; return n; }
    if (*iPtr % 2 == 0) n=2;
    if (*iPtr % 3 == 0) n=3;

    return n;
}

//  if (i % 2 == 0) cout << i << " - " << Str1;
//  if (i % 3 == 0) cout << i << " - " << Str2;



