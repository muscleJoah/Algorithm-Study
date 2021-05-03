
//이웃 원소가 크면 작은놈보단 많이받아야함.
//근데 같은놈보다는 적게 받아도 상관이 없음.

class Solution {
public:
    int candy(vector<int>& ratings) {
    
    vector<int> candy(ratings.size());
    for (int i = 1; i < ratings.size(); i++)
      if (ratings[i] > ratings[i - 1]) 
          candy[i] = candy[i - 1] + 1;
    for (int i = ratings.size() - 2; i >= 0; i--)
      if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i+1]) 
          candy[i] = candy[i+1]+1;
   
    int sum = 0;
    for(auto e: candy)
        sum +=e+1;
      return sum;
    }
};