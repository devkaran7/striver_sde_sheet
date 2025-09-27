class Solution {
private:
    struct Box {
        int value;
        int frequency;
        Box(int value, int frequency) : value(value), frequency(frequency) {}
    };
    struct Compare {
        bool operator()(const auto &a, const auto &b) const {
            return a.frequency > b.frequency;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (const auto &num : nums) {
            frequencyMap[num]++;
        }
        priority_queue<Box, vector<Box>, Compare> pq;
        for (const auto &kv : frequencyMap) {
            pq.push(Box(kv.first, kv.second));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> answer;
        while(pq.empty() == false) {
            answer.push_back(pq.top().value);
            pq.pop();
        }
        return answer;
    }
};
