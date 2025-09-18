#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto mir = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class TaskManager {
public:
    set<pair<int, int>> priorityTask;
    unordered_map<int, int> taskPriority;
    unordered_map<int, unordered_set<int>> userTask;
    unordered_map<int, int> taskUser;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        priorityTask.insert({priority, taskId});
        taskPriority[taskId] = priority;
        userTask[userId].insert(taskId);
        taskUser[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        int oldPriority = taskPriority[taskId];
        taskPriority[taskId] = newPriority;
        priorityTask.erase({oldPriority, taskId});
        priorityTask.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        int priority = taskPriority[taskId];
        priorityTask.erase({priority, taskId});
        int userId = taskUser[taskId];
        userTask[userId].erase(taskId);
        taskPriority.erase(taskId);
        taskUser.erase(taskId);
    }

    int execTop() {
        if (priorityTask.empty())
            return -1;
        int taskId = priorityTask.rbegin()->second;
        int userId = taskUser[taskId];
        rmv(taskId);
        return userId;
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