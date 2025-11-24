1.記得flatten要把child = NULL
2.flatten完，移動curr只能走child產生的，如果提前走到原本的curr->next，可能會誤判斷亂接node
