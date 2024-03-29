#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 1123456;

array<int, MAX> arr;
vector<int> vec;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vec.reserve(MAX);
    int n, q, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vec.push_back(m);
    }

    sort(vec.begin(), vec.end());

    int j = 0, qnt = 0;

    for (int i = 1; i < MAX; i++)
    {

        while (j <= n-1 && vec[j] <= i)
        {
            qnt++;
            j++;
        }
        arr[i] = qnt;
    }
    
    
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> m;
        if (m >= 100000) {
            cout << n << '\n';
        } else {
            cout << arr[m] << '\n';
        }
    }
    



    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome