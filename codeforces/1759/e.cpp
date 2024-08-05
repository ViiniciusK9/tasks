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
        int n, h;
        vector<ii> v;
        cin >> n >> h;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;

            int val = aux / 2;
            
            v.pb({aux, val});
            
        }

        sort(v.begin(), v.end());

        ll m1 = 0, m2 = 0, m3 = 0;
        ll h1 = h, h2 = h, h3 = h;

        int mi1= -1, mi2 = -1, mi3= -1;

        int g = 2, b = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first < h1)
            {
                h1 += v[i].second;
                mi1 = i;
            }
            else if (g == 2)
            {
                h1 *= 2;
                g = 1;
                if (v[i].first < h1)
                {
                    h1 += v[i].second;
                    mi1 = i;
                }
                else
                {
                    h1 *= 2;
                    g = 0;
                    if (v[i].first < h1)
                    {
                        h1 += v[i].second;
                        mi1 = i;
                    }
                    else
                    {
                        h1 *= 3;
                        b = 0;
                        if (v[i].first < h1)
                        {
                            h1 += v[i].second;
                            mi1 = i;
                        }
                        else
                        {
                            m1 = max(m1, h1);
                            break;
                        }
                    }
                }
            }
            else if (g == 1)
            {
                h1 *= 2;
                g = 0;
                if (v[i].first < h1)
                {
                    h1 += v[i].second;
                    mi1 = i;
                }
                else
                {
                    h1 *= 3;
                    b = 0;
                    if (v[i].first < h1)
                    {
                        h1 += v[i].second;
                        mi1 = i;
                    }
                    else
                    {
                        m1 = max(m1, h1);
                        break;
                    }
                }
            }
            else if (g == 0 && b == 1)
            {
                h1 *= 3;
                b = 0;
                if (v[i].first < h1)
                {
                    h1 += v[i].second;
                    mi1 = i;
                }
                else
                {
                    m1 = max(m1, h1);
                    break;
                }
            } else {
                m1 = max(m1, h1);
                break;
            }

            m1 = max(m1, h1);
        }

        g = 2, b = 1;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first < h2)
            {
                h2 += v[i].second;
                mi2 = i;
            }
            else if (b == 1)
            {
                h2 *= 3;
                b = 0;
                if (v[i].first < h2)
                {
                    h2 += v[i].second;
                    mi2 = i;
                }
                else
                {
                    h2 *= 2;
                    g = 1;
                    if (v[i].first < h2)
                    {
                        h2 += v[i].second;
                        mi2 = i;
                    }
                    else
                    {
                        h2 *= 2;
                        g = 0;
                        if (v[i].first < h2)
                        {
                            h2 += v[i].second;
                            mi2 = i;
                        }
                        else
                        {
                            m2 = max(m1, h2);
                            break;
                        }
                    }
                }
            }
            else if (g == 2)
            {
                h2 *= 2;
                g = 1;
                if (v[i].first < h2)
                {
                    h2 += v[i].second;
                    mi2 = i;
                }
                else
                {
                    h2 *= 2;
                    g = 0;
                    if (v[i].first < h2)
                    {
                        h2 += v[i].second;
                        mi2 = i;
                    }
                    else
                    {
                        m2 = max(m2, h2);
                        break;
                    }
                }
            }
            else if (g == 1)
            {
                h2 *= 2;
                g = 0;
                if (v[i].first < h2)
                {
                    h2 += v[i].second;
                    mi2 = i;
                }
                else
                {
                    m2 = max(m2, h2);
                    break;
                }
            } else {
                m2 = max(m2, h2);
                break;
            }

            m2 = max(m2, h2);
        }

        g = 2, b = 1;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first < h3)
            {
                h3 += v[i].second;
                mi3 = i;
            }
            else if (g == 2)
            {
                h3 *= 2;
                g = 1;
                if (v[i].first < h3)
                {
                    h3 += v[i].second;
                    mi3 = i;
                }
                else
                {
                    h3 *= 3;
                    b = 0;
                    if (v[i].first < h3)
                    {
                        h3 += v[i].second;
                        mi3 = i;
                    }
                    else
                    {
                        h3 *= 2;
                        g = 0;
                        if (v[i].first < h3)
                        {
                            h3 += v[i].second;
                            mi3 = i;
                        }
                        else
                        {
                            m3 = max(m3, h3);
                            break;
                        }
                    }
                }
            }
            else if (b == 1)
            {
                h3 *= 3;
                b = 0;
                if (v[i].first < h3)
                {
                    h3 += v[i].second;
                    mi3 = i;
                }
                else
                {
                    h3 *= 2;
                    g = 0;
                    if (v[i].first < h3)
                    {
                        h3 += v[i].second;
                        mi3 = i;
                    }
                    else
                    {
                        m3 = max(m3, h3);
                        break;
                    }
                }
            }
            else if (g == 1)
            {
                h3 *= 2;
                g = 0;
                if (v[i].first < h3)
                {
                    h3 += v[i].second;
                    mi3 = i;
                }
                else
                {
                    m3 = max(m3, h3);
                    break;
                }
            } else {
                m3 = max(m3, h3);
                break;
            }

            m3 = max(m3, h3);
        }

        cout << max({mi1+1, mi2+1, mi3+1}) << '\n';

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome