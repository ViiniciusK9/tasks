#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 200045


int n;
int vet[MAX];
int r[MAX];
int t[MAX];

/*
int solve() // TIME LIMITED EXCEEDED
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vet[j] < vet[i])
            {
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (memo[i] > ans)
        {
            ans = memo[i];
        }
    }
    return ans;
}
*/



// BUSCAR UMA IMPLEMENTAÇÃO N LOG(N)

int ceilIndex(int t[], int end, int s)
{
    int start = 0;
    int middle;
    int len = end;
    while(start <= end){
        middle = (start + end)/2;
        if(middle < len && vet[t[middle]] < s && s <= vet[t[middle+1]]){
            return middle+1;
        }else if(vet[t[middle]] < s){
            start = middle+1;
        }else{
            end = middle-1;
        }
    }
    return -1;
}

int LIS() // n log(n)
{
    t[0] = 0;
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        if (vet[t[0]] > vet[i])
        {
            t[0] = i;
        }
        else if (vet[t[len]] < vet[i])
        {
            len++;
            t[len] = i;
            r[t[len]] = t[len-1];
        }
        else
        {
            int index = ceilIndex(t, len, vet[i]);
            t[index] = i;
            r[t[index]] = t[index-1];
        }
    }

    return len+1;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    memset(r, -1, sizeof(-1));

    cout << LIS() << '\n';


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome