#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
int INF = std::numeric_limits<int>::max();
int MINF = std::numeric_limits<int>::min();

int cut_rod(int *p, int n){
    if (n == 0)
    {
        return 0;
    }

    int q = MINF;
    for (int i = 1; i <= n; i++)
    {
        q = max(q, p[i] + cut_rod(p, n-i));
    }
    
    return q;
}

int memoized_cut_rod_aux(int *p, int n, int *r){
    int q;

    if (r[n] >= 0)
    {
        return r[n];
    }

    if (n == 0)
    {
        q = 0;
    } else {
        q = MINF;

        for (int i = 1; i <= n; i++)
        {
            q = max(q, p[i] + memoized_cut_rod_aux(p, n-i, r));
        }

        r[n] = q;
    }

    return q;
}

int memoized_cut_rod(int *p, int n){
    int r[n];
    for (int i = 0; i <= n; i++)    
    {
        r[i] = MINF;
    }
    return memoized_cut_rod_aux(p, n, r);
}

int bottom_up_cut_rod(int *p, int n){
    int r[n+1];
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int q = MINF;
        for (int i = 1; i <= j; i++)
        {
            q = max(q, (p[i] + r[j-i]));
        }
        r[j] = q;
    }
    return r[n];
}

int* extended_bottom_up_cut_rod(int *p, int n){
    int r[n+1];
    int s[n+1];
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int q = MINF;
        for (int i = 1; i <= j; i++)
        {
            if (q < p[i] + r[j - i])
            {
                q = p[i] + r[j-i];
                s[j] = i;
            }
            
        }
        r[j] = q;
    }
    return r,  s;
}

void print_cut_rod_solution(int *p, int n){
    int *r, *s;
    (r, s) = extended_bottom_up_cut_rod(p, n);
    while (n > 0)
    {
        cout << s[n] << '\n';
        n -= s[n];
    }
}

int main(int argc, char const *argv[])
{
    int p[111];

    int j, n;
    cin >> j;
    cin >> n;
    for (int i = 1; i <= j; i++)
    {
        cin >> p[i];
    }
    

    //printf("%d\n", cut_rod(p, 4));
    
    print_cut_rod_solution(p, n);
    return 0;
}

// g++ -o nome.cpp nome.exe

/* input utilizado
10
1 5 8 9 10 17 17 20 24 30
*/