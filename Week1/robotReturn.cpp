#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;

        for (char move : moves) {

            if (move == 'U')
                y++;
            else if (move == 'D')
                y--;
            else if (move == 'R')
                x++;
            else
                x--;
        }

        return x == 0 && y == 0;
    }
};

int main() {

    Solution sol;

    // Example 1
    string moves1 = "UD";
    cout << "Example 1: ";
    cout << (sol.judgeCircle(moves1) ? "true" : "false") << endl;

    // Example 2
    string moves2 = "LL";
    cout << "Example 2: ";
    cout << (sol.judgeCircle(moves2) ? "true" : "false") << endl;

    return 0;
}