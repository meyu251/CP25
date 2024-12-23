#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;



int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> songs(n);
    for(int i = 0; i < n; i++){
        cin >> songs[i];
    }

    unordered_map<int, int> lastPos;
    int left = 0, maxLength = 0;
    for(int right = 0; right < n; right++){
        if(lastPos.count(songs[right]) && lastPos[songs[right]] >= left){
            left = lastPos[songs[right]] + 1;
        }

        lastPos[songs[right]] = right;

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;

    return 0;
}

/*
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?
Input
The first input line contains an integer n: the number of songs.
The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
Output
Print the length of the longest sequence of unique songs.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le k_i \le 10^9

Example
Input:
8
1 2 1 3 2 7 4 2

Output:
5
*/
