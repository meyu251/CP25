#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void myPrint(vector<bool>& vec, int n){

    for(int i = 0; i < n-1; i++){
        cout << vec[i] << " ";
    }

    cout << vec[n-1] << endl;
}

int main(){

    int n;
    cin >> n;
    cin.ignore();
    
    vector<pair<int, int>> ranges(n);
    for(int i = 0; i < n; i++){
        cin >> ranges[i].first >> ranges[i].second;
        cin.ignore();
    }

    vector<int> sortedRanges(n); //going to be sorted
    for(int i = 0; i < n; i++){sortedRanges[i] = i;}
    sort(sortedRanges.begin(), sortedRanges.end(), [&ranges](int a, int b){
        if(ranges[a].first == ranges[b].first){
            return ranges[a].second > ranges[b].second;
        }
        return ranges[a].first < ranges[b].first;
    });

    vector<bool> containsOther(n, false);
    vector<bool> contained(n, false);

    for(int i = 0; i < n; i++){
        int idx1 = sortedRanges[i];

        for(int j = i+1; j < n; j++){
            int idx2 = sortedRanges[j];

            // If second range starts after first range ends, we can skip the rest
            if(ranges[idx2].first > ranges[idx1].second){break;}

            if(ranges[idx2].second <= ranges[idx1].second){
                containsOther[idx1] = true;
                contained[idx2] = true;
                // break;
            }
        }    
    }

    myPrint(containsOther, n);
    myPrint(contained, n);

    return 0;
}

/*
Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.
Range [a,b] contains range [c,d] if a \le c and d \le b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) if it contains some other range (1) or not (0).
Then print a line that describes for each range (in the input order) if some other range contains it (1) or not (0).
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x < y \le 10^9

Example
Input:
4
1 6
2 4
4 8
3 6

Output:
1 0 0 0
0 1 0 1
*/