#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int end;
};

bool compareActivity(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

int maxActivities(std::vector<Activity>& activities) {
    if (activities.empty()) return 0;

    std::sort(activities.begin(), activities.end(), compareActivity);

    int count = 0;
    int last_end_time = -1;

    for (const auto& act : activities) {
        if (act.start >= last_end_time) {
            count++;
            last_end_time = act.end;
        }
    }

    return count;
}

int main() {
    std::vector<Activity> activities = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}};
    std::cout << maxActivities(activities) << std::endl;
    return 0;
}
