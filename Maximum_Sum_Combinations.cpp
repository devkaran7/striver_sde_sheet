vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    pq.push({A[n-1] + B[n-1], {n-1, n-1}});
    set<pair<int, int>> st;
    st.insert({n-1, n-1});
    vector<int> vec;
    while(vec.size() != C){
        int sum = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
            vec.push_back(sum);
            if(a != 0 && st.find({a-1, b}) == st.end()){
                pq.push({A[a-1] + B[b], {a-1, b}});
                st.insert({a-1, b});
            }
            if(b != 0 && st.find({a, b-1}) == st.end()){
                pq.push({A[a] + B[b-1], {a, b-1}});
                st.insert({a, b-1});
            }
    }
    return vec;
}
