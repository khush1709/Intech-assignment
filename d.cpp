/*
Q. Count Ways to Express a Number as the Sum of Consecutive Natural Numbers
Given a natural number n, we are asked to find the total number of ways to express n as the sum of consecutive natural numbers.

Example 1:Input: 15
Output: 3
Explanation: There are 3 ways to represent 15 as sum of consecutive natural numbers as follows:
1 + 2 + 3 + 4 + 5 = 15
4 + 5 + 6 = 15
7 + 8 = 15

Submitted by:
Khushal Gautam
CS20B1080
7891616255
*/

#include <iostream>

using namespace std;

int countWays(int n) {
    int count = 0;
    for (int length = 1; length * (length + 1) < 2 * n; length++) {
        if ((n - (length * (length + 1)) / 2) % length == 0)
            count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the natural number n: ";
    cin >> n;

    int ways = countWays(n);
    cout << "Total number of ways to express " << n << " as the sum of consecutive natural numbers: " << ways << endl;

    return 0;
}
