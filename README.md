C++ Comparator Cheatsheet (LeetCode) 🚀
The Golden Rule: Your comparator should return true if element a should be ordered before element b.

std::sort (Use a Lambda [](){})
The most common and concise method for sorting problems.

Syntax Template:

C++

sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
    return /* comparison logic */;
});
Ascending Order: return a < b;

Descending Order: return a > b;

Complex Sort (e.g., sort pairs by 2nd element, ascending): return a.second < b.second;

std::priority_queue (Use a struct)
The standard, most reliable method for priority queues.

Syntax Template:

C++

struct Compare {
    bool operator()(const auto& a, const auto& b) const {
        return /* comparison logic */;
    }
};
priority_queue<Type, vector<Type>, Compare> pq;
Min-Heap (Smallest on top; for "Top K" problems): return a > b;

Max-Heap (Largest on top; default logic): return a < b;

Complex Heap (e.g., min-heap of pairs by 1st element): return a.first > b.first;
