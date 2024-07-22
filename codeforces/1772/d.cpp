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
        int n, aux;
        cin >> n;
        vi v;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }
        int ant = v[0];
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (ant > v[i]) {
                flag = false;
                break;
            }
            ant = v[i];
        }

        if (flag) {
            cout << "0\n";
            continue;
        }

        ant = v[n-1];
        flag = true;
        for (int i = n-1; i >= 0; i--)
        {
            if (ant > v[i]) {
                flag = false;
                break;
            }
            ant = v[i];
        }

        if (flag) {
            cout << v[0] << '\n';
            continue;
        }
        

        // solve
        int mx = 0;
        int mi = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, v[i]);
            mi = min(mi, v[i]);
        }
        vi arr;
        int val = (mx+mi)/2 + ((mx+mi)%2);
        for (int i = 0; i < n; i++)
        {
            arr.pb(abs(v[i] - val));
        }
        
        ant = arr[0];
        flag = true;
        for (int i = 0; i < n; i++)
        {
            if (ant > arr[i]) {
                flag = false;
                break;
            }
            ant = arr[i];
        }

        if (flag) {
            cout << val << '\n';
        } else {
            cout << "-1\n";
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome