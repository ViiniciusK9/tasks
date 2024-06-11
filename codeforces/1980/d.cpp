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

    int t, n;

    cin >> t;

    vi v;
    vi v1;

    while (t--)
    {
        v.clear();
        v1.clear();
        cin >> n;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        int ant = v[0];
        for (int i = 1; i < n; i++)
        {
            v1.pb(__gcd(ant, v[i]));
            ant = v[i];
        }
        ant = v1[0];
        int ind = 0;
        bool ans = true;
        for (int i = 1; i < v1.size(); i++)
        {
            if (ant > v1[i])
            {
                ans = false;
                ind = i;
            }
        }

        // for (auto vi : v1)
        // {
        //     cout << vi << " ";
        // }
        // cout << '\n';

        if (ans == true)
        {
            cout << "YES\n";
        }
        else
        {
            if (ind == 1)
            {
                v1.clear();
                ant = v[1];
                for (int i = 2; i < n; i++)
                {
                    v1.pb(__gcd(ant, v[i]));
                    ant = v[i];
                }

                ans = true;
                ant = v1[0];
                for (int i = 1; i < v1.size(); i++)
                {
                    if (ant > v1[i])
                    {
                        ans = false;
                    }
                }

                if (ans == true)
                {
                    cout << "YES\n";
                }
                else
                {
                    v1.clear();
                    ant = v[0];
                    for (int i = 2; i < n; i++)
                    {
                        v1.pb(__gcd(ant, v[i]));
                        ant = v[i];
                    }

                    ans = true;
                    ant = v1[0];
                    for (int i = 1; i < v1.size(); i++)
                    {
                        if (ant > v1[i])
                        {
                            ans = false;
                        }
                    }

                    if (ans == true)
                    {
                        cout << "YES\n";
                    }
                    else
                    {
                        cout << "NO\n";
                    }
                }
            }
            else if (ind == v1.size() - 1)
            {
                v1.clear();
                ant = v[0];
                for (int i = 1; i < (n - 1); i++)
                {
                    v1.pb(__gcd(ant, v[i]));
                    ant = v[i];
                }

                ans = true;
                ant = v1[0];
                for (int i = 1; i < v1.size(); i++)
                {
                    if (ant > v1[i])
                    {
                        ans = false;
                    }
                }

                if (ans == true)
                {
                    cout << "YES\n";
                }
                else
                {
                    v1.clear();
                    ant = v[0];
                    for (int i = 1; i < n; i++)
                    {
                        if (i == (n - 2))
                        {
                            continue;
                        }
                        v1.pb(__gcd(ant, v[i]));
                        ant = v[i];
                    }

                    ans = true;
                    ant = v1[0];
                    for (int i = 1; i < v1.size(); i++)
                    {
                        if (ant > v1[i])
                        {
                            ans = false;
                        }
                    }

                    if (ans == true)
                    {
                        cout << "YES\n";
                    }
                    else
                    {
                        v1.clear();
                        ant = v[0];
                        for (int i = 1; i < n; i++)
                        {
                            if (i == (n - 3))
                            {
                                continue;
                            }
                            v1.pb(__gcd(ant, v[i]));
                            ant = v[i];
                        }

                        ans = true;
                        ant = v1[0];
                        for (int i = 1; i < v1.size(); i++)
                        {
                            if (ant > v1[i])
                            {
                                ans = false;
                            }
                        }
                        if (ans == true)
                        {
                            cout << "YES\n";
                        }
                        else
                        {
                            cout << "NO\n";
                        }
                    }
                }
            }
            else
            {
                v1.clear();
                ant = v[0];
                for (int i = 1; i < n; i++)
                {
                    if (i == ind)
                    {
                        continue;
                    }
                    v1.pb(__gcd(ant, v[i]));
                    ant = v[i];
                }

                ans = true;
                ant = v1[0];
                for (int i = 1; i < v1.size(); i++)
                {
                    if (ant > v1[i])
                    {
                        ans = false;
                        ind = i;
                    }
                }

                if (ans == true)
                {
                    cout << "YES\n";
                }
                else
                {
                    v1.clear();
                    ant = v[0];
                    for (int i = 1; i < n; i++)
                    {
                        if (i == ind - 1)
                        {
                            continue;
                        }
                        v1.pb(__gcd(ant, v[i]));
                        ant = v[i];
                    }

                    ans = true;
                    ant = v1[0];
                    for (int i = 1; i < v1.size(); i++)
                    {
                        if (ant > v1[i])
                        {
                            ans = false;
                        }
                    }

                    if (ans == true)
                    {
                        cout << "YES\n";
                    }
                    else
                    {
                        v1.clear();
                        ant = v[0];
                        for (int i = 1; i < n; i++)
                        {
                            if (i == ind + 1)
                            {
                                continue;
                            }
                            v1.pb(__gcd(ant, v[i]));
                            ant = v[i];
                        }

                        ans = true;
                        ant = v1[0];
                        for (int i = 1; i < v1.size(); i++)
                        {
                            if (ant > v1[i])
                            {
                                ans = false;
                            }
                        }

                        if (ans == true)
                        {
                            cout << "YES\n";
                        }
                        else
                        {
                            cout << "NO\n";
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome