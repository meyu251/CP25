#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n, maxWeight;
    cin >> n >> maxWeight;
    cin.ignore();
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());

    int ans = 0, head = 0, tail = n-1;

    while (head < tail){
        if(weights[tail] + weights[head] <= maxWeight){
            head++;
        }
        tail--;
        ans++;
    }
    if(head == tail){ans++;}

    cout << ans;

    return 0;
}


/*
Time limit: 1.00 s
Memory limit: 512 MB



There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line contains n integers p_1,p_2,\ldots,p_n: the weight of each child.
Output
Print one integer: the minimum number of gondolas.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x \le 10^9
1 \le p_i \le x

Example
Input:
4 10
7 2 3 9

Output:
3
*/
