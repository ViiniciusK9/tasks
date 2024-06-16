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

string mat[20];
int n, m;

string jointwo(string a, string b) {

    string nova;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'o' || b[i] == 'o')
        {
            nova.pb('o');
        } else {
            nova.pb('x');
        }
    }   
    return nova;
}

bool isComplete(string a) {
    bool ans = true;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'x')
        {
            ans = false;
            break;
        }
    } 
    return ans;
}

int solve(int i, string at) {

    if (i == n) {
        if (isComplete(at)) {
            return 0;
        } else {
            return 100000;
        }
    }

    return min(solve(i+1, jointwo(at, mat[i])) + 1, solve(i+1, at));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    
    string init;
    for (int i = 0; i < m; i++)
    {
        init.pb('x');
    }
    

    int ans = solve(0, init);

    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome