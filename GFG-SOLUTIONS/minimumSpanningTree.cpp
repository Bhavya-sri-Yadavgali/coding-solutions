class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
        vector<int> visited(V,0) ;
        int sum = 0 ;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [weight ,node] = pq.top();
            pq.pop();
            if(visited[node]){
                continue ;
            }
            visited[node] = 1 ;
            sum += weight ;
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1] ;
                int weight = edge[2] ;
                if(u == node || v == node){
                    int adj = u==node ? v:u ;
                    pq.push({weight,adj}) ;
                }
            }
            
            
        }
        return sum ;
        
        
    }
};