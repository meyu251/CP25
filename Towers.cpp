#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solve(vector<int>& cubes, int n){

    int ans = 0;
    multiset<int> topCubes;
    for(int cube : cubes){
        auto availableTower = topCubes.upper_bound(cube);
        // if there is an available legal tower for this cube
        if(availableTower != topCubes.end()){
            topCubes.erase(availableTower);
        }
        else{
            ans++;
        }
        topCubes.insert(cube);
    }

    return ans;
}

int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<int> cubes(n);
    for(int i = 0; i < n; i++){
        cin >> cubes[i];
    }

    cout << solve(cubes, n) << endl;

    return 0;
}
