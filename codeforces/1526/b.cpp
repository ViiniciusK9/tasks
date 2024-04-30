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

const int MAX = 1000;

//bool memo[MAX];
map<int, bool> mem;
vector<int> coin = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

void solve()
{
    mem[0] = 1;
    for (int i = 1; i < MAX-4; i++)
    {
        for (auto c : coin)
        {
            if (i - c >= 0)
            {
                if (mem.find(i-c) != mem.end()) {
                    mem[i] = 1;
                    break;
                }
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;
    //bool a = ;
    solve();
    while (t--)
    {
        cin >> n;
        if (mem.find(n) != mem.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome