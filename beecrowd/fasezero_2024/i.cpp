#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    char aux;
    cin >> n >> m;

    vector<int> a(n*m);
    vector<int> p;
    int kk = 0;
    for (int &i: a) {
        cin >> aux;
        i = (aux - '0');
        p.push_back(i + kk);
        kk += i;
    }

    bool f;
    for (int k = 0; k < m; k++) {
        f = false;
        set<int> s;

        int i = k;
        for (;i+m-1 < n*m; i+= m) {
            int sum = a[i] + p[i+m-1] - p[i];
            if (s.count(sum)) {
                f = true; break;
            }
            s.insert(sum);
        }

        if(k > 0){
            int sum = 0;
            sum += a[0] + p[k-1] - p[0];
            sum += a[i] + p[n*m-1] - p[i];
            if (s.count(sum)) f = true;
        }

        if(f) break;
    }

    cout << (f?"N":"S") << endl;

    return 0;
}