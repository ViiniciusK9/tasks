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
        vector<int> qnt(n);
        vector<int> pref(n+1);

        vector<vector<ii>> mat;
        vector<int> neg;
        vector<ii> aux;
        int ne = 0;
        for (int i = 0; i < n; i++)
        {
            int el;
            cin >> el;

            if (abs(el) == 2) {
                qnt[i] = 1;
            }

            if (el == 0)
            {
                if (aux.size() >= 1)
                {
                    mat.push_back(aux);
                    aux.clear();
                    neg.push_back(ne);
                }
            }
            else
            {
                aux.push_back({el, i});
                if (el < 0)
                {
                    ne++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            pref[i+1] = pref[i] + qnt[i];
        }
        

        if (aux.size() >= 1)
        {
            mat.push_back(aux);
            aux.clear();
            neg.push_back(ne);
        }

        int mx = -1;
        ii ans;
        for (int i = 0; i < mat.size(); i++)
        {
            vector<ii> el = mat[i];

            if (neg[i] % 2 == 0)
            {
                if (pref[el[el.size()-1].second+1] - pref[el[0].second] > mx) {
                    mx = pref[el[el.size()-1].second+1] - pref[el[0].second];
                    ans.first = el[0].second;
                    ans.second = el[el.size()-1].second;
                }
            }
            else
            {
                if (neg[i] == 1)
                {
                    //DBG(1);
                    int l = 0;
                    for (auto ele : el) {
                        if (ele.first < 0) {
                            l = ele.second;
                            break;
                        }
                    }

                    //DBG(l);

                    if (pref[l] - pref[el[0].second] > mx) {
                        mx = pref[l] - pref[el[0].second];
                        ans.first = el[0].second;
                        ans.second = l-1;
                    }

                    if (pref[el[el.size()-1].second + 1] - pref[l+1] > mx) {
                        mx = pref[el[el.size()-1].second + 1] - pref[l+1];
                        ans.first = l+1;
                        ans.second = el[el.size()-1].second;
                    }

                }
                else
                {
                    int l = 0, r = el.size() - 1;

                    while (el[l].first > 0 || el[r].first > 0)
                    {
                        if (el[l].first > 0)
                        {
                            l++;
                        }

                        if (el[r].first > 0)
                        {
                            r--;
                        }
                    }

                    //pref[l] - pref[el[0].second]

                    if (pref[l] - pref[el[0].second] > mx) {
                        mx = pref[l] - pref[el[0].second];
                        ans.first = el[0].second;
                        ans.second = l-1;
                    }

                    if (pref[el[el.size()-1].second + 1] - pref[l+1] > mx) {
                        mx = pref[el[el.size()-1].second + 1] - pref[l+1];
                        ans.first = l+1;
                        ans.second = el[el.size()-1].second;
                    }

                    if (pref[r] - pref[el[0].second] > mx) {
                        mx = pref[r] - pref[el[0].second];
                        ans.first = el[0].second;
                        ans.second = r-1;
                    }

                    if (pref[el[el.size()-1].second + 1] - pref[r+1] > mx) {
                        mx = pref[el[el.size()-1].second + 1] - pref[r+1];
                        ans.first = r+1;
                        ans.second = el[el.size()-1].second;
                    }
                }
            }
        }
        //DBG(mx);
        cout << ans.first << " " << abs(ans.second - (n-1)) << '\n';

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome