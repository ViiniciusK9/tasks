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

string nthPalindrome(long long n) {
    if (n < 10) {
        return to_string(n);
    }

    n -= 9;  

    long long length = 2;
    while (true) {
        long long palindromesInThisLength = 9 * pow(10, (length - 1) / 2);
        if (n <= palindromesInThisLength) {
            break;
        }
        n -= palindromesInThisLength;
        length++;
    }

    long long halfLength = (length + 1) / 2;
    long long start = pow(10, halfLength - 1);
    long long num = start + n - 1;
    string firstHalf = to_string(num);
    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    if (length % 2 == 1) {
        firstHalf.pop_back();
    }

    return (firstHalf + secondHalf);
}

int main() {
    long long th;
    cin >> th;
    cout << nthPalindrome(th-1) << '\n';
    return 0;
}
