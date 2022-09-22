priority_queue<pair<int, int>> pq;
    for(int i = 0; i < k; i++){
        pq.push({-kArrays[i][0], i});
    }
    vector<int> points(k, 1);
    vector<int> arr;
    while(pq.empty() == false){
        int a = -pq.top().first;
        int b = pq.top().second;
        pq.pop();
        arr.push_back(a);
        if(points[b] < kArrays[b].size()){
            pq.push({-kArrays[b][points[b]++], b});
        }
    }
    return arr;
