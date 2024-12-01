#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> stickLength(n);
    for(int i = 0; i < n; i++){
        cin >> stickLength[i];
    }
    sort(stickLength.begin(), stickLength.end());

    long long ans = 0;
    int mid = stickLength[n/2];
    
    for(int i = 0; i < n; i++){
        ans += abs(mid - stickLength[i]);
    }

    cout << ans << endl;

    return 0;
}


/*
Time limit: 1.00 s
Memory limit: 512 MB



There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?
Input
The first input line contains an integer n: the number of sticks.
Then there are n integers: p_1,p_2,\ldots,p_n: the lengths of the sticks.
Output
Print one integer: the minimum total cost.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le p_i \le 10^9

Example
Input:
5
2 3 1 5 2

Output:
5
*/
