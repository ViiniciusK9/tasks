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

    map<int, int> ma;
    int q;
    cin >> q;
    while (q--)
    {
        
        int n, x;
        cin >> n;
        if (n == 1) {
            cin >> x;

            
            ma[x]++;

        } else if (n == 2) {
            cin >> x;

            ma[x]--;
            if (ma[x] == 0) {
                ma.erase(x);
            }

        } else if (n == 3) {
            cout << ma.size() << '\n';
        }
    }


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome