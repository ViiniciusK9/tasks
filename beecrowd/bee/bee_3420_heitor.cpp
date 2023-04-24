#include<bits/stdc++.h>
using namespace std;
#define MAX (int)10e18///o valor maximo que a resposta pode ser

long long bTries(long long top, long long bottom, long long nCards){
    long long m;
    while (bottom <= top) {
            m = bottom + (top - bottom) / 2;
    
            if ((m*(m*3+1)/2) == nCards)
                return m;
    
            if (m*(m*3+1)/2 < nCards)
                bottom = m + 1;
    
            else
                top = m - 1;
        }
    if(m*(m*3+1)/2>nCards){
        m--;
    }
        return m;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t, j, ncards;
    int n;
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>t;
         ncards = 0;
        cout<<bTries(t%MAX, 0, t)<<"\n";
    }
    return 0;
}
