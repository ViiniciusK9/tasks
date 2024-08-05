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

const int MAX = 512;

string mat1[MAX];
string mat2[MAX];

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
            cin >> mat1[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> mat2[i];
        }

        int tot1 = 0;
        int tot2= 0;
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            tot1=0;
            tot2=0;
            for (int i = 0; i < n; i++)
            {
                if (mat1[i][j] == '1') {
                    tot1+=1;
                } else if (mat1[i][j] == '2') {
                    tot1+=2;
                }

                if (mat2[i][j] == '1') {
                    tot2+=1;
                } else if (mat2[i][j] == '2') {
                    tot2+=2;
                }
            }

            if (tot1%3 != tot2%3) {
                flag = false;
            }
            
        }

        for (int i = 0; i < n; i++)
        {
            tot1=0;
            tot2=0;
            for (int j = 0; j < m; j++)
            {
                if (mat1[i][j] == '1') {
                    tot1+=1;
                } else if (mat1[i][j] == '2') {
                    tot1+=2;
                }

                if (mat2[i][j] == '1') {
                    tot2+=1;
                } else if (mat2[i][j] == '2') {
                    tot2+=2;
                }
            }

            if (tot1%3 != tot2%3) {
                flag = false;
            }
            
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome