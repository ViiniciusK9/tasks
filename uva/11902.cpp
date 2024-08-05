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

const int MAX = 112;
int n;
int mat[MAX][MAX];
int ans[MAX][MAX];
bool visited[MAX];

bool inicial[MAX];
bool aux[MAX];

void dfs(int so, int el)
{

    visited[so] = true;
    stack<int> st;
    st.push(so);

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();

        for (int i = 0; i < n; i++)
        {
            if (mat[cur][i] == 1 && !visited[i] && i != el)
            {
                visited[i] = true;
                st.push(i);
                aux[i] = true;
            }
        }
    }
}

void dfs_i(int so)
{

    visited[so] = true;
    stack<int> st;
    st.push(so);

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();

        for (int i = 0; i < n; i++)
        {
            if (mat[cur][i] == 1 && !visited[i])
            {
                visited[i] = true;
                st.push(i);
                inicial[i] = true;
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
    int ca = 1;
    while (t--)
    {
        cout << "Case " << ca << ":\n";
        ca++;
        memset(inicial, false, sizeof(inicial));
        memset(visited, false, sizeof(visited));
        memset(mat, 0, sizeof(mat));
        memset(ans, 0, sizeof(ans));
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        dfs_i(0);

        for (int i = 0; i < n; i++)
        {
            if (inicial[i])
            {
                memset(visited, false, sizeof(visited));
                memset(aux, false, sizeof(aux));
                dfs(0, i);

                for (int j = 0; j < n; j++)
                {
                    if (inicial[j] && !aux[j])
                    {
                        ans[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans[0][i] = inicial[i];
        }
        ans[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            cout << "+";
            for (int j = 0; j < (n*2-1); j++)
            {
                cout << "-";
            }
            cout << "+\n";

            cout << "|";

            for (int j = 0; j < n; j++)
            {
                cout << (ans[i][j] == 1 ? "Y" : "N");
                cout << "|";
            }
            cout << "\n";

            
        }

        cout << "+";
        for (int j = 0; j < (n*2-1); j++)
        {
            cout << "-";
        }
        cout << "+\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome