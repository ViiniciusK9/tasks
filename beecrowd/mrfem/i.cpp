#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 8;
    int a = 0;
    int aux;

    for (int i = 0; i < n-1; i++)
    {
        cin >> aux;
        if (aux == 1) {
            a++;
        }
    }
    cin >> aux;
    if (a%2 == 0 && aux != 0) {
        cout << "S\n";
    } else if (a%2 != 0 && aux == 0) {
        cout << "S\n";
    } else {
        cout << "N?\n";
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome