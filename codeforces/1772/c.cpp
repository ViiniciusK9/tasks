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
    {
        int n, k;
        cin >> k >> n;

        vi v = {1, 2, 4, 7, 11, 16, 22, 29, 37};
        set<int> aux;
        for (int i = 0; i < v.size(); i++)
        {
            if (aux.size() == k) {
                break;
            }
            if (n - v[i] <= k - (i+1)) {
                break;
            } else {
                aux.insert(v[i]);
            }
        }

        k-=aux.size();
        int na=n;
        while (k >= 1)
        {
            aux.insert(na);
            na--;
            k--;
        }
        bool fir = true;
        for (auto el : aux)
        {
            cout << (fir ? "" : " ") << el;
            fir = false;
        }
        cout << '\n';
        
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome