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

    int n;
    cin >> n;
    cin.ignore();
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    cin.ignore();

    cout << collectNums(numbers, n) << endl;

    return 0;
}

/*
You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Output
Print one integer: the number of rounds.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
5
4 2 1 5 3

Output:
3
*/