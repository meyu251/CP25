#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> songs(n);
    for(int i = 0; i < n; i++){
        cin >> songs[i];
    }

    int left = 0, maxLength = 0;
    for(int right = 0; right < n; right++){
        while(find(songs.begin() + left, songs.begin() + right, songs[right]) != songs.begin() + right){
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;

    return 0;
}
