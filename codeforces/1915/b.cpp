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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string mat[3];
        cin >> mat[0];
        cin >> mat[1];
        cin >> mat[2];
        
        for (int i = 0; i < 3; i++)
        {
            set<char> st;
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] == '?') {
                    if (j == 0) {
                        if (max(mat[i][1], mat[i][2]) > 'B' && min(mat[i][1], mat[i][2]) < 'B') {
                            cout << "B\n";
                        } else if (max(mat[i][1], mat[i][2]) <= 'B') {
                            cout << "C\n";
                        } else {
                            cout << "A\n";
                        }
                    } else if (j == 1) {
                        if (max(mat[i][0], mat[i][2]) > 'B' && min(mat[i][0], mat[i][2]) < 'B') {
                            cout << "B\n";
                        } else if (max(mat[i][0], mat[i][2]) <= 'B') {
                            cout << "C\n";
                        } else {
                            cout << "A\n";
                        }
                    } else {
                        if (max(mat[i][1], mat[i][0]) > 'B' && min(mat[i][1], mat[i][0]) < 'B') {
                            cout << "B\n";
                        } else if (max(mat[i][1], mat[i][0]) <= 'B') {
                            cout << "C\n";
                        } else {
                            cout << "A\n";
                        }
                    }
                }
            }

            
            
        }
        

    }


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome