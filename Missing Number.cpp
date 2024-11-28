#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int findMissingNumber(const std::vector<int>& arr){
    
    int head = 0;
    int tail = arr.size()-1;
    int mid;

    while (head <= tail){
        mid = (head+tail)/2;

        if(arr[mid] == mid+1){
            head = mid+1;
        }
        else{
            if(mid == 0 || arr[mid-1] == mid){
                return mid+1;
            }
            tail = mid-1;
        }
    }
    
    return head+1;
}

int main(){

    using namespace std;

    int n;
    cin >> n;
    cin.ignore();

    vector<int> arr;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;

    while (iss >> num){
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    cout << findMissingNumber(arr);

    return 0;
}