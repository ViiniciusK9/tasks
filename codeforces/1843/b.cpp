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
        int n;
        cin >> n;
        vi v;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            v.pb(aux);
        }

        int op = 0;
        int ant = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum+=abs(v[i]);
            if (v[i] < 0 && ant == 0) {
                op++;
                ant = 1;
            } else if (v[i] >= 1) {
                ant = 0;
            }
        }


        cout << sum <<" " << op << '\n';


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome