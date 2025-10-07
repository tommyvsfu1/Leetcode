重點:
要用unordered_set 來儲存 followers，如果你想要一勞永逸用pq處理，是沒辦法很容易處理unfollow情況
所以要同時考慮getPost, follow, unfollow，來去思考怎麼設計資料結構
