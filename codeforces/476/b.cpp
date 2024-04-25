#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(12)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int falta, result, start, qnt;

void solve(int i, int tot) {
    
    if (i == falta && tot == result) {
        qnt++;
        return;
    }

    if (i == falta) {
        return;
    }

    solve(i+1, tot+1);
    solve(i+1, tot-1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    cin >> s1 >> s2;
    int p1, n1, p2, n2;

    p1 = 0;
    p2 = 0;
    n2 = 0;

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '+') p1++;
    }

    n1 = s1.size() - p1;

    for (int i = 0; i < s1.size(); i++)
    {
        if (s2[i] == '+') {
            p2++;
        } else if (s2[i] == '-') {
            n2++;
        }
    }

    if (p2 + n2 == s1.size()) {
        if (p2 == p1 && n1 == n2) {
            cout << FF(1.0) << '\n';
        } else {
            cout << FF(0.0) << '\n';
        }
    } else if (p1 - p2 < 0 || n1 - n2 < 0) {
        cout << FF(0.0) << '\n';
    } else {
        falta = s2.length() - (p2 + n2);
        result = p1 - n1;
        start = p2 - n2;
        qnt = 0;
        solve(0, start);
        //DBG(qnt);
        //DBG(falta);
        //DBG(result);
        //DBG(start);

        cout << FF((double) qnt / pow(2, falta)) << '\n';
    }


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome