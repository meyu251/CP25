#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> coins(n);
    long long ans = 1;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    for(int i = 0; i < n; i++){
        if(coins[i] > ans){
            break;
        }
        ans += coins[i];
    }

    cout << ans << endl;

    return 0;
}
