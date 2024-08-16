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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        cin >> s1;

        int ind = 0;
        int pz = -1;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1')
            {
                ind = i;
            }

            if (pz == -1 && s1[i] == '0')
            {
                pz = i;
            }
        }

        if (pz == -1) {
            pz = s1.size() -1;
        }

        
        cout << abs(ind - pz) + 1<< '\n';
        

        // DBG(ind);
        // DBG(pz);
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome