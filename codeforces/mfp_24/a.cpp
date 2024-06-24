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

string mat[50];
bool feito[50];

string f(int i) {
    if (i == 1) {
        return "a";
    }

    if (feito[i] == true) {
        return mat[i];
    }

    
    mat[i] = f(i-1) + ((char)(97 + (i-1))) + f(i-1);
    feito[i] = true;
    return mat[i];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    //string result = f(n);

    string result = "a";
    int t = 1;
    n--;
    while (n-- && result.size() <= int(1e5))
    {
        result = result + (((char) (97 + t))) + result;         
        t++;
    }

    

    int j = 0;
    while (j < result.size() && j < int(1e5))
    {
        cout << result[j];
        j++;
    }
    cout << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome