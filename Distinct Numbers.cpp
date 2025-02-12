#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int ans = 1;

    for(int i = 0; i < n-1; i++){
        if(numbers[i] != numbers[i+1]){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}


/*
Time limit: 1.00 s
Memory limit: 512 MB



You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
Input
The first input line has an integer n: the number of values.
The second line has n integers x_1,x_2,\dots,x_n.
Output
Print one integers: the number of distinct values.
Constraints

1 <= n <= 2*10^5
1 <= x_i <= 10^9

Example
Input:
5
2 3 2 2 3

Output:
2
*/