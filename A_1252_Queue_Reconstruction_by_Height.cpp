class Solution {
public:
    /**
     * @param people: a random list of people
     * @return: the queue that be reconstructed
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // write your code here
        sort(people.begin(),people.end(),[](vector<int> &a,vector<int>&b){
            return a[0]>b[0] || (a[0]==b[0] && a[1] < b[1]);
        });
        for(int i =0;i<people.size();i++){
            auto f = people[i];
            if(f[1] != i){
                people.erase(people.begin()+i);
                people.insert(people.begin()+f[1],f);
            }
        }
        return people;
    }
};
