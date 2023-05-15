#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

bool is_equal(iiii a, iiii b) {
    if (a.first.first == b.second.second && a.first.second == b.second.first && a.second.first == b.first.second && a.second.second == b.first.first)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    char a0, a1, a2, a3;
    cin >> n;
    stack<iiii> s;
    while (n--)
    {
        cin >> a0 >> a1 >> a2 >> a3;
        if (s.empty())
        {
            s.push(iiii(ii('F', 'A'), ii('C', 'E')));
        }
        if (is_equal(s.top(), iiii(ii(a0, a1), ii(a2, a3))))
        {
            s.pop();
            ans++;
        } else {
            s.push(iiii(ii(a0, a1), ii(a2, a3)));
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome