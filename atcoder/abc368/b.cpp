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

    int n;
    cin >> n;

    vi v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int qnt = 0;

    while (v[0] > 0 && v[1] > 0)
    {
        v[0]--;
        v[1]--;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        qnt++;
    }

    cout << qnt << '\n';
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome