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

    string s;
    deque<string> dq;
    string aux;

    while (cin >> s)
    {
        dq.clear();
        aux.clear();
        int lado = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                if (lado == 1)
                {
                    dq.push_front(aux);
                }
                else
                {
                    dq.push_back(aux);
                }
                aux.clear();
                lado = 1;
            }
            else if (s[i] == ']')
            {
                if (lado == 1)
                {
                    dq.push_front(aux);
                }
                else
                {
                    dq.push_back(aux);
                }
                aux.clear();
                lado = 0;
            }
            else
            {
                aux.push_back(s[i]);
            }
        }
        if (lado == 1)
        {
            dq.push_front(aux);
        }
        else
        {
            dq.push_back(aux);
        }

        for (auto a : dq)
        {
            cout << a;
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome