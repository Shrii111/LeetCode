class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int n = s.size();
        int power = 0;
        long long val = 0;
        for(int i=n-1; i>=0;i--){
            if(s[i]=='0'){
                count++;
            }else{
                if (power < 31 && (val + (1LL << power)) <= k) {
                    val += (1LL << power);
                    count++;
            }
        }
        power++;
    }
    return count;
    }
};