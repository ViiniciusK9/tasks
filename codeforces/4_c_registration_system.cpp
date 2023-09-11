#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int vet[51];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    map<string, int> m;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (!m[s])
        {
            m[s]++;
            cout << "OK\n";
        } 
        else
        {
            cout << s << + m[s] << '\n';
            m[s]++;
        }
    }
    


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome