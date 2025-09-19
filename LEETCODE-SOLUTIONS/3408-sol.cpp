class TaskManager {
public:
    vector<vector<int>> tasks ;
    unordered_map<int,pair<int,int>> map ;
    priority_queue<pair<int,int>> pq ;
    TaskManager(vector<vector<int>>& taskss) {
        tasks = taskss ;

        for(auto v : tasks){
            map[v[1]] = {v[0],v[2]} ;
            pq.push({v[2],v[1]}) ;
        }

    }
    
    void add(int userId, int taskId, int priority) {
        map[taskId] = {userId,priority} ;
        pq.push({priority,taskId}) ;
    }
    
    void edit(int taskId, int newPriority) {
        auto& [user,priority] = map[taskId] ;
        map[taskId] = {user,newPriority} ;
        pq.push({newPriority,taskId}) ;

    }
    
    void rmv(int taskId) {
        map.erase(taskId) ;
    }
    
    int execTop() {
        
        while(!pq.empty()){

        auto& [priority,task] = pq.top() ;

        if(map.find(task) == map.end() || map[task].second != priority){

            pq.pop() ;

        }else{
            int user =  map[task].first ;
            
            map.erase(task) ;
            pq.pop() ; 

            return user ;
        }
    }

    return -1 ;
}
    

   
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */