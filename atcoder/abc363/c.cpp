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

ll fat[12];

bool has(string s1, int k)
{

    for (int i = 0; i <= s1.size() - k; i++)
    {
        string aux = s1.substr(i, k);
        //cout << aux << '\n';
        string p = aux;
        reverse(p.begin(), p.end());
        if (aux == p)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fat[0] = 1;
    for (int i = 1; i < 12; i++)
    {
        fat[i] = fat[i - 1] * i;
    }

    int n, k;

    cin >> n >> k;
    string s1;
    cin >> s1;
    sort(s1.begin(), s1.end());

    ll cnt = 0;
    do
    {
        cnt++;
        //cout << s1 << '\n';
        if (has(s1, k))
        {
            cnt--;
        }
    } while (next_permutation(s1.begin(), s1.end()));

    cout << cnt << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome