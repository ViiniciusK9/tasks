#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n, x, y, query;
    char movi;

    cin >> a >> b;
    int mat[a][b];
    memset(mat, 0, sizeof(mat));

    cin >> n;

    deque<pi> q;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        q.push_back({x, y});
        mat[x][y] = 1;
    }

    cin >> query;
    int morreu = 0;
    while (query--)
    {
        cin >> movi;
        pi cabeca = q.front();
        pi calda = q.back();
        q.pop_back();
        mat[calda.first][calda.second] = 0;

        if (movi == 'D') {
            cabeca.second+=1;
        } else if (movi == 'C') {
            cabeca.first -=1;
        } else if (movi == 'B') {
            cabeca.first +=1;
        } else {
            cabeca.second-=1;
        }

        if (mat[cabeca.first][cabeca.second] == 1 || cabeca.first == a || cabeca.first < 0 || cabeca.second == b || cabeca.second < 0) {
            morreu = 1;
        }
        q.push_front(cabeca);
    }

    if (morreu == 1) {
        cout << "A cobra morreu\n";
    } else {
        cout << q.front().first << " " << q.front().second << '\n';
        cout << q.back().first << " " << q.back().second << '\n';
    }
    

    /*
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome