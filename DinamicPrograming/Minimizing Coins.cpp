#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    if (coins[0] > x) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> dp(x+1, -1);
    int currCoin = coins[0], tmp, value1, value2;

    // Handle first coin
    dp[currCoin] = 1;  // can make sum = currCoin using 1 coin
    // Fill remaining sums using only first coin
    for(int j = currCoin+1; j <= x; j++){
        if(dp[j-currCoin] != -1){
            dp[j] = dp[j-currCoin] + 1;  // propagate solution if possible
        }
    }

    // Fill DP table for remaining coins
    for(int i = 1; i < n; i++){
        currCoin = coins[i];

        for(int j = 1; j <= x; j++){
            // Case 1: Current sum is less than coin value
            // Can only use solution without current coin
            if(j < currCoin){
                continue;
            }

            // Case 2: Sum equals current coin value
            // Can make it using just one coin
            if(j == currCoin){
                dp[j] = 1;
                continue;
            }

            // Case 3: Sum > coin value
            // Try both options: use current coin or don't use it
            value1 = dp[j];         // don't use current coin
            value2 = dp[j-currCoin];  // use current coin

            // Handle all possible combinations of valid/invalid (-1) values
            if(value1 == -1 && value2 == -1){
                dp[j] = -1;  // no valid solution exists
            }
            else if(value1 == -1){
                dp[j] = value2 + 1;  // only solution using current coin is valid
            }
            else if(value2 == -1){
                dp[j] = value1;  // only solution without current coin is valid
            }
            else{
                dp[j] = min(value1, value2 + 1);  // take minimum of both valid solutions
            }
        }
    }

    // Final answer is in dp[n-1][x]
    cout << dp[x] << endl;

    return 0;
}



/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 11
1 5 7

Output:
3
*/