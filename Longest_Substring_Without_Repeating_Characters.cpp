class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastPos;
        int left = 0;
        int ans = 0;
        for(int right=0; right<s.size(); right++){
            char c = s[right];
            if(lastPos.count(c)){
                left=max(left,lastPos[c]+1);
                

            }lastPos[c]=right;
                ans=max(ans,right-left+1);
            
        }
        return ans;
    }
};