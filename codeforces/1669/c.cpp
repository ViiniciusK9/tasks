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

    int t;

    cin >> t;   
    int n;
    vi v;
    while (t--)
    {
        v.clear();
        cin >> n;
        int aux;
        int p1, p2;
        int flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (i == 0) {
                p1 = aux%2;
            } else if (i == 1) {
                p2 = aux%2;
            }

            if (i % 2 == 0 && (aux % 2) != p1) {
                flag = false;
            }
            if (i % 2 != 0 && (aux % 2) != p2) {
                flag = false;
            }
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome