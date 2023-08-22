#include <bits/stdc++.h>

using namespace std;

/* void sieve(int N)
    {
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i*i <= N; ++i)
        {
            if (isPrime[i])
            {
                for (int j = i*i; j <= N; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    } */
int primeCount(int M, int N){
    int count=0;
    for(int i=M; i<=N; i++){
        
    }
    return count;
}

int main()
{
    int test;
    vector<int>low, high;
    int a,b;
    cin>>test;
    for(int i=0; i<test; i++){
        cin>>a>>b;
        if(a>b) return 0;
        low.push_back(a);
        high.push_back(b);
    }
    
    for(int i=1; i<=test; i++){
        int count=0;
        count = primeCount(low[i-1], high[i-1]);
        cout<<"Case "<<i<<": "<<count;
    }
    
return 0;
}