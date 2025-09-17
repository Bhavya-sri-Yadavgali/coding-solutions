class FoodRatings {
public:
    struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first)
            return a.second > b.second; // smaller name should come first
        return a.first < b.first;       // bigger rating should come first
    }

    } ;
    vector<string> foods ;
    vector<string> cuisines ;
    vector<int> ratings ;
    unordered_map<string,pair<string,int>> foodmap ;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>, cmp>> cuisinesmap  ;

FoodRatings(vector<string>& foodss, vector<string>& cuisiness, vector<int>& ratingss) {
         foods = foodss ;
         cuisines = cuisiness ;
         ratings = ratingss ;

       for(int i = 0 ; i < foods.size();i++){
             pair<string,int> str = {cuisines[i],ratings[i]} ;
             foodmap.insert({foods[i],str}) ;
             cuisinesmap[cuisines[i]].push({ratings[i],foods[i]}) ;

       }

    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine,oldrating] = foodmap[food]  ;
        foodmap[food] = {cuisine,newRating} ;
        cuisinesmap[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        
        auto& heap = cuisinesmap[cuisine] ;
        while(true){
        auto [rating,food] = heap.top() ;
            if(rating == foodmap[food].second){
                return food ;
            }
            heap.pop() ;
        }
        }


};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */