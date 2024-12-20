#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool match(char c1, char c2){
    return c1 == 'R' || c2 == 'R' || c1 == c2;
}

int charValue(char c){
    switch (c){
    case 'A':
        return 20;
    case 'T':
        return 10;
    case 'J':
    case 'Q':
    case 'K':
        return 15;
    case 'R':
        return 50;
    default:
        return c - '0';
    }
}

int main(){

    while (true){
        int n;
        cin >> n;
        cin.ignore();
        if(n == 0){
            break;
        }

        string input;
        char c;
        vector<char> line1;
        vector<char> line2;

        getline(cin, input);
        istringstream iss1(input);
        while (iss1 >> c){
            line1.push_back(c);
        }
        getline(cin, input);
        istringstream iss2(input);
        while (iss2 >> c){
            line2.push_back(c);
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < n+1; j++){
                // option 1 - don't take any of those cards
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                // option 2 - take those cards(they match each other)
                if (match(line1[i - 1], line2[j - 1])){
                    int cardsValue;
                    if (line1[i - 1] == 'R' && line2[j - 1] == 'R'){
                        cardsValue = 100;
                    }
                    else if (line1[i - 1] == 'R'){
                        cardsValue = charValue(line2[j - 1]) * 2;
                    }
                    else{
                        cardsValue = charValue(line1[i - 1]) * 2;
                    }

                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + cardsValue);
                }
            }
        }

        cout << dp[n][n] << endl;
    }

    return 0;
}

/*
Kabloom
The card game Kabloom is played with multiple decks of playing cards. Players are dealt 2 n cards, face up and arranged in two rows of n cards. The players must discard some of the cards, so that the cards that remain in the first row match the rank of the cards that remain in the second row. The cards match only in rank (e.g. an Ace of Hearts matches any other Ace regardless of suit), but they must appear in the same order in each row. The players are not able to rearrange the order in which the cards appear. Note also that a Joker can match any card including another Joker .
The goal is to maximize the sum of the point value of the cards that remain. Aces are worth 20 points, face cards are worth 15 points, and the numbered cards are worth the number on the card (e.g. the Seven of Clubs is worth 7 points).The value of a Joker is equal to the card with which it is matched, e.g. a Joker matched with an Ace is worth 20 points, a Joker matched with a face card is worth 15 points, etc. If two Jokers are matched with each other, they are worth 50 points each.

Task
Write a program that determines the value of the best hand given the two rows of cards. For example, consider the hand that is dealt below.

IMAGE 1

The best possible hand has a value of 140, and is obtained by keeping the cards shown below:

IMAGE 2

Input
The input is made up of multiple test cases (#test cases<=30, if 1<=n<=10 or #test cases<=10 if 10<=n<=1000). Each test case contains three lines of input.
The first line in each test case is an integer n , 1 <= n <= 1,000, indicating how many cards are in each row.
The second line of the test case will contain n symbols representing the ranks of the cards in the first row. Each symbol will be chosen from the list {A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, R}. The symbols in the list represent the following ranks, respectively, {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Joker}. Similarly, the third line of the test case will contain the n symbols of the cards in the second row.
The input will end with a 0 on a line by itself.

Output
For each test case, output the value of the best Kabloom hand on a line by itself. Note that the cards that comprise the best Kabloom hand may not be unique for a test case.
Note: Every line of output should end in a newline character .

Sample Input 1
9
6 3 7 4 2 A K R T
3 5 4 7 R A Q K T
0

Sample Output 1
140

Sample Input 2
7
R R 5 4 A T Q
Q 3 T A 8 8 8
13
A 2 3 4 5 6 7 8 9 T J Q K
K Q J T 9 8 7 6 5 4 3 2 A
6
A A A A A A
K Q J T 9 8
13
A 2 3 4 5 6 7 8 9 T J Q K
A 2 3 4 5 6 7 8 9 T J Q K
0

Sample Output 2
90
40
0
238
*/