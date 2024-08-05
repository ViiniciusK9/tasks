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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {   int n;
        cin >> n;   
        int aux;
        int p1, p2;
        p1 = p2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (aux % 2 == 0) {
                p1++;
            } else {
                p2++;
            }
        }

        if (p2 % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome