
#include <iostream>


using namespace std;

int main()
{
    string StrIn;// = "1234567890123456789q";
    string StrOut;
    char *pEnd;
    int SizeStr = 0;
    long long ResultNumber = 0;

//        cin >> StrIn;
        getline(cin, StrIn);
        SizeStr = StrIn.size();

        for(int i = 0; i < SizeStr; i++)
        {
            if (isdigit(StrIn[i])) StrOut.push_back(StrIn[i]);
            else break;
        }
        ResultNumber = std::strtoll(StrOut.c_str(), &pEnd, 10);

        cout << ResultNumber << endl;

    return 0;
}
