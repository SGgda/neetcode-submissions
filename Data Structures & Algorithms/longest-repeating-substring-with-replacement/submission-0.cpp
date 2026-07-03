class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int i=0;
        int j=0;
        int maxLength=0;    
        int maxFreq=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq,freq[s[j]-'A']);
            int windowLength=j-i+1;
            if(windowLength-maxFreq<=k){
                maxLength=max(maxLength,windowLength);
            }else{
                freq[s[i]-'A']--;
                i++;
            }
            j++;

        }
        return maxLength;
    }
};