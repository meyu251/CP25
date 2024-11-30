#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n, sum;
    cin >> n >> sum;
    cin.ignore();
    vector<pair<int, int>> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i].first;
        numbers[i].second = i+1;
    }
    sort(numbers.begin(), numbers.end());

    int left = 0, right = n-1;

    while (left < right){
        int tmp = numbers[left].first + numbers[right].first;

        if(tmp == sum){
            int index1 = min(numbers[left].second, numbers[right].second);
            int index2 = max(numbers[left].second, numbers[right].second);

            cout << index1 << " " << index2 << endl;
            return 0;
        }
        else if (tmp > sum){
            right--;
        }
        else{
            left++;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;

    return 0;
}


/*
Time limit: 1.00 s
Memory limit: 512 MB



You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x,a_i \le 10^9

Example
Input:
4 8
2 7 5 1

Output:
2 4
*/
