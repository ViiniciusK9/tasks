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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    string s1;
    int n;
    while (t--)
    {
        cin >> n;
        cin >> s1;

        //DBG(s1);

        int qnt = s1.size() - 2;

        if (qnt == 0)
        {
            cout << (s1[0] - '0') * 10 + (s1[1] - '0') << '\n';
        }
        else
        {
            vector<vector<int>> ve;        
            for (int i = 1; i < s1.size(); i++)
            {
                vector<int> va;
                char ant = s1[0];
                for (int j = 1; j < s1.size(); j++)
                {
                    
                }
                

            }
            

        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome