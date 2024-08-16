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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 123;

int mat[MAX][MAX];

set<int> st[10001];

bool visited[10001];

int bfs(int s) {
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    int mx = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> mat[i][j];
            mx = max(mx, mat[i][j]);
        }
    }

    for (int i = h-1; i >= 1; i--)
    {
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] != mat[i+1][j]) {
                st[mat[i][j]].insert(mat[i+1][j]);
            }
        }
    }

    set<int> iniciais;

    
    for (int j = 0; j < w; j++)
    {
        iniciais.insert(mat[h-1][j]);
    }

    int ans = INT_MAX;
    for (auto co : iniciais)
    {

        ans = min(ans, bfs(co));
    }
    
    





    



    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome