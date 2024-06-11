#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



long long int b2c(long long int b) {
    // 5b = 3c
    // 2b = 3a
    // 5a = 2c
    return max((long long int)((b / 5) * 3), (long long int)((((b/1) * (long double)1.5)/(long double)2.5)*1));
}

long long int a2c(long long int a) {
    return max((long long int)((a / (long double)2.5)*1), (long long int)((((a/(long double)1.5)*1)/5)*3));
}

long long int a2b(long long int a) {
    return max((long long int)((a / (long double)1.5) * 1), (long long int)((((a/(long double)2.5) * 1)/3)*5));
}

long long int c2b(long long int c) {
    return max((long long int)((c / 3)*5), (long long int)((((c/1)*(long double)2.5)/(long double)1.5)*1));
}

long long int b2a(long long int b) {
    return max((long long int)((b / 1) * (long double)1.5), (long long int)((((b/5) * 3)/1)*(long double)2.5));
}

long long int c2a(long long int c) {
    return max((long long int) ((c / 1)*(long double)2.5),(long long int) ((((c/3)*5)/1)*(long double)1.5));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    // 2b = 3a
    // 2c = 5a
    // 5b = 3c
    // 5a = 2c
    // 3a = 2b
    // 3c = 5b

    long long int a, b, c;
    cin >> a >> b >> c;
    string s;
    cin >> s;

    if (s[0] == 'A')
    {
        cout << (c2a(c) + b2a(b) + a) << '\n';
    } else if (s[0] == 'B') {
        cout << (c2b(c) + a2b(a) + b) << '\n';
    } else {
        cout << (a2c(a) + b2c(b) + c) << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome