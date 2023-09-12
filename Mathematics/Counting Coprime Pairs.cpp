#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int L = 1e6 + 7;

ll divs[L];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // sieve
    vector<int> spf(L);
    // spf[1] = 1;
    for (int i = 2; i <= L; i++){
        if (spf[i] == 0){
            for (int j = i; j <= L; j += i){
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    //Important (ll) n!!!
    ll pairs = (ll)n * (n - 1) / 2;

    ll cnt = 0;
    for (int num = 0; num < n; num++){
        int x;
        cin >> x;

        vector<int> primes;
        primes.clear();
        while (x > 1){
            int num = spf[x];
            primes.push_back(num);
            while(x % num == 0)x/=num;
        }

        // bit mask PIE
        ll s = primes.size();
        for (int mask = 1; mask < (1 << s); mask++){
            int prod = 1;
            for (long k = 0; k < s; k++){
                if (mask & (1 << k)){
                    prod *= primes[k];
                }
            }
            cnt += (__builtin_popcount(mask) & 1 ? divs[prod] : -divs[prod]);//*(divs[prod]>1);
            divs[prod]++;
        }
    }
    cout << pairs - cnt;
}
