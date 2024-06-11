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

const int MAX = int(2e5+10);

string mat[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n, m;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];  
        }

        int xi, yi;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '#') {
                    xi = i;
                    yi = j;
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                break;
            }
        }

        int c = 0;
        int cx = xi;
        int cy = yi;
        while (mat[cx][cy] == '#' && cx < n)
        {
            c++;
            cx++;
        }

        if (c == 1) {
            cout << xi+1 << " " << yi + 1 << '\n';
        } else {
            c = c /2;
            cout << xi + c + 1 << " " << yi + 1 << '\n';
        }


        
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome