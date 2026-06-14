class Solution {
public:
    bool isBalanced(unordered_map<int, int> &freq,unordered_map<int, int> &freqCount){
        if(freq.size() == 1) return true;
        if(freqCount.size() != 2) return false;

        vector<int> frequencies;
        for(auto &p : freqCount){
            frequencies.push_back(p.first);
        }

        int a = min(frequencies[0], frequencies[1]);
        int b = max(frequencies[0], frequencies[1]);

        return b == 2 * a;
    }
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> freq;
            unordered_map<int, int> freqCount;
            for(int j = i; j < n; j++){
                int num = nums[j];
                int oldFreq = freq[num];

                if(oldFreq > 0){
                    freqCount[oldFreq]--;
                    if(freqCount[oldFreq] == 0){
                        freqCount.erase(oldFreq);
                    }
                }

                freq[num]++;
                int  newFreq = freq[num];
                freqCount[newFreq]++;
                if(isBalanced(freq, freqCount)){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};