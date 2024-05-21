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

    int t, x, y;

    cin >> t;

    while (t--)
    {
        cin >> x >> y;

        int ans = 0;
        int tela = y / 2;

        int qnt = tela * 7;

        if (y % 2 != 0) {
            tela++;
            qnt += 7 + 4;
        }

        if (qnt >= x) {
            cout << tela << '\n';
        } else {
            tela += (x - qnt) / 15;
            if ((x - qnt) % 15 != 0) {
                tela++;
            }
            cout << tela << '\n';
        }


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome