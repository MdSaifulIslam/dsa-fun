/*
11. Container With Most Water

Approach: Two pointer

- Start with widest container [left = 0, right = n - 1]
- Move pointer with smaller hight inword
- Track maxium area

Time O(n), Space O(1)

Algorithm:
1. Initialize: left = 0, end = n-1, maxArea = 0
2. While left < right
    a. Calculate area = min(hight[left], hight[right]) * (right - left)
    b. Update maxArea = min(maxArea, area)
    c. Move pointer
        - if hight[left] < hight[right] left ++
        - else right --
3. Return maxArea
*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxAreaFun(vector<int> &height)
    {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);

            maxArea = max(area, maxArea);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

int main()
{
    vector<int> hight = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    cout << solution.maxAreaFun(hight) << endl;
    return 0;
}