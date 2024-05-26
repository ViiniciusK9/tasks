#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v) {
        cin >> i;
    }


    list<string> l;
    for (int i = 1; i <= n; i++) {
        string aux;
        cin >> aux;
        l.push_front(aux);
    }

    set<string> s;
    for (int i = 0; i < v.size() - 1; i++) {
        cout << l.back() << " ";
        s.insert(v[i]);
        while (s.count(l.back())) {
            l.pop_back();
        }
    }
    cout << l.back() << endl;

    return 0;
}