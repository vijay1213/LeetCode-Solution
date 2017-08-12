class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return -1;
        }
        
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] <= nums[end])
            {
                if (nums[mid] < target && nums[end] >= target)
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else
            {
                if (nums[start] <= target && nums[mid] > target)
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
        }
        
        if (nums[start] == target)
        {
            return start;
        }
        else if (nums[end] == target)
        {
            return end;
        }
        else
        {
            return -1;
        }
    }
};
