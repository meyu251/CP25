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
