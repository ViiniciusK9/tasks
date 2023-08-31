#include<bits/stdc++.h>

using namespace std;

int vetor[1000005];
int add[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num;
    long long x;
    long long y = 0;
    cin >> num;
    
    for (int i = 0; i < num; i++)
    {
        cin >> vetor[i];
        add[i] = 0;
    }

    while (true)
    {
        if (vetor[y] % 2 == 0 and y == 0)
        {
            add[y] = 1;
            if (vetor[y] > 0){
                vetor[y]--;
            }
            break;
        }
        else if (vetor[y] % 2 == 0)
        {
            add[y] = 1;
            if (vetor[y] > 0)
                vetor[y]--;
            y--;
        }
        else if (vetor[y] % 2 == 1 && y == num - 1)
        {
            add[y] = 1;
            if (vetor[y] > 0)
                vetor[y]--;
            break;
        }
        else if (vetor[y] % 2 == 1)
        {
            vetor[y]--;
            add[y] = 1;
            y++;
        }
    }
    x = 0;
    y = 0;
    for (int i = 0; i < num; i++)
    {
        y += vetor[i];
        x += add[i];
    }
    cout << x << " " << y << endl;

    return 0;
}