class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>> cuisineRatingFood;
    unordered_map<string,int> foodRating;
    unordered_map<string,string> foodCuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            cuisineRatingFood[cuisines[i]].insert({-ratings[i],foods[i]});
            foodRating[foods[i]]=ratings[i];
            foodCuisine[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating=foodRating[food];
        string cuisine=foodCuisine[food];
        cuisineRatingFood[cuisine].erase({-oldRating,food});
        foodRating[food]=newRating;
        cuisineRatingFood[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return begin(cuisineRatingFood[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */