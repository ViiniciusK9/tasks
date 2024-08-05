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

string mat[59];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;

    cin >> h >> w;
    int x, y;
    cin >> x >> y;
    string path;
    x--;
    y--;
    for (int i = 0; i < h; i++)
    {
        cin >> mat[i];
    }
    cin >> path;

    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == 'L')
        {
            if (y - 1 >= 0 && mat[x][y - 1] == '.')
            {
                y--;
            }
        }
        else if (path[i] == 'R')
        {
            if (y + 1 < w && mat[x][y + 1] == '.')
            {
                y++;
            }
        }
        else if (path[i] == 'D')
        {
            if (x + 1 < h && mat[x + 1][y] == '.')
            {
                x++;
            }
        }
        else
        {
            if (x - 1 >= 0 && mat[x - 1][y] == '.')
            {
                x--;
            }
        }
    }

    cout << x+1 << " " << y+1 << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome