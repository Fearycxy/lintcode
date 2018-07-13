class Solution {
public:
    /**
     * @param price: List[int]
     * @param special: List[List[int]]
     * @param needs: List[int]
     * @return: return an integer
     */
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        // write your code here
        int n = price.size();
        int res = inner_product(price.begin(),price.end(),needs.begin(),0);
        for(auto sp:special){
            bool valid = true;
            for(int y = 0; y <n;y++){
                if(needs[y] < sp[y]) valid = false;
                needs[y] -= sp[y];
            }
            if(valid) res = min(res,sp.back() + shoppingOffers(price,special,needs));
            for(int y=0;y<n;y++) needs[y] += sp[y];
        }
        return res;
    }
};
