class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> Set;
        vector<double> res;
        for (int i = 0; i < k; i++) {
            Set.insert(nums[i]);
        }

        auto iter = Set.begin();
        iter = next(iter, (k+1)/2 - 1);
        
        if (k % 2 == 1) {
            res.push_back(*iter);
        }
        else {
            res.push_back((((*iter) * 1.0)/2) + (((*next(iter,1)) * 1.0)/2));
        }

        for (int i = k; i < nums.size(); i++) {

            Set.insert(nums[i]);

            if (nums[i] < *iter) --iter;               // 規則 1

            // 刪除 y
            if (nums[i-k] <= *iter) ++iter;            // 規則 2（先調，再刪）
            
            // if (k % 2 == 1) { // OXO
            //     if (nums[i] < *iter) {
            //         iter = prev(iter, 1);
            //     }

            //     //OXOO 
            //     if (nums[i-k] < *iter) {
            //         iter = next(iter, 1);
            //     }
            //     else if (nums[i-k] > *iter) {
            //         // do nothing
            //     }
            //     else { // 
            //         iter = next(iter, 1);
            //     }
            // }
            // else { // OXOOO
            //        // OOXOO
            //     if (nums[i] > *iter) {
            //         iter = next(iter, 1);
            //     }
            //     else if (nums[i] == *iter) {
            //         iter = next(iter, 1);
            //     }

            //     // OOXOO, OXO, OOXOOO, OOOOXOOOO
            //     if (nums[i-k] > *iter) {
            //         iter = prev(iter, 1);
            //     }
            //     else if (nums[i-k] < *iter) {
            //         // do nothing
            //     }
            //     else {
            //         if (iter != Set.begin() && (*iter == *prev(iter,1))) {

            //         }
            //         else {
            //             iter = prev(iter,1);
            //         }
            //     }
            // }

            Set.erase(Set.lower_bound(nums[i-k]));

            if (k % 2 == 1) {
                res.push_back(*iter);
            }
            else {
                res.push_back((((*iter) * 1.0)/2) + (((*next(iter,1)) * 1.0)/2));
            }
        }
        return res;
    }
};
