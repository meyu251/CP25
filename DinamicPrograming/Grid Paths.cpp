#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){

    int n;
    cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n, 0));
    char c;

    cin >> c;
    if(c == '*'){
        cout << 0 << endl;
        return 0;
    }
    else{
        grid[0][0] = 1;    
    }

    // handle first line
    for(int i = 1; i < n; i++){
        cin >> c;
        if(grid[i-1][0] == -1 || c == '*'){
            grid[i][0] = -1;
        }
        else{
            grid[i][0] = 1;
        }
    }

    ll tmp = -1;
    int mod = 1e9 + 7;

    for(int j = 1; j < n; j++){
        for(int i = 0; i < n; i++){
            cin >> c;
            if(i == 0){
                if(c == '*' || grid[i][j-1] == -1){
                    grid[i][j] = -1;
                }
                else{
                    grid[i][j] = 1;
                }
            }
            else{
                if(c == '*'){
                    tmp = -1;
                }
                else if(grid[i-1][j] == -1 && grid[i][j-1] == -1){
                    tmp = -1;
                }
                else if(grid[i-1][j] == -1){
                    tmp = grid[i][j-1];
                }
                else if(grid[i][j-1] == -1){
                    tmp = grid[i-1][j];
                }
                else{
                    tmp = (grid[i-1][j] + grid[i][j-1]) % mod;
                }
                grid[i][j] = tmp;
            }
        }
    }

    int ans = grid[n-1][n-1] == -1 ? 0 : grid[n-1][n-1];
    cout << ans << endl;

    return 0;
}
