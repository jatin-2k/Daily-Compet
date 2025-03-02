#include <iostream>
#include <vector>

/*
* based on following mapping, count the number of substrings whose sum of substring mappings is divisable by length of substring
* mapping
* ab1, cde2. fgh3, ijk4, lmn5, opq6, rst7, uvw8, xyz9
*/

using namespace std;

int getDigit(char ch) {
    if (ch <= 'b') return 1;
    if (ch <= 'e') return 2;
    if (ch <= 'h') return 3;
    if (ch <= 'k') return 4;
    if (ch <= 'n') return 5;
    if (ch <= 'q') return 6;
    if (ch <= 't') return 7;
    if (ch <= 'w') return 8;
    return 9;
}

int countValidSubstrings(const string &s) {
    int count = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += getDigit(s[j]);
            if (sum % (j - i + 1) == 0) count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << countValidSubstrings(s) << endl;
    return 0;
}
