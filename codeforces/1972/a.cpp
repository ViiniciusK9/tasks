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

    int n, aux;
    int t;
    vi a;
    vi b;
    cin >> t;

    while (t--)
    {
        a.clear();
        b.clear();



        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a.PB(aux);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            b.PB(aux);
        }

        int k = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[k] > b[i]) {
                sum++;
            } else {
                k++;
            }
        }
        
        cout << sum << '\n';
        
    }
    



    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome