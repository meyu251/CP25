#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> coins(n);
    long long ans = 1;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    for(int i = 0; i < n; i++){
        if(coins[i] > ans){
            break;
        }
        ans += coins[i];
    }

    cout << ans << endl;

    return 0;
}

/*
Time limit: 1.00 s
Memory limit: 512 MB



You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
Input
The first input line has an integer n: the number of coins.
The second line has n integers x_1,x_2,\dots,x_n: the value of each coin.
Output
Print one integer: the smallest coin sum.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5
2 9 1 2 7

Output:
6
*/
