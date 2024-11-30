#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int n, sum;
    cin >> n >> sum;
    cin.ignore();
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    return 0;
}
