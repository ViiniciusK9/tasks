#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d, f;
    long long sum = 0, ans = 0;
    vector<pair<int, int>> vet;
    cin >> n;
    while (n--)
    {
        cin >> d >> f;
        vet.push_back({d, f});
    }
    sort(vet.begin(), vet.end());

    for (auto &j : vet)
    {
        ans += j.second - (sum + j.first);
        sum += j.first;
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome