#include <iostream>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    char result = 0;

    for (char c : s) result ^= c;
    for (char c : t) result ^= c;

    return result;
}
void run_find_diff() {
    string s = "abcd";
    string t = "abcde";

    cout << findTheDifference(s, t) << endl;
}