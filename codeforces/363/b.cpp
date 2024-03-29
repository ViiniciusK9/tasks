#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 212345;

int n, k;
array<int, MAX> arr;
array<int, MAX> tab;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(arr.begin(), arr.end(), 0);

    cin >> n >> k;

    int start = 0, aux, ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        arr[i] = aux;
        if (start >= k) {

            tab[i] = ans-arr[i-k]+arr[i];
            ans = tab[i];
            //DBG(tab[i]);
        } else {
            start++;
            ans += aux;
            tab[i] = ans;
        }
    }

    
    long long ans1 = arr[0];
    int ind = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (arr[i] < ans1) {
                ind = i;
                ans1 = tab[i];
            }
        }
        cout << ind+1 << '\n';
        return 0;
    }

    ans1 = tab[k-1];
    ind = k-1;
    if (n == k) {
        //cout << tab[n-1] << '\n';
        cout << "1" << '\n';
    } else {
        for (int i = k-1; i < n; i++)
        {
            if (tab[i] < ans1) {
                ind = i;
                ans1 = tab[i];
            }
        }
        //DBG(ind);
        //DBG(ans1);
        cout << ind - (k-2) << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome