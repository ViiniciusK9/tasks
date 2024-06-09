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

    string s1;

    cin >> s1;
    int m1 = 0;
    int m2 = 0;

    //m1 = 'a';
    //m2 = 'A';

    //DBG(m1);
    //DBG(m2);

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= 'a')
        {
            m1++;
        }
        else
        {
            m2++;
        }
    }

    //DBG(m1);
    //DBG(m2);

    if (m1 > m2)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] >= 'a')
            {
                continue;
            }
            else
            {
                s1[i] = s1[i] + 32;
            }
        }
    }
    else
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] >= 'a')
            {
                s1[i] = s1[i] - 32;
            }
            else
            {
                continue;
            }
        }
    }

    cout << s1 << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome