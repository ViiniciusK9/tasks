#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define INF -1123456789

array<int, 4123> memoization;

int n, a, b, c;

int cut_ribbon(int tam) {

    if (tam == 0) {
        return 0;
    }

    if (tam < 0) {
        return INF;
    }

    if (memoization[tam] != 0) {
        return memoization[tam];
    }

    memoization[tam] = 1 + max({cut_ribbon(tam - a), cut_ribbon(tam - b), cut_ribbon(tam - c)});
    return memoization[tam];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(memoization.begin(), memoization.end(), 0);

    cin >> n >> a >> b >> c;

    cout << cut_ribbon(n) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome