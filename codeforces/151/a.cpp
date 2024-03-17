#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l, c, d, p, nl, np, lq, qnt, rd, sq, ans;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    lq = k * l;
    rd = c * d;
    sq = p / np;
    lq = lq / nl;
    qnt = min({rd, sq, lq});

    ans = qnt / n;

    cout << ans << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome