class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();

        int x_max;
        int x_min;
        int y_max;
        int y_min;

        x_min = UPPER(image, 0, x, 0, n-1);
        x_max = LOWER(image, x, m-1, 0, n-1);
        y_max = RIGHT(image, 0, m-1, y, n-1);
        y_min = LEFT(image, 0, m-1, 0, y);
        return (x_max - x_min + 1) * (y_max - y_min + 1);
    }

    int UPPER(vector<vector<char>>& image, int rowMin, int rowMax, int colMin, int colMax) {
        int left = rowMin;
        int right = rowMax; 

        while (left < right) {
            int mid = left + (right - left) / 2;

            int flag = 0;
            for (int j = colMin; j <= colMax; j++) {
                if (image[mid][j] == '1') {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    int LOWER(vector<vector<char>>& image, int rowMin, int rowMax, int colMin, int colMax) {
        int left = rowMin;
        int right = rowMax; 

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            int flag = 0;
            for (int j = colMin; j <= colMax; j++) {
                if (image[mid][j] == '1') {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        return left;
    }
    int RIGHT(vector<vector<char>>& image, int rowMin, int rowMax, int colMin, int colMax) {
        int left = colMin;
        int right = colMax; 

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            int flag = 0;
            for (int i = rowMin; i <= rowMax; i++) {
                if (image[i][mid] == '1') {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        return left;
    }
    int LEFT(vector<vector<char>>& image, int rowMin, int rowMax, int colMin, int colMax) {
        int left = colMin;
        int right = colMax; 

        while (left < right) {
            int mid = left + (right - left) / 2;

            int flag = 0;
            for (int i = rowMin; i <= rowMax; i++) {
                if (image[i][mid] == '1') {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
