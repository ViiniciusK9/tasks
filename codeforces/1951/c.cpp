#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



int solve(int i) {

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    long long t, n, m, k, aux, qnt, mi, ans, qnt1;
    vector<int> vet;
    vector<int> vet2;
    vector<int> vet_aux;

    cin >> t;
    while (t--)
    {
        vet.clear();
        vet2.clear();
        vet_aux.clear();
        cin >> n >> m >> k;
        mi = 10e9+1;
        
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet.push_back(aux);
            vet2.push_back(aux);
        }

        sort(vet.begin(), vet.end());



        if (k > m) {

            

            qnt = k/m;

            qnt1 = k/m;
            if (k%m != 0) qnt1++;
            set<int> con;
            for (int i = 0; i < qnt1; i++)
            {
                con.insert(vet[i]);
            }
            int maxx = 0;
            for (int i = 0; i < n; i++)
            {
                if (qnt1 == 0) break;

                if (con.find(vet2[i]) != con.end()) {
                    //DBG(vet2[i]);
                    vet_aux.push_back(vet2[i]);
                    if (vet2[i] > maxx) maxx = vet2[i];
                    qnt1--;
                }
            }

            // se não der a divisão exata tem que somar mais k no ultimo numero
            ans = 0;
            int i = 0;
            int xx = k%m;

            int flag = 0;

            for (i = 0; i < qnt; i++)
            {
                if (i == qnt-1) {
                    //DBG((((vet_aux[i] + (i*m)) * m) + ((k%m) * (((i+1)*m) + vet_aux[i+1]))));
                    //DBG((((k%m) * (vet_aux[i] + (i*m))) + ((m) * (((i+1)*m) + vet_aux[i+1]))));
                    if (flag == 0 && k%m != 0) {
                        if (  (((vet_aux[i] + (i*m)) * m) + ((k%m) * (((i+1)*m) + vet_aux[i+1]))) < (((vet_aux[i] + (i*m)) * xx) + ((vet_aux[i+1] + ((i+1)*m - xx)) * m))        ) {
                            ans += (((vet_aux[i] + (i*m)) * m) + ((k%m) * ((i+1*m) + vet_aux[i+1]))); 
                        } else {
                            ans += ((vet_aux[i] + (i*m)) * xx) + ((vet_aux[i+1] + ((i+1)*m - xx)) * m);
                        }
                    } else {
                        ans += ((vet_aux[i] + (i*m)) * m);
                    }
                } else if (vet_aux[i] == maxx && k%m != 0) {
                    if (  (((vet_aux[i] + (i*m)) * m) + ((k%m) * (((i+1)*m) + vet_aux[i+1]))) < (((vet_aux[i] + (i*m)) * xx) + ((vet_aux[i+1] + ((i+1)*m - xx)) * m))        ) {
                        ans += (((vet_aux[i] + (i*m)) * m) + ((k%m) * ((i+1*m) + vet_aux[i+1]))); 
                    } else {
                        ans += ((vet_aux[i] + (i*m)) * xx) + ((vet_aux[i+1] + ((i+1)*m - xx)) * m);
                        flag = 1;
                    }
                }
                 else {
                    ans += ((vet_aux[i] + (i*m)) * m);
                }
                //DBG(ans);

            }

            
            /*

            if (k%m != 0) {
                ans += ((k%m) * ((i*m) + vet_aux[i]));
            }

            ((k%m) * ((i+1*m) + vet_aux[i+1]))

            ((vet_aux[i] + (i*m)) * m)

            ((k%m) * (vet_aux[i] + (i*m))) + ((m) * ((i+1*m) + vet_aux[i+1]))
            */
            

            cout << ans << '\n';
            

        } else {
            cout << (k * vet[0]) << '\n';
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome