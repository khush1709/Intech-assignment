/*
Q. Write a piece of code to find the largest 5 digit prime number in the first 100 digits of Pi? 

Submitted by:
Khushal Gautam
CS20B1080
7891616255
*/
#include <iostream>
#include <iomanip>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int findLargest5DigitPrime(const string &pi) {
    int largestPrime = 0;

    for (int i = 0; i <= 95; ++i) { // Loop through the first 96 digits (there are only 96 5-digit numbers in the first 100 digits)
        string fiveDigits = pi.substr(i, 5);
        stringstream ss(fiveDigits);
        int num;
        ss >> num;

        if (!ss.fail() && isPrime(num) && num > largestPrime) {
            largestPrime = num;
        }
    }

    return largestPrime;
}

int main() {
    // reference: https://www.piday.org/million/
    string pi = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067";
    //cout << pi.size();

    int largestPrime = findLargest5DigitPrime(pi);

    cout << "The largest 5-digit prime number in the first 100 digits of Pi is: " << largestPrime << endl;

    return 0;
}

// Verification that 97169 is prime: https://numberempire.com/97169