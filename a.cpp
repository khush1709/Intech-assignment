/*
Q. String compression
Implement a method to perform string compression. E.g. ‘aabcccccaaa’ should be a2b1c5a3. The code to implement this is given in the link - https://www.educative.io/answers/string-compression-using-run-length-encoding

Build a second compressor which takes the output of first compressor and optimizes further. 
The answer should be taken into second compressor and compress further.  
E.g. a2b2c1a3c3 should become ab2c1ac3. Please test at the end cases as well. The code should work with inputs like a20b20c1a4 – ab20c1a4. Test and show the result of the same.  
The compressed output should be put into a decompressor - 
ab2c1ac3 should return aabbcaaaccc. 
Write all the test cases to evaluate this and see if the results match. 

Submitted by:
Khushal Gautam
CS20B1080
7891616255
*/

#include <bits/stdc++.h>
using namespace std;

string compress(string s)
{
    int num = s.length(); // calculating length of the string
    int i = 0;
    string ans = ""; // the result string, which will be returned by the function
    while (i < num)
    {

        // Counting the repetitions of each character
        int repetition = 1;
        while (s[i] == s[i + 1] && i < num - 1)
        {
            repetition++;
            i++;
        }

        ans += s[i];                  // adding the character to the ans string
        ans += to_string(repetition); //  adding the count of the character to the ans string
        i++;
    }
    return ans;
}

string compress2(string s)
{
    string ans = "";
    int num = s.length(); // calculating length of the string
    int i = 0;
    int prevCount = 0;
    while (i < num)
    {
        char currentChar = s[i];
        i++;
        int count = 0;
        while (isdigit(s[i]))
        {
            count = count * 10 + (s[i] - '0');
            i++;
        }
        if(prevCount==count)
        {
            while(prevCount)
            {
                ans.pop_back();
                prevCount /= 10;
            }
        }
        ans += currentChar;
        ans += to_string(count);
        prevCount = count;
    }
    return ans;
}
string decompressor(string s)
{
    string ans = "";
    int num = s.length(); // calculating length of the string
    int i = 0;
    while (i < num)
    {
        // Checking if the character is a valid letter
        if (s[i] - 'a' < 0)
            return "Not a valid string";
        
        string temp = "";
        temp.push_back(s[i]);
        i++;

        // Extracting the characters until a digit is encountered
        while (i < num && s[i] - 'a' >= 0)
        {
            temp.push_back(s[i]);
            i++;
        }

        int count = 0;
        // Extracting the count of the characters
        while (i < num && isdigit(s[i]))
        {
            count = count * 10 + (s[i] - '0');
            i++;
        }

        // Appending the characters to the result string with the respective counts
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < count; k++)
            {
                ans += temp[j];
            }
        }
    }
    return ans;
} 


int main()
{
    string str = "aabbcaaaccc";
    string comp_str = compress(str);
    cout << "First Compression: " << comp_str << endl;
    // a2b2c1a3c3

    string comp2_str = compress2(comp_str);
    cout << "Second Compression: " << comp2_str << endl;
    // ab2c1ac3

    string decomp_str = decompressor(comp2_str);
    cout << "Decompression: " << decomp_str << endl;
    // aabbcaaaccc

    return 0;
}
