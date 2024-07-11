#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int mat[26][26];

bool visited[26];
string n;

void bfs(int source) {

    queue<int> q;
    q.push(source);
    visited[source]=true;

    while (!q.empty())
    {
        int at = q.front();
        q.pop();

        for (int i = 0; i <= n[0]-'A'; i++)
        {
            if(mat[at][i] == 1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
        
    }
    

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    bool first = true;
    string s1;
    while (t--)
    {
        memset(visited, false, sizeof(visited));
        memset(mat, 0, sizeof(mat));
        if (first) {
            cin >> n;
        }
        //DBG(n);

        while (cin >> s1 && s1.size() == 2)
        {
            //DBG(s1);
            mat[s1[0] - 'A'][s1[1] - 'A'] = 1;
            mat[s1[1] - 'A'][s1[0] - 'A'] = 1;
        }
        int ans = 0;
        for (int i = 0; i <= n[0]-'A'; i++)
        {
            if (!visited[i]) {
                bfs(i);
                ans++;
            }
        }

        cout << (first == true ? "" : "\n") << ans << '\n';

        n = s1;
        first = false;
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome