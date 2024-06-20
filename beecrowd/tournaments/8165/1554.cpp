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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int INF = int(1e9+10);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c;

    cin >> c;
    int n, x, y, xi, yi, ind, cal, mini;

    while (c--)
    {
        cin >> n;
        cin >> x >> y;
        ind = 0;
        mini = INF;
        for (int i = 1; i <= n; i++)
        {
            cin >> xi >> yi;
            cal = abs(xi - x) * abs(xi - x) + abs(yi - y) * abs(yi - y);
            if (cal < mini) {
                ind = i;
                mini = cal;
            }
        }

        cout << ind << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome