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

const int MAX = 100;

int dp[MAX];
int dp_lcs[MAX][MAX];
int dp_scs[MAX][MAX];
int dp_scs_bottom[MAX][MAX];
array<int, MAX> dp_scs_b_at;
array<int, MAX> dp_scs_b_prev;
string s1, s2;

int lcs(int i, int j) {
    if (i == s1.size() || j == s2.size()) {
        return 0;
    }

    if (dp_lcs[i][j] != 0) return dp_lcs[i][j];

    if (s1[i] == s2[j]) {
        return dp_lcs[i][j] = lcs(i+1, j+1) + 1;
    }

    return dp_lcs[i][j] = max(lcs(i, j + 1), lcs(i + 1, j));
}

int scs(int i, int j) {

    if (i == s1.length()) {
        return s2.length() - j;
    }

    if (j == s2.length()) {
        return s1.size() - i;
    }

    if (dp_scs[i][j] != 0) return dp_scs[i][j];

    if (s1[i] == s2[j])
    {
        return dp_scs[i][j] = 1 + scs(i+1, j+1);
    }

    return dp_scs[i][j] = 1 + min(scs(i + 1, j), scs(i, j + 1));
}


int scs_bottom_up(int i, int j) {

    for (int i = 0; i <= s1.size(); i++) {
        dp_scs_bottom[i][0] = i;
    }

    for (int i = 0; i <= s2.size(); i++) {
        dp_scs_bottom[0][i] = i;
    }

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i-1] == s2[j-1]) {
                dp_scs_bottom[i][j] = 1 + dp_scs_bottom[i-1][j-1];
            } else {
                dp_scs_bottom[i][j] = 1 + min(dp_scs_bottom[i-1][j], dp_scs_bottom[i][j-1]);
            }
        }
    }
    
    return dp_scs_bottom[i][j];
}

int scs_bottom_up_optmization(int j) {


    for (int i = 0; i <= s2.size(); i++) {
        dp_scs_b_prev[i] = i;
    }

    for (int i = 1; i <= s1.size(); i++)
    {
        dp_scs_b_at[0] = i;
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i-1] == s2[j-1]) {
                dp_scs_b_at[j] = 1 + dp_scs_b_prev[j-1];
            } else {
                dp_scs_b_at[j] = 1 + min(dp_scs_b_prev[j], dp_scs_b_at[j-1]);
            }
        }
        dp_scs_b_prev = dp_scs_b_at;
    }
    
    return dp_scs_b_prev[j];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    /*
        SCS - SHORTEST COMMON SUPERSEGUENCE = ANS = (S1 + S2) - LCS(S1, S2);
        LCS - LONGEST COMMON SUBSEQUENCE
    */

    /*
        test case 1:
        
        intput:
        abdacebfcab
        acebfca

        output:
        11
    */

    
    cin >> s1 >> s2;

    cout << "LCS: " << lcs(0, 0) << '\n';

    cout << "SCS with (s1.size() + s2.size() - LCS(s1, s2)): " << s1.size() + s2.size() - lcs(0, 0) << '\n';

    cout << "SCS TOP-DOWN: " << scs(0, 0) << '\n';

    cout << "SCS BOTTOM-UP: " << scs_bottom_up(s1.length(), s2.length()) << '\n';

    cout << "SCS BOTTOM-UP WITH OPTMIZATION MEMORY : " << scs_bottom_up_optmization(s2.length()) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome