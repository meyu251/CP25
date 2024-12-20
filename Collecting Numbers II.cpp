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

    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    cin.ignore();

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cin.ignore();

        swap(numbers[a-1], numbers[b-1]);

        cout << collectNums(numbers, n) << endl;
    }

    return 0;
}
