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
    int x, y;
    int mix, miy, maxx, may;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        if (i == 0) {
            mix = x;
            miy = y;
            maxx = x;
            may = y;
        }

        mix = min(x, mix);
        miy = min(y, miy);
        maxx = max(x, maxx);
        may = max(y, may);

    }

    int l = abs(mix - maxx) + 2;
    int r = abs(miy - may) + 2;

    cout << (2*l + 2*r) << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome