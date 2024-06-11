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


array<int, 100> arr;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n;
    int aux;
    vi v;
    while (t--)
    {
        cin >> n;
        int mi = 0, im = 0;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i == 0){
                mi = arr[i];
                im = i;
            }

            if (arr[i] < mi) {
                mi = arr[i];
                im = i;
            }
        }

        for (int i = im; i < n; i++)
        {
            v.pb(arr[i]);
        }

        for (int i = 0; i < im; i++)
        {
            v.pb(arr[i]);
        }
        
        int fir= v[0];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < fir) {
                ans = -1;
                break;
            }

            fir = v[i];
        }

        if (ans == -1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome