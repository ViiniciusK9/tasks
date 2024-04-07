#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 2e5+3;
long long int INF = -1e13;
long long int t, n, aux, first, _min, _max, at, ant, ans;

array<int, MAX> arr;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        cin >> first;
        _max = 0;
        _min = 0;
        if (first < 0) {
            _min = first;
        } else {
            _max = first;
        }
        ant = first;
        ans = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> at;
            //DBG(_min);
            //DBG(_max);
            //DBG(ans);
            if ((ant < 0) != (at < 0)) {
                if ((ant < 0)) {
                    ans += _min;
                    _max = at;
                } else {
                    ans += _max;
                    _min = at;
                }
                //cout << "somou\n";
            } else {
                if ((ant < 0)) {
                    _min = max(_min , at);
                } else {
                    _max = max(_max , at);
                }
            }
            ant = at;

        }
        
        if ((ant < 0)) {
            ans += _min;
            _max = at;
        } else {
            ans += _max;
            _min = at;
        }

        cout << ans << '\n';
    
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome