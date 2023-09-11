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
    if (s.size() == 8)
    {
        cout << "mas\n";
    } 
    else if (s.size() == 13)
    {
        cout << "mas\n";
    }
    else if (s.size() == 10)
    {
        cout << "mais\n";
    }
    else
    {
        cout << "mais\n";
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome