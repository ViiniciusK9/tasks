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

string mat[3];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> mat[0];
        cin >> mat[1];
        int qnt = 0;
        
        for (int j = 1; j < n; j++)
        {
            if (mat[0][j] == '.' && mat[0][j-1] == '.' && j+1 < n && mat[0][j+1] == '.' && mat[1][j] == '.' && mat[1][j-1] == 'x' && j+1 < n && mat[1][j+1] == 'x') {
                qnt++;
            }
        }

        for (int j = 1; j < n; j++)
        {
            if (mat[1][j] == '.' && mat[1][j-1] == '.' && j+1 < n && mat[1][j+1] == '.' && mat[0][j] == '.' && mat[0][j-1] == 'x' && j+1 < n && mat[0][j+1] == 'x') {
                qnt++;
            }
        }
        
        cout << qnt << '\n';
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome