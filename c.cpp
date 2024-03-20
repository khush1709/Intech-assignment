/*
Q. Given an array of integers representing the elevation of a roof structure at
various positions, each position is separated by a unit length, Write a program
to determine the amount of water that will be trapped on the roof after heavy
rainfall
Example:
input : [2 1 3 0 1 2 3]
Ans : 7 units of water will be trapped

https://www.geeksforgeeks.org/trapping-rain-water/

Go through the above code for the solution. 

The next phase is that the values are now not discrete but analog. E.g. I give an equation of function that is bounded, can you predict how many units of water gets trapped. 

Submitted by:
Khushal Gautam
CS20B1080
7891616255
*/

#include <bits/stdc++.h>

using namespace std;

// Function to calculate trapped water for analog values
double trappedWater(const vector<double>& elevations) {
    int n = elevations.size();
    if (n <= 2) return 0;

    vector<double> leftMax(n), rightMax(n);

    // Initialize left max array
    leftMax[0] = elevations[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], elevations[i]);
    }

    // Initialize right max array
    rightMax[n - 1] = elevations[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], elevations[i]);
    }

    double water = 0;

    // Calculate trapped water
    for (int i = 0; i < n; ++i) {
        water += min(leftMax[i], rightMax[i]) - elevations[i];
    }

    return water;
}

int main() {
    // Example with analog values: polynomial function
    // Function: 0.1x^3 + 0.1x^2 - 2x + 4
    // Range: x = -5 to x = 5
    
    vector<double> elevations;
    int size = 101; // Number of points to discretize the range [-5, 5]
    for (int i = 0; i < size; ++i) {
        // Discretize the analog function
        double x = -5.0 + (10.0 * i) / (size - 1); // Normalize x to [-5, 5]
        double elevation = 0.1 * pow(x, 3) + 0.1 * pow(x, 2) - 2 * x + 4; // Evaluate function
        elevations.push_back(elevation);
    }

    // Set boundary heights
    elevations.front() = 0.1 * pow(-5, 3) + 0.1 * pow(-5, 2) - 2 * (-5) + 4; // Height at x = -5
    elevations.back() = 0.1 * pow(5, 3) + 0.1 * pow(5, 2) - 2 * 5 + 4; // Height at x = 5

    double trapped = trappedWater(elevations);
    cout << "Units of water trapped: " << trapped << endl;

    return 0;
}
