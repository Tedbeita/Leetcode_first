//本题主要运用set来构建hash表，由于需要输出交集，对排序没有要求，但要求不重复，故采用unordered_set来进行hash的构建
//主要思路是对于s1构建一个hash，然后查找s1里有无s2的元素，有就保存下来，最后转换成vector的数组。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums(nums1.begin(),nums1.end());
        for(int i = 0;i < nums2.size();i++)
        {
            if(nums.find(nums2[i]) != nums.end())
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(),result.end());

    }   
};
