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
    int ant = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.') {
            if (ant == 1) {
                cout << "1";
                ant = 0;
            } else {
                cout << "0";
                ant = 0;
            }
        } else if (s[i] == '-') {
            if (ant == 1) {
                cout << "2";
                ant = 0;
            } else {
                ant = 1;
            }
        }
    }
    
    cout << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome