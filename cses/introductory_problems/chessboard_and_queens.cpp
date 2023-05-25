#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 64


int column[MAX], diag1[MAX], diag2[MAX], n=8;
int ans = 0;
vector<string> vet;


void search(int y) {
    if (y == n) {
        ans++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1] || (vet[x][y] == '*')) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vet.push_back(s);
    }
    search(0);
    cout << ans << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome