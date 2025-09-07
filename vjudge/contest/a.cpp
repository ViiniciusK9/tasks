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

    string s;
    cin >> s;



    char tem[3];
    tem[0] = 'T';
    tem[1] = 'A';
    tem[2] = 'P';
    int ind = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char at = s[i];
        if (at == tem[ind]) {
            ind++;
        }

        if (ind == 3) {
            break;
        }
    }

    cout << (ind == 3 ? "S\n" : "N\n");
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome