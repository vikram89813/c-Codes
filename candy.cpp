int Solution::candy(vector<int> &ratings) {

    vector<int> val(ratings.size(), 1);
    int i = 0;
    while(i < ratings.size()){
        if(i == 0){
            if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
        }
        else if(i == ratings.size()-1){
            if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        else{
            if(ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1]){
                val[i] = max(val[i+1], val[i-1]) + 1;
            }
            else if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
            else if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        i++;
    }

    i = ratings.size()-1;

    while(i >= 0){
        if(i == 0){
            if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
        }
        else if(i == ratings.size()-1){
            if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        else{
            if(ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1]){
                val[i] = max(val[i+1], val[i-1]) + 1;
            }
            else if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
            else if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        i--;
    }
    int sol = 0;
    for(int i = 0; i < val.size(); i++){
        sol = sol + val[i];
    }
    return sol;
}
