class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> availableMovie;//movie->{price,shop}
    unordered_map<int,set<pair<int,int>>> movieShopPrice;//movie->{shop,price}
    set<tuple<int,int,int>> rentedMovie;//{price,shop,movie}
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e:entries){
            int shop=e[0],movie=e[1],price=e[2];
            availableMovie[movie].insert({price,shop});
            movieShopPrice[movie].insert({shop,price});
        }
    }
    
    vector<int> search(int movie) {
        if(availableMovie[movie].size()==0){
            return {};
        }
        vector<int> cheapestAvailableMovies;
        int cnt=0;
        for(auto &[price,shop]:availableMovie[movie]){
            cheapestAvailableMovies.push_back(shop);
            cnt+=1;
            if(cnt==5){
                break;
            }
        }
        return cheapestAvailableMovies;
    }
    
    void rent(int shop, int movie) {
        auto it=movieShopPrice[movie].lower_bound({shop,INT_MIN});
        int price=it->second;
        //remove this movie from availableMovie shop 
        availableMovie[movie].erase({price,shop});
        //added to rent
        rentedMovie.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        auto it=movieShopPrice[movie].lower_bound({shop,INT_MIN});
        int price=it->second;
        //add this movie to availableMovie shop 
        availableMovie[movie].insert({price,shop});
        //remove from rent
        rentedMovie.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        if(rentedMovie.size()==0){
            return {};
        }
        int cnt=0;
        vector<vector<int>> cheapestRentedMovie;
        for(auto &[price,shop,movie]:rentedMovie){
            cheapestRentedMovie.push_back({shop,movie});
            cnt++;
            if(cnt==5){
                break;
            }
        }
        return cheapestRentedMovie;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */