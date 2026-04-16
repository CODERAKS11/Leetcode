class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        string res = "";
        while(!pq.empty()){
            res.append(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;
    }
};