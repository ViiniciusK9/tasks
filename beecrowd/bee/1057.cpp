#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 11;

int t, n;
string s[MAX];
string ss[MAX];
array<array<pii, MAX>, MAX> mat0;
array<array<pii, MAX>, MAX> mat1;
array<array<pii, MAX>, MAX> mat2;
array<array<pii, MAX>, MAX> mat3;
array<array<pii, MAX>, MAX> mat4;
array<array<pii, MAX>, MAX> mat5;
array<array<bool, MAX>, MAX> visited;

int dist(pi a, pii b)
{
    return sqrt(pow((a.fi - b.second.first), 2) + pow((a.second - b.second.second), 2));
}

int bfs(pi so, array<array<pii, MAX>, MAX> &mat)
{

    visited[so.fi][so.se] = true;

    queue<pii> q;

    int i, j;
    i = so.fi;
    j = so.se;

    if (i + 1 < n && mat[i + 1][j].fi == '.' || mat[i + 1][j].fi == 'X')
    {
        q.push(mat[i + 1][j]);
    }
    if (i - 1 >= 0 && mat[i - 1][j].fi == '.' || mat[i - 1][j].fi == 'X')
    {
        q.push(mat[i - 1][j]);
    }
    if (j + 1 < n && mat[i][j+1].fi == '.' || mat[i][j+1].fi == 'X')
    {
        q.push(mat[i][j + 1]);
    }
    if (j - 1 >= 0 && mat[i][j-1].fi == '.' || mat[i][j-1].fi == 'X')
    {
        q.push(mat[i][j - 1]);
    }

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        i = cur.se.fi;
        j = cur.se.se;
        if (!visited[i][j])
        {
            visited[i][j] = true;
            if (cur.fi == 'X')
            {
                mat[i][j] = {'#',{i, j}};
                return dist(so, cur);
            }

            if (i + 1 < n && mat[i + 1][j].fi == '.' || mat[i + 1][j].fi == 'X')
            {
                q.push(mat[i + 1][j]);
            }
            if (i - 1 >= 0 && mat[i - 1][j].fi == '.' || mat[i - 1][j].fi == 'X')
            {
                q.push(mat[i - 1][j]);
            }
            if (j + 1 < n && mat[i][j+1].fi == '.' || mat[i][j+1].fi == 'X')
            {
                q.push(mat[i][j + 1]);
            }
            if (j - 1 >= 0 && mat[i][j-1].fi == '.' || mat[i][j-1].fi == 'X')
            {
                q.push(mat[i][j - 1]);
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    int cas = 1;
    while (t--)
    {
        
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            ss[i] = s[i];
        }

        pi a, b, c;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat0[i][j] = {s[i][j], {i, j}};
                mat1[i][j] = {s[i][j], {i, j}};
                mat2[i][j] = {s[i][j], {i, j}};
                mat3[i][j] = {s[i][j], {i, j}};
                mat4[i][j] = {s[i][j], {i, j}};
                mat5[i][j] = {s[i][j], {i, j}};
                if (s[i][j] == 'A')
                {
                    a.fi = i;
                    a.se = j;
                }
                else if (s[i][j] == 'B')
                {
                    b.fi = i;
                    b.se = j;
                }
                else if (s[i][j] == 'C')
                {
                    c.fi = i;
                    c.se = j;
                }
            }
        }

        vector<int> respos;
        respos.clear();

        int ans0, ans1, ans2;
        int res = 0;
        int flag = 0;
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(a, mat0);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(b, mat0);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(c, mat0);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }


        if (flag == 0 && res != 0) {
            respos.pb(res);
        }

        res = 0;
        flag = 0;
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(a, mat1);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(c, mat1);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(b, mat1);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }


        if (flag == 0 && res != 0) {
            respos.pb(res);
        }

        // B

        res = 0;
        flag = 0;
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(b, mat2);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(a, mat2);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(c, mat2);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }


        if (flag == 0 && res != 0) {
            respos.pb(res);
        }

        res = 0;
        flag = 0;
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(b, mat3);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(c, mat3);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(a, mat3);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }


        if (flag == 0 && res != 0) {
            respos.pb(res);
        }

        // C
        res = 0;
        flag = 0;
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(c, mat4);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(a, mat4);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(b, mat4);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }


        if (flag == 0 && res != 0) {
            respos.pb(res);
        }

        res = 0;
        flag = 0;
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(c, mat5);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(b, mat5);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }
        memset(visited.begin(), false, sizeof(visited));
        ans0 = bfs(a, mat5);
        if (ans0 == -1) {
            flag = 1;
        } else {
            res = max(res, ans0);
        }


        if (flag == 0 && res != 0) {
            respos.pb(res);
        }

        cout << "case " << cas << ": ";
        cas++;
        //DBG(result.size());
        if (respos.size() > 0) {
            sort(respos.begin(), respos.end());
            cout << respos[0] << '\n';
        } else {
            cout << "trapped\n";
        }

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome