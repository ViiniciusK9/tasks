#include <bits/stdc++.h>

#define MAX_N 3
#define MAX_M 10

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

vi permutation;
vi coefs(MAX_N);
set<int> vals;
vector<bool> chosen(MAX_M + 1);

int val_funcao(int n) {
    int val = 0;
    for (int i = 0; i < n; i++) {
        val += (coefs[i] * permutation[i]);
    }

    return val;
}

bool search(int n, int m) {
    if (permutation.size() == n) {
        auto ret = vals.insert(val_funcao(n));
        if(!ret.second) {
            return false;
        }
    }
    else {
        for (int i = 1; i <= m; i++) {
            if (chosen[i])
                continue;

            chosen[i] = true;
            permutation.push_back(i);

            if (!search(n, m)) {
                return false;
            }

            chosen[i] = false;
            permutation.pop_back();
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;

    while(cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> coefs[i];
        }

        cout << (search(n, m) ? "Lucky Denis!" : "Try again later, Denis...") << "\n";

        permutation.clear();
        vals.clear();
        fill(chosen.begin(), chosen.begin() + (m + 1), false);
    }

    return 0;
}