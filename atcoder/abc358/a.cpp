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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    string s1, s2;

    cin >> s1 >> s2;

    if (s1.size() == 7 && s2.size() == 4 && s1[0] == 'A' &&s1[1] == 't' &&s1[2] == 'C' &&s1[3] == 'o' &&s1[4] == 'd' &&s1[5] == 'e' &&s1[6] == 'r' && s2[0] == 'L' && s2[1] == 'a' && s2[2] == 'n' && s2[3] == 'd') {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome