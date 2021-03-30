https://leetcode.com/problems/reverse-string/submissions/

class Solution {
public:
    
    void swap(char &a, char &b)
    {
        char c;
        c = a;
        a = b;
        b = c;
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            swap(s[i], s[n-i-1]);
        }
    }
};