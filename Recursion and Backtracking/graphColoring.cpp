class Solution{
private:
    bool is_safe(int node, int n, int color[], bool graph[101][101]){
        for(int i = 0; i < n; i++){
            if(node != i && graph[node][i] && color[i] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool recursion(int node, int n, int m, bool graph[101][101], int color[]){
        if(node == n){
            return true;
        }
        for(int i = 1; i <= m; i++){
            color[node] = i;
            if(is_safe(node, n, color, graph)){
                if(recursion(node+1, n, m, graph, color)){
                    return true;
                }
            }
            color[node] = 0;
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        return recursion(0, n, m, graph, color);
    }
};
