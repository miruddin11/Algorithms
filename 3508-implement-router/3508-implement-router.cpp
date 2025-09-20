class Router {
public:
    queue<vector<int>> router;
    unordered_set<string> seen;
    unordered_map<int, deque<int>> destinationTime;
    int limit;
    Router(int memoryLimit) { limit = memoryLimit; }
    string getKey(int source, int destination, int timestamp) {
        string key = to_string(source) + "-" + to_string(destination) + "-" +
                     to_string(timestamp);
        return key;
    }
    void removePacket() {
        vector<int> packet = router.front();
        int source = packet[0], destination = packet[1], timestamp = packet[2];
        string oldKey = getKey(source, destination, timestamp);
        auto &dq= destinationTime[destination];
        if(!dq.empty()) dq.pop_front();
        seen.erase(oldKey);
        router.pop();
    }
    bool addPacket(int source, int destination, int timestamp) {
        string key = getKey(source, destination, timestamp);
        if (seen.count(key) > 0) {
            return false;
        }
        if (router.size() >= limit) {
            removePacket();
        }
        seen.insert(key);
        router.push({source, destination, timestamp});
        destinationTime[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (router.size() == 0) {
            return {};
        }
        vector<int> packet = router.front();
        removePacket();
        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &vec = destinationTime[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime); 
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2-it1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */