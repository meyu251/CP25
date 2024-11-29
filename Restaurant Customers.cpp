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
