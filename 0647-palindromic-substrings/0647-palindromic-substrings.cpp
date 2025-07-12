class Solution {
public:
    int countSubstrings(string s) {
        int len =s.length();
        int totalpalindrome = 0;
        for(int mid=0;mid<2*len-1;mid++){
            int low = mid/2;
            int high = low+(mid%2);
            while(low>=0&&high<len&&s[low]==s[high]){
                totalpalindrome++;
                low--;
                high++;
            }
        }
        return totalpalindrome;
    }
};