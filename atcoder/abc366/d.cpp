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

const int MAX = 111;
int n;
ll a[MAX][MAX][MAX];
ll pre[MAX][MAX][MAX];

void prefixSum3d()
{
    pre[0][0][0] = a[0][0][0];

    for (int i = 1; i < n; i++) pre[i][0][0] = pre[i - 1][0][0] + a[i][0][0];
    for (int i = 1; i < n; i++) pre[0][i][0] = pre[0][i - 1][0] + a[0][i][0];
    for (int i = 1; i < n; i++) pre[0][0][i] = pre[0][0][i - 1] + a[0][0][i];

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            pre[k][i][0] = a[k][i][0] + pre[k - 1][i][0] + pre[k][i - 1][0] - pre[k - 1][i - 1][0];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pre[0][i][j] = a[0][i][j] + pre[0][i - 1][j] + pre[0][i][j - 1] - pre[0][i - 1][j - 1];
        }
    }
    for (int j = 1; j < n; j++) {
        for (int k = 1; k < n; k++) {
            pre[k][0][j] = a[k][0][j] + pre[k - 1][0][j] + pre[k][0][j - 1] - pre[k - 1][0][j - 1];
        }
    }

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                pre[k][i][j] = a[k][i][j]
                             + pre[k - 1][i][j]
                             + pre[k][i - 1][j]
                             + pre[k][i][j - 1]
                             - pre[k - 1][i - 1][j]
                             - pre[k][i - 1][j - 1]
                             - pre[k - 1][i][j - 1]
                             + pre[k - 1][i - 1][j - 1];
            }
        }
    }
}

ll query(int lx, int rx, int ly, int ry, int lz, int rz) {
    ll result = pre[rx][ry][rz];

    if (lx > 0) result -= pre[lx - 1][ry][rz];
    if (ly > 0) result -= pre[rx][ly - 1][rz];
    if (lz > 0) result -= pre[rx][ry][lz - 1];

    if (lx > 0 && ly > 0) result += pre[lx - 1][ly - 1][rz];
    if (lx > 0 && lz > 0) result += pre[lx - 1][ry][lz - 1];
    if (ly > 0 && lz > 0) result += pre[rx][ly - 1][lz - 1];

    if (lx > 0 && ly > 0 && lz > 0) result -= pre[lx - 1][ly - 1][lz - 1];

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int z = 0; z < n; z++)
            {
                cin >> a[x][y][z];
            }
        }
    }

    prefixSum3d();

    int q;
    cin >> q;

    while (q--)
    {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; ly--; lz--; 
        rx--; ry--; rz--; 

        cout << query(lx, rx, ly, ry, lz, rz) << '\n';
    }

    return 0;
}