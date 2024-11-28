#include <iostream>
#include <vector>
#include <climits>


using namespace std;

void minDifference(vector<int>& arr, size_t p, long long& totalSum, long long currSum, long long& minDif){

    if(p == arr.size()){
        return;
    }

    long long tmp = abs(totalSum - currSum*2);
    if(tmp < minDif){
        minDif = tmp;
    }

    minDifference(arr, p+1, totalSum, currSum+arr[p], minDif);
    minDifference(arr, p+1, totalSum, currSum, minDif);

}

int main(){

    int n;
    cin >> n;
    cin.ignore();

    vector<int> weights(n);
    long long minDif = LONG_LONG_MAX;
    long long totalSum = 0;

    for(int i = 0; i < n; i++){
        cin >> weights[i];
        totalSum += weights[i];
    }

    minDifference(weights, 0, totalSum, 0, minDif);
    
    cout << minDif << endl;
    
    return 0;
}