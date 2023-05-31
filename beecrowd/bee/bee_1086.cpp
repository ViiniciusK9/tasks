#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 112345

int t[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, l, k, i, v;
    while (cin >> n >> m && n != 0)
    {
        cin >> l >> k;
        for (i = 0; i < k; i++)
        {
            cin >> t[i];
        }
        if ((n * 100) % l != 0 && (m * 100) % l != 0)
        {
            cout << "impossivel\n";
        } else if ((n * 100) % l != 0) {
            sort(t, t+k);
            v = i = 0;
            int j = k-1, stop = (m * 100), qnt = 0;
            while (v < stop && i <= j)
            {
                if (t[j] > n)
                {
                    j--;
                } else if (t[j] == n) {
                    j--;
                    v += l;
                    qnt++;
                } else if ((t[j] + t[i]) == n) {
                    j--;
                    i++;
                    v += l;
                    qnt += 2;
                } else if ((t[j] + t[i]) > n){
                    j--;
                } else {
                    i++;
                }
            }
            if (v == stop)
            {
                cout << qnt << '\n';
            } else {
                cout << "impossivel\n";
            }
            

        } else if ((m * 100) % l != 0) {
            sort(t, t+k);
            v = i = 0;
            int j = k-1, stop = (n * 100), qnt = 0;
            while (v < stop && i <= j)
            {
                if (t[j] > m)
                {
                    j--;
                } else if (t[j] == m) {
                    j--;
                    v += l;
                    qnt++;
                } else if ((t[j] + t[i]) == m) {
                    j--;
                    i++;
                    v += l;
                    qnt += 2;
                } else if ((t[j] + t[i]) > m){
                    j--;
                } else {
                    i++;
                }
            }
            if (v == stop)
            {
                cout << qnt << '\n';
            } else {
                cout << "impossivel\n";
            }

        } else {
            sort(t, t+k);
            v = i = 0;
            int j = k-1, stop = (m * 100), qnt1 = 0;
            while (v < stop && i <= j)
            {
                //DBG(v);
                //DBG(stop);
                if (t[j] > n)
                {
                    j--;
                } else if (t[j] == n) {
                    j--;
                    v += l;
                    qnt1++;
                } else if ((t[j] + t[i]) == n && i != j) {
                    j--;
                    i++;
                    v += l;
                    qnt1 += 2;
                } else if ((t[j] + t[i]) > n){
                    j--;
                } else {
                    i++;
                }
            }

            if (v != stop)
            {
                qnt1 = -1;
            }
            

            v = i = 0;
            j = k-1, stop = (n * 100);
            int qnt2 = 0;
            while (v < stop && i <= j)
            {
                //DBG(v);
                //DBG(stop);
                if (t[j] > m)
                {
                    j--;
                } else if (t[j] == m) {
                    j--;
                    v += l;
                    qnt2++;
                } else if ((t[j] + t[i]) == m && i != j) {
                    j--;
                    i++;
                    v += l;
                    qnt2 += 2;
                } else if ((t[j] + t[i]) > m){
                    j--;
                } else {
                    i++;
                }
            }

            if (v != stop)
            {
                qnt2 = -1;
            }

            if (qnt1 == -1 && qnt2 == -1)
            {
                cout << "impossivel\n";
            } else if (qnt1 == -1) {
                cout << qnt2 << '\n';
            } else if (qnt2 == -1) {
                cout << qnt1 << '\n';
            } else {
                cout << min(qnt1, qnt2) << '\n';
            }
        }
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome