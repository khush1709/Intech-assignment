/*
Q. Write a piece of code to determine if two rectangles are intersecting each other or not?

Submitted by:
Khushal Gautam
CS20B1080
7891616255
*/
#include <iostream>

using namespace std;

bool areRectanglesIntersecting(pair<int, int> rect1_top_left, pair<int, int> rect1_bottom_right, 
                                pair<int, int> rect2_top_left, pair<int, int> rect2_bottom_right) {
    // Check for intersection
    if (rect1_top_left.first < rect2_bottom_right.first && rect1_bottom_right.first > rect2_top_left.first &&
        rect1_top_left.second < rect2_bottom_right.second && rect1_bottom_right.second > rect2_top_left.second) {
        return true;
    } else {
        return false;
    }
}

int main() {
    pair<int, int> rect1_top_left = make_pair(0, 0);
    pair<int, int> rect1_bottom_right = make_pair(3, 3);
    pair<int, int> rect2_top_left = make_pair(4, 2);
    pair<int, int> rect2_bottom_right = make_pair(5, 5);

    if (areRectanglesIntersecting(rect1_top_left, rect1_bottom_right, rect2_top_left, rect2_bottom_right)) {
        cout << "Rectangles intersect." << endl;
    } else {
        cout << "Rectangles do not intersect." << endl;
    }

    return 0;
}

