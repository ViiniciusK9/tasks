#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long v = 1, pro, at;

    at = 2;
    long long i = 1;

    while (at < 10e18 && at > 0 )
    {   
        pro = (i + 1) * 2;
        at += pro + i;
        //cout << at << '\n';
        i++;
        cout << i  << " : " << at << '\n';
        if (i == 101)
        {
            break;
        }
        
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome