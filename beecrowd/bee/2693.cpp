#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed << std::setprecision(1) << (x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, pair<char, string>>> v;

    int n, d;
    char z;
    string s;

    while (cin >> n)
    {
        v.clear();
        while (n--)
        {
            cin >> s >> z >> d;
            v.PB(MP(d, MP(z, s)));
        }

        sort(v.begin(), v.end());

        for (auto i : v)
        {
            cout << i.S.S << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome