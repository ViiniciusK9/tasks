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

int n = 5;

int mat[10][10];
int visited[10][10];

bool bfs(pi source)
{
    queue<pi> q;

    q.push(source);

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        int i, j;
        i = cur.f;
        j = cur.s;

        if (i == 5 && j == 5) {
            return true;
        }

        if (!visited[i][j]) {
            visited[i][j] = true;
            if (i+1 <= 5 && mat[i+1][j] == 0) {
                q.push({i+1, j});
            }
            if (i-1 >= 1 && mat[i-1][j] == 0) {
                q.push({i-1, j});
            }

            if (j+1 <= 5 && mat[i][j+1] == 0) {
                q.push({i, j+1});
            }
            if (j-1 >= 1 && mat[i][j-1] == 0) {
                q.push({i, j-1});
            }
        }
    }
    

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        memset(visited, 0, sizeof(visited));

        for (size_t i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                cin >> mat[i][j];
            }
        }

        if (mat[1][1] == 1) {
            cout << "ROBBERS\n";
        } else {
            bool ans = bfs({1, 1});
            if (ans == true) {
                cout << "COPS\n";
            } else {
                cout << "ROBBERS\n";
            }
        }


        

        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome