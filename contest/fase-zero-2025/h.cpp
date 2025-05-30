#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
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

    ll x;
    cin >> x;

    bool isPalindrome = false;
    while (!isPalindrome)
    {
        bitset<64> b(x);
        string bin = b.to_string();
        bin.erase(0, bin.find_first_not_of('0'));
        isPalindrome = equal(bin.begin(), bin.begin() + bin.size()/2, bin.rbegin());
        if (!isPalindrome) {
            x--;
        }
    }
    
    cout << x << endl;

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome