#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int n, m;
int ans = 0;
set<pair<int, pair<int, int>>> set_aux;
vector<int> permut; vector<bool> chosen(n);
void search() {
    if (permut.size() == m) {
        
        for (int i = 0; i < m; i++)
        {
            cout << permut[i]+1 << " ";
        }
        ans++;
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permut.push_back(i);
            search();
            chosen[i] = false;
            permut.pop_back();
        }
    }
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> m >> n)
    {
        
    }
    

    search();
    cout << ans << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome