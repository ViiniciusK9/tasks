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

string mat[123];
int visited[110][110];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;

    cin >> x >> y;

    for (int i = 0; i < y; i++)
    {
        cin >> mat[i];
    }


    int dir = 0;
    int i, j;
    i = j = 0;
    bool ans = true;
    while (true)
    {
        if (visited[i][j]) {
            ans = false;
            break;
        }

        visited[i][j] = 1;

        if (!(i >= 0 && i < y)) {
            // deu ruim;
            ans = false;
            break;
        }

        if (!(j >= 0 && j < x)) {
            // deu ruim;
            ans = false;
            break;
        }


        if (mat[i][j] == '>') {
            dir = 1;
            j++;
        } else if (mat[i][j] == '<') {
            dir = 2;
            j--;
        } else if (mat[i][j] == '^') {
            dir = 3;
            i--;
        } else if (mat[i][j] == 'v') {
            dir = 4;
            i++;
        } else if (mat[i][j] == '*') {
            // deu bom
            ans = true;
            break; 
        } else if (mat[i][j] == '.') {
            if (dir == 1) {
                j++;
            } else if (dir == 2) {
                j--;
            } else if (dir == 3) {
                i--;
            } else if (dir == 4) {
                i++;
            }
        }
    }
    
    if (ans) {
        cout << "*\n";
    } else {
        cout << "!\n";
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome