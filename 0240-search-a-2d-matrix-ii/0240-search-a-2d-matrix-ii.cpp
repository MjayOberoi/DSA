class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = row - 1; i >= 0; i--)
        {
            if (matrix[i][0] <= target && target <= matrix[i][col - 1])
            {
                int r = col - 1, l = 0, mid;
                while (l <= r)
                {
                    mid = (l + r) / 2;
                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] < target)
                    {
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                    ;
                }
            }
            else if (target > matrix[i][col - 1])
            {
                break;
            }
        }
        return false;
    }
};