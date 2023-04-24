#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 11234

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int f[MAX], c[MAX];

    int n, m;
    priority_queue<int, vector<int>, greater<int>> p;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome