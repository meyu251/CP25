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
    sort(orderCustomers.begin(), orderCustomers.end(), [&customers](int a, int b) {
        if(customers[a].checkIn == customers[b].checkIn) {
            return customers[a].checkOut < customers[b].checkOut;
        }
        return customers[a].checkIn < customers[b].checkIn;
    });
    
    // Keep track of when each room becomes available
    vector<pair<int, int>> roomAvailability;  // {checkout time, room number}
    int nextRoom = 1;
    
    // Process each customer
    for(int i = 0; i < n; i++) {
        int idx = orderCustomers[i];
        bool foundRoom = false;
        
        // Check all available rooms
        for(auto& room : roomAvailability) {
            if(room.first < customers[idx].checkIn) {
                // Can reuse this room
                customers[idx].roomNumber = room.second;
                room.first = customers[idx].checkOut;
                foundRoom = true;
                break;
            }
        }
        
        // If no existing room can be reused, create new room
        if(!foundRoom) {
            customers[idx].roomNumber = nextRoom;
            roomAvailability.push_back({customers[idx].checkOut, nextRoom});
            nextRoom++;
        }
        
        // Sort rooms by checkout time for next iteration
        sort(roomAvailability.begin(), roomAvailability.end());
    }
    
    // Output results
    cout << roomAvailability.size() << endl;
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