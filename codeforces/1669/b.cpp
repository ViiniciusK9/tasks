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

        while (t--)
        {
            cin >> n;
            map<int, int> ma;
            int aux;
            for (int i = 0; i < n; i++)
            {
                cin >> aux;
                ma[aux]++;
            }

            bool flag = true;
            for (auto v : ma)
            {
                if (v.second >= 3) {
                    cout << v.first << '\n';
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << "-1\n";
            }
            
            
        }
        

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome