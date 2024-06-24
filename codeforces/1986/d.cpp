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
            char ant = s1[0];
            int da = 0;
            for (int i = 1; i < s1.size(); i++)
            {
                if (s1[i] == ant && ant == '0')
                {
                    da = 1;
                    break;
                }
                ant = s1[i];
            }

            if (da == 1 || s1[0] == '0' || s1[s1.size()-1] == '0')
            {
                cout << "0\n";
            }
            else if (s1.size() == 3) {

                cout << min({ (s1[0] - '0') + ((s1[1] - '0') * 10 + (s1[2] - '0')) , (s1[0] - '0') * ((s1[1] - '0') * 10 + (s1[2] - '0')),
                              ((s1[0] - '0') * 10 + (s1[1] - '0')) + ((s1[2] - '0')) , ((s1[0] - '0') * 10 + (s1[1] - '0')) * ((s1[2] - '0'))
                }) << '\n';

            }

            else
            {
                
                int st = 0;

                for (int i = 0; i < s1.size(); i++)
                {
                    if (s1[i] - '0' == 1) {
                        continue;
                    }
                    st += (s1[i] - '0');
                }

                char ant = s1[0];
                int menor = 10000000;
                for (int i = 1; i < s1.size(); i++)
                {
                    int val = (ant - '0') * 10  + (s1[i] - '0');
                    
                    menor = min(menor, ((st - (ant - '0' == 1 ? 0 : ant - '0') - (s1[i] - '0' == 1 ? 0 : s1[i] - '0')) + val));
                    ant = s1[i];
                }

                cout << menor << '\n';
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome