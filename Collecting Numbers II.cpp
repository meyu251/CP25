#include <iostream>
#include <vector>

using namespace std;

int collectNums(const vector<int>& numbers, int n){

    vector<bool> found(n+1, false);
    int rounds = 0;

    for(int num : numbers){
        if(!found[num - 1]){
            rounds++;
        }
        found[num] = true;
    }

    return rounds;
}

int main(){

    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    cin.ignore();

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cin.ignore();

        swap(numbers[a-1], numbers[b-1]);

        cout << collectNums(numbers, n) << endl;
    }

    return 0;
}

/*
You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.
Input
The first line has two integers n and m: the array size and the number of operations.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.
Output
Print m integers: the number of rounds after each swap.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
4 2 1 5 3
2 3
1 5
2 3

Output:
2
3
4
*/