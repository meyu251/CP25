#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){

    int n;
    cin >> n;
    vector<ll> results(n+1);
    if(n < 7){
        switch(n){
            case 1:
                cout << 1 << endl;
                return 0;
            case 2:
                cout << 2 << endl;
                return 0;
            case 3:
                cout << 4 << endl;
                return 0;
            case 4:
                cout << 8 << endl;
                return 0;
            case 5:
                cout << 16 << endl;
                return 0;
            case 6:
                cout << 32 << endl;
                return 0;
            case 7:
                cout << 63 << endl;
                return 0;
        }
    }
    results[0] = 0;
    results[1] = 1;
    results[2] = 2;
    results[3] = 4;
    results[4] = 8;
    results[5] = 16;
    results[6] = 32;
    results[7] = 63;

    int mod = 1e9 + 7;
    ll tmp = 63;
    for(int i = 8; i < n+1; i++){
        tmp = ((tmp << 1) % mod - results[i-7] % mod + mod) % mod;
        results[i] = tmp;
    }

    cout << results[n] << endl;

    return 0;
}

/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4
*/
