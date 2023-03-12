#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) { // if the length of the strings is different, they can't be isomorphic
        return false;
    }

    unordered_map<char, char> map;
    unordered_map<char, bool> usedChars;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (map.find(c1) != map.end()) { // if c1 is already mapped to a character in t
            if (map[c1] != c2) { // and the mapping is not equal to c2, then they are not isomorphic
                return false;
            }
        } else { // if c1 is not yet mapped
            if (usedChars[c2]) { // if c2 is already used as a mapping for another character, then they are not isomorphic
                return false;
            }
            map[c1] = c2; // map c1 to c2
            usedChars[c2] = true; // mark c2 as used
        }
    }

    return true; // if we reach this point, the strings are isomorphic
}

int main() {
    string s1 = "mad";
    string t1 = "dam";

    string s2 = "pepsi";
    string t2 = "water";

    if (isIsomorphic(s1, t1)) {
        cout << s1 << " and " << t1 << " are isomorphic." << endl;
    } else {
        cout << s1 << " and " << t1 << " are not isomorphic." << endl;
    }

    if (isIsomorphic(s2, t2)) {
        cout << s2 << " and " << t2 << " are isomorphic." << endl;
    } else {
        cout << s2 << " and " << t2 << " are not isomorphic." << endl;
    }

    return 0;
}
