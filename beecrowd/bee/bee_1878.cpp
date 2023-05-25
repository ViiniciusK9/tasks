#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int n, m, c0, c1, c2, ans = 0;

set<int> set_t;
vector<int> permut; 
vector<bool> chosen;

void search() {
    if (permut.size() == m) {
        if (m == 1)
        {
            set_t.insert((permut[0]+1) * c0);
        } else if (m == 2) {
            set_t.insert((permut[0]+1) * c0 + (permut[1]+1) * c1);
        } else {
            set_t.insert((permut[0]+1) * c0 + (permut[1]+1) * c1 + (permut[2]+1) * c2);
        }
        ans++;
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
        chosen.clear();
        for (int i = 0; i < n; i++)
        {
            chosen.push_back(false);
        }
        
        ans = 0;
        c0 = c1 = c2 = 0;
        if (m == 3)
        {
            cin >> c0 >> c1 >> c2;
        } else if (m == 2) {
            cin >> c0 >> c1;
        } else {
            cin >> c0;
        }
        search();
        
        if (set_t.size() == ans) {
            cout << "Lucky Denis!\n";
        } else {
            cout << "Try again later, Denis...\n";
        }
        set_t.clear();
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome