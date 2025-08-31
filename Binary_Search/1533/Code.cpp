/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int left = 0;
        int right = reader.length() - 1;
        int res;
        while (left < right) {
            int mid = left + (right - left) / 2;
                
            int value;
            
            if ((right - left + 1) % 2 == 0) {
                value = reader.compareSub(left, mid, mid + 1, right);
            }
            else {
                value = reader.compareSub(left, mid - 1, mid + 1, right);
            }
            
            if (value == 0) {
                res = mid;
                break;
            }
            else if (value == 1) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        if (left == right) res = left;
        
        return res;
    }

    
};
