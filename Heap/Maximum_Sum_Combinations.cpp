class Solution {
  private:
    struct Box {
        int sum;
        int aIndex;
        int bIndex;
        Box(int sum, int a, int b) {
            this->sum = sum;
            this->aIndex = a;
            this->bIndex = b;
        }
    };
    struct Compare {
        bool operator()(const auto &a, const auto &b) const {
            return a.sum < b.sum;
        }
    };
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<Box, vector<Box>, Compare> pq;
        pq.push(Box(a.back() + b.back(), a.size() - 1, b.size() - 1));
        set<pair<int, int>> visited;
        visited.insert(make_pair(a.size() - 1, b.size() - 1));
        vector<int> answer;
        while(k--) {
            int sum = pq.top().sum;
            int aIndex = pq.top().aIndex;
            int bIndex = pq.top().bIndex;
            pq.pop();
            answer.push_back(sum);
            if (aIndex != 0 && visited.find(make_pair(aIndex-1, bIndex)) == visited.end()) {
                pq.push(Box(sum - a[aIndex] + a[aIndex-1], aIndex-1, bIndex));
                visited.insert(make_pair(aIndex-1, bIndex));
            }
            if (bIndex != 0 && visited.find(make_pair(aIndex, bIndex-1)) == visited.end()) {
                pq.push(Box(sum - b[bIndex] + b[bIndex-1], aIndex, bIndex-1));
                visited.insert(make_pair(aIndex, bIndex-1));
            }
        }
        return answer;
    }
};
