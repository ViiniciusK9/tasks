#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 112345

typedef pair<double, pair<int, int>> iii;

int v[MAX], p[MAX];
vector<iii> vet;


double solve(int i, long long b) {
    double ans = 0;

    while (b != 0 && i < vet.size())
    {
        if (b >= vet[i].second.second)
        {
            b -= vet[i].second.second;
            ans += vet[i].second.first;
        } else {

            ans += b * (vet[i].second.first / vet[i].second.second);
            b = 0;
        }
        i++;
    }
    
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long b;
    double vol;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    
    for (int i = 0; i < n; i++)
    {
        double aux = ((double) p[i]) / v[i];
        vet.push_back({aux, {v[i], p[i]}});
    }
    sort(vet.begin(), vet.end());
    

    if (b == 0)
    {
        cout << 0 << '\n';
    } else {
        vol = solve(0, b);
        cout << (int) (-0.5 + sqrt(0.25 + 2 * vol)) << '\n';
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome