#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct customer {
    int checkIn, checkOut, roomNumber;
};

int main() {
    int n;
    cin >> n;
    vector<customer> customers(n);
    
    // Read input
    for(int i = 0; i < n; i++) {
        cin >> customers[i].checkIn >> customers[i].checkOut;
        customers[i].roomNumber = 0;
    }
    
    // Create index vector for sorting
    vector<int> orderCustomers(n);
    for(int i = 0; i < n; i++) {
        orderCustomers[i] = i;
    }
    
    // Sort by check-in time, then check-out time
    sort(orderCustomers.begin(), orderCustomers.end(), [&customers](int a, int b){
        if(customers[a].checkIn == customers[b].checkIn) {
            return customers[a].checkOut < customers[b].checkOut;
        }
        return customers[a].checkIn < customers[b].checkIn;
    });
    
    // Keep track of when each room becomes available
    set<pair<int, int>> availableRooms;
    int nextRoom = 2;
    int idx = orderCustomers[0];

    // first customer gets room number 1, then we dont have to handle case this set is empty..
    customers[idx].roomNumber = 1;
    availableRooms.insert({customers[idx].checkOut, 1});
    
    // Process each customer
    for(int i = 1; i < n; i++) {
        idx = orderCustomers[i];
        
        // Check for available room
        auto it = availableRooms.begin();
        if(it->first < customers[idx].checkIn){
            customers[idx].roomNumber = it->second;
            availableRooms.erase(it);
            availableRooms.insert({customers[idx].checkOut, customers[idx].roomNumber});
        }
        // If no existing room can be reused, create new room
        else{
            customers[idx].roomNumber = nextRoom;
            availableRooms.insert({customers[idx].checkOut, nextRoom});
            nextRoom++;
        }
    }
    
    // Output results
    cout << availableRooms.size() << endl;
    for(int i = 0; i < n-1; i++) {
        cout << customers[i].roomNumber << " ";
    }
    cout << customers[n-1].roomNumber << endl;
    
    return 0;
}

/*
Time limit: 1.00 s
Memory limit: 512 MB



There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
Input
The first input line contains an integer n: the number of customers.
Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.
Output
Print first an integer k: the minimum number of rooms required.
After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,\ldots,k. You can print any valid solution.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a \le b \le 10^9

Example
Input:
3
1 2
2 4
4 4

Output:
2
1 2 1
*/