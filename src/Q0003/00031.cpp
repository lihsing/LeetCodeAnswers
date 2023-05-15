#include <string>
#include <unordered_set>


using namespace std;


class Solution {
public:
    static int lengthOfLongestSubstring(string s);
};
int Solution::lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    int longest = 0;
    for (int i=0; i<s.size(); ++i) {
        unordered_set<char> tmp;
        for (int j=i; j<s.size(); ++j) {
            if (tmp.find(s[j]) == tmp.end()) {
                tmp.insert(s[j]);
            } else {
                break;
            }
        }
        if (tmp.size() > longest) {
            longest = tmp.size();
        }
    }
    return longest;
}


void example1() {
    assert(Solution::lengthOfLongestSubstring(string("abcabcbb")) == 3);
}


void example2() {
    assert(Solution::lengthOfLongestSubstring(string("bbbbb")) == 1);
}


void example3() {
    assert(Solution::lengthOfLongestSubstring(string("pwwkew")) == 3);
}


int main() {
    example1();
    example2();
    example3();
    return 0;
}