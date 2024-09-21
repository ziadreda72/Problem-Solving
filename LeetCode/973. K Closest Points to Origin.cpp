class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
            To find k closest points, we can use minHeap(Priority Queue).
            Instead storing distance as double because of square roots, we can store integers
            but why? because if square root of point[x1, y1] less than square root of point[x2, y2]
            it by squaring both sides, point[x1, y1] will remain less.
        */

        // Store distances as pairs, second element will be the original index to return the point.
        // Using max heap with negative values will put closest points at the top
        priority_queue < pair < int, int > > min_heap;
        for (int i = 0; i < (int) points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            
            // distance = x^2 + y^2, because the other point is the origin[0, 0]
            min_heap.emplace(-(x * x + y * y), i);
        }

        vector < vector < int > > ans;

        // extract top k element(closest to origin)
        while (k--) {
            // closest is the index of the current closest point
            auto closest = min_heap.top().second;
            ans.push_back(points[closest]);
            min_heap.pop();
        }

        return ans;
    }
};
