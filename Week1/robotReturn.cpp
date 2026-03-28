#include <iostream>
#include <string>
using namespace std;

bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (char c : moves) {
        if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == 'R') x++;
        else if (c == 'L') x--;
    }

    return x == 0 && y == 0;
}

void run_circle() {
    cout << (judgeCircle("UD") ? "true" : "false") << endl;
    cout << (judgeCircle("LL") ? "true" : "false") << endl;
}