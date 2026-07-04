class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it :nums){
            pq.push(it);
        }
        int max=0;
        for(int i=0;i<k;i++){
            max=pq.top();
            pq.pop();
        }
        return max;
    }
};