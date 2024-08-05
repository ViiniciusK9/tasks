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

    int n;

    cin >> n;
    string bf;
    getline(cin, bf);
    while (n--)
    {
        getline(cin, bf);
        istringstream is(bf);
        vector<string> v((istream_iterator<string>(is)), istream_iterator<string>());
        bool ans = true;
        for (auto s1 : v) {
            if (s1.size() > 5) {
                int tam = s1.size() -1;
                if (tolower(s1[0]) != 'a' && tolower(s1[0]) != 'e' && tolower(s1[0]) != 'i' && tolower(s1[0]) != 'o' && tolower(s1[0]) != 'u') {
                    ans = false;
                }

                if (tolower(s1[tam]) != 'a' && tolower(s1[tam]) != 'e' && tolower(s1[tam]) != 'i' && tolower(s1[tam]) != 'o' && tolower(s1[tam]) != 'u') {
                    ans = false;
                }

            } else if (s1.size() == 1) {
                continue;
            } else {
                int tam = s1.size() -1;
                if (tolower(s1[0]) == 'a' || tolower(s1[0]) == 'e' || tolower(s1[0]) == 'i' || tolower(s1[0]) == 'o' || tolower(s1[0]) == 'u') {
                    ans = false;
                }

                if (tolower(s1[tam]) != 'a' && tolower(s1[tam]) != 'e' && tolower(s1[tam]) != 'i' && tolower(s1[tam]) != 'o' && tolower(s1[tam]) != 'u') {
                    ans = false;
                }
            }
        }

        cout << (ans ? "SIM\n" : "NAO\n");
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome