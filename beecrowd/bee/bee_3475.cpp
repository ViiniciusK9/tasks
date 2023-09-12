#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    if (s.length() > 1)
    {
        if (s == "zero")
        {
            cout << "0\n";
        } else if (s == "um")
        {
            cout << "1\n";
        } else if (s == "dois")
        {
            cout << "2\n";
        } else if (s == "tres")
        {
            cout << "3\n";
        } else if (s == "quatro")
        {
            cout << "4\n";
        } else if (s == "cinco")
        {
            cout << "5\n";
        } else if (s == "seis")
        {   
            cout << "6\n";
        } else if (s == "sete")
        {
            cout << "7\n";
        } else if (s == "oito")
        {
            cout << "8\n";
        } else
        {
            cout << "9\n";
        }
        
    }
    else
    {
        switch (s[0])
        {
        case '0':
            cout << "zero\n";
            break;
        
        case '1':
            cout << "um\n";
            break;
        case '2':
            cout << "dois\n";
            break;
        case '3':
            cout << "tres\n";
            break;
        case '4':
            cout << "quatro\n";
            break;
        case '5':
            cout << "cinco\n";
            break;
        case '6':
            cout << "seis\n";
            break;
        case '7':
            cout << "sete\n";
            break;
        case '8':
            cout << "oito\n";
            break;
        case '9':
            cout << "nove\n";
            break;
        }
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome