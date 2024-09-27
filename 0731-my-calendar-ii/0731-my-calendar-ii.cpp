class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleBooking;
    vector<pair<int,int>> booking;
    MyCalendarTwo() {
        
    }
    bool isOverlap(int s1,int e1,int s2,int e2)
    {
        return max(s1,s2)<min(e1,e2);
    }
    pair<int,int> overlapRegion(int s1,int e1,int s2,int e2)
    {
        return {max(s1,s2),min(e1,e2)};
    }
    bool book(int start, int end) {
        for(auto &d:doubleBooking)
        {
            if(isOverlap(d.first,d.second,start,end)){
                return false;
            }
        }
        for(auto &b:booking)
        {
            if(isOverlap(b.first,b.second,start,end)){
                doubleBooking.push_back(overlapRegion(b.first,b.second,start,end));
            }
        }
        booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */