#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

ll binpower(ll n, ll x, ll mod) {
    ll k = 1;
    n %= mod;
    while (x) {
        if (x & 1) k = (k * n) % mod;
        n = n * n % mod;
        x >>= 1;
    }
    return k;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;

    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }

    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2) return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;

        ll k = check_composite(n, a, d, r);
        if (k) return false;
    }
    return true;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;

        bool flag = false;
        long i = n>>1;
        if(i == n-i) i--;

        for (;i >= 1; i--) {
            if (!MillerRabin(i) && !MillerRabin(n-i)) {
                flag = true;
                break;
            }
        }

        if (flag) cout << i << " " << n-i << endl;
        else cout << -1 << endl;

    }

    return 0;
}