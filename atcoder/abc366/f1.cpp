#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = int(2e5 + 10);
int n, k;

vi a(MAX);
vi b(MAX);
bool use[MAX];

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<ll, ll, custom_hash> memo;

ll solve(int q, ll mul) {
    if (q == k) {
        return mul;
    }

    if (memo.count(mul)) {
        return memo[mul];
    }

    ll ans = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            use[i] = true;
            ans = max(ans, solve(q + 1, a[i] * mul + b[i]));
            use[i] = false;
        }
    }

    memo[mul] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    cout << solve(0, 1) << '\n';
    
    return 0;
}