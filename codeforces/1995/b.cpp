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

const int MAX = int(2e5+10);


ll maxSubarraySum(vector<int> arr, int N, ll K)
{
    set<ll> cum_set;
    cum_set.insert(0);
 
    ll max_sum = INT_MIN, cSum = 0;
 
    for (int i = 0; i < N; i++) {
 
        // getting cumulative sum from [0 to i]
        cSum += arr[i];
 

        set<ll>::iterator sit
            = cum_set.upper_bound(cSum - K);
 
        if (sit != cum_set.end())
 
            max_sum = max(max_sum, cSum - *sit);

        cum_set.insert(cSum);
    }
 
    return max_sum;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        ll n, m;
        vi f;
        cin >> n >> m;
        map<int, int> ma;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            ma[aux]++;
            f.pb(aux);
        }

        ll ans = 0;
        for (auto el : ma) {

            

            if (ma.find(el.first+1) != ma.end()) {
                ii ot = {el.first+1, ma[el.first+1]};
                vi pref(el.second+ot.second);

                int ind = 0;

                for (int i = 0; i < el.second; i++)
                {
                    pref[i] = el.first;
                    ind = i;
                }

                for (int i = ind+1; i < ind+1 + ot.second; i++)
                {
                    pref[i] = ot.first;
                }

                ans = max(ans, maxSubarraySum(pref, el.second+ot.second, m+1));

            } 

            if (ma.find(el.first-1) != ma.end()) {
                ii ot = {el.first-1, ma[el.first-1]};
                vi pref(el.second+ot.second);

                int ind = 0;

                for (int i = 0; i < el.second; i++)
                {
                    pref[i] = el.first;
                    ind = i;
                }

                for (int i = ind+1; i < ind+1 + ot.second; i++)
                {
                    pref[i] = ot.first;
                }

                ans = max(ans, maxSubarraySum(pref, el.second+ot.second, m+1));
            }

            if (el.second >= 1) {
                vi pref(el.second);

                for (int i = 0; i < el.second; i++)
                {
                    pref[i] = el.first;
                }

                ans = max(ans, maxSubarraySum(pref, el.second, m+1));
            }
        }

        cout << ans << '\n';

        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome