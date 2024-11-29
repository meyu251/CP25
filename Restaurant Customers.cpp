#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n;
    cin >> n;
    cin.ignore();

    vector<int> arriveTime(n);
    vector<int> leaveTime(n);

    for(int i = 0; i < n; i++){
        cin >> arriveTime[i];
        cin >> leaveTime[i];
        cin.ignore();
    }
    sort(arriveTime.begin(), arriveTime.end());
    sort(leaveTime.begin(), leaveTime.end());

    int count = 0, ans = 0;

    for(int i = 0, j = 0; i < n;){
        if(arriveTime[i] < leaveTime[j]){
            count++;
            i++;
            if(count > ans){
                ans = count;
            }
        }
        else{
            count--;
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.
Constraints

1 <= n <= 2*10^5
1 <= a < b <= 10^9

Example
Input:
3
5 8
2 4
3 9

Output:
2

*/
