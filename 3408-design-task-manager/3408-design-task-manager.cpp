class TaskManager {
public:
    unordered_map<int, int> taskPriorityMap;
    priority_queue<pair<int, int>> priorityTaskIdMaxHeap;
    unordered_map<int, int> taskUserIdMap;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskPriorityMap[taskId] = priority;
        priorityTaskIdMaxHeap.push({priority, taskId});
        taskUserIdMap[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        taskPriorityMap[taskId] = newPriority;
        priorityTaskIdMaxHeap.push({newPriority, taskId});
    }

    void rmv(int taskId) { taskPriorityMap[taskId] = -1; }

    int execTop() {
        while (!priorityTaskIdMaxHeap.empty()) {
            int priority = priorityTaskIdMaxHeap.top().first;
            int taskId = priorityTaskIdMaxHeap.top().second;
            priorityTaskIdMaxHeap.pop();
            if (priority == taskPriorityMap[taskId]) {
                rmv(taskId);
                return taskUserIdMap[taskId];
            }
        }
        return -1;
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