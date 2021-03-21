投票算法证明：
如果候选人不是maj 则 maj,会和其他非候选人一起反对 会反对候选人,所以候选人一定会下台(maj==0时发生换届选举)
如果候选人是maj , 则maj 会支持自己，其他候选人会反对，同样因为maj 票数超过一半，所以maj 一定会成功当选
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (auto item : nums) {
            if (candidate == item) {
                ++count;
            } else if ((--count) < 0) {
                candidate = item;
                count++;
            }
        }
        return candidate;
    }
};
