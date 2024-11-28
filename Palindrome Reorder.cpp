#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

    using namespace std;

int main(){

    string s, order_s, ans;
    getline(cin, s);
    istringstream iss(s);
    char c;
    while(iss >> c){
        order_s += c;
    }

    sort(order_s.begin(), order_s.end());
    size_t length = order_s.length();
    ans.resize(length, ' ');
    char c1, c2, mid='\0';
    bool flag = false;
    size_t i=0, left=0, right=length-1;

    while (left < right){
        c1 = order_s[i];
        c2 = order_s[i+1];
        if(c1 == c2){
            ans[left] = ans[right] = c1;
            left++;
            right--;
            i += 2;
        }
        /*
        means we already have a single char for the middle of the palindrom,
        or that length is even, so we can't have a single char
        */
        else if (flag || (length & 1) == 0){
            cout << "NO SOLUTION";
            return 0;
        }
        else{
            mid = order_s[i];
            flag = true;   // means we can't have another single char
            i++;
        }
    }
    if(left == right){
        ans[right] = (mid == '\0') ? order_s[i] : mid;
    }

    cout << ans;

    return 0;
}