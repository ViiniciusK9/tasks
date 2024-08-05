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
        ll n, k;
        cin >> n >> k;

        map<char, int> ma;
        string s1;
        cin >> s1;

        for (int i = 0; i < s1.size(); i++)
        {
            ma[s1[i]]++;
        }
        ll ans = 0;
        ll qnt = 0;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            ii el = {i, ma[i]};
            if (el.first < 'a') {
                ans += min(el.second, ma[(el.first + 32)]);
                qnt += (max(el.second, ma[(el.first + 32)]) - min(el.second, ma[(el.first + 32)])) / 2;
            }
        }
        
        cout << ans + min(qnt, k)<< '\n';



    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome