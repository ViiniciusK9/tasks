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
        int n;
        cin >> n;
        string s1;
        cin >> s1;

        string aux;
        int val = 0;
        int cnt = 1;

        for (int i = s1.size()-1; i >= 0; i--)
        {
            if (s1[i] == '0') {
                int a = (s1[i-2] - '0') * 10;
                a += s1[i-1] - '0';
                aux.pb('a'+(a-1));
                i-=2;
            } else {
                int a = s1[i] - '0';
                aux.pb('a'+(a-1));
            }
        }

        reverse(aux.begin(), aux.end());
        cout << aux << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome