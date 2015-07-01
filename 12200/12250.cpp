#include <iostream>

using namespace std;

int main()
{
    int t=0;
    string in;
    while(cin>>in)
    {
        t++;
        if(in=="#")
        {
            break;
        }
        else
        {
            cout<<"Case "<<t<<": ";
            if(in=="HELLO")
                cout<<"ENGLISH\n";
            else if(in=="HOLA")
                cout<<"SPANISH\n";
            else if(in=="HALLO")
                cout<<"GERMAN\n";
            else if(in=="BONJOUR")
                cout<<"FRENCH\n";
            else if(in=="CIAO")
                cout<<"ITALIAN\n";
            else if(in=="ZDRAVSTVUJTE")
                cout<<"RUSSIAN\n";
            else 
                cout<<"UNKNOWN\n";
        }
        
    }
    return 0;
}
