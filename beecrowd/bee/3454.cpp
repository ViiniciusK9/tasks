#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int cont = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'X') cont++;
    }
    
    if (cont != 2) {
        cout << "?\n";
    } else {
        if (s[1] == 'X') {
            cout << "Alice\n";
        } else {
            cout << "*\n";
        }
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome