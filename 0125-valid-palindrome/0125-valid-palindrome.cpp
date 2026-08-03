class Solution {
public:
    bool isPalindrome(string s) {

        int st = 0;
        int end = s.length() - 1;

        while (st < end) {

            // Skip non-alphanumeric from left
            while (st < end && !isalnum(s[st])) {
                st++;
            }

            // Skip non-alphanumeric from right
            while (st < end && !isalnum(s[end])) {
                end--;
            }

            // Compare (ignore case)
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};