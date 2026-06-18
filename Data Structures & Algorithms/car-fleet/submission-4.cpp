class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>>car_fleet;
        for (int index = 0; index < speed.size(); index++){
            car_fleet.push_back({position[index], speed[index]});
        }
        sort(car_fleet.begin(), car_fleet.end());
        vector<double>ans;
        for (int index = position.size() - 1; index >= 0; index--){
            double time = (double)(target - car_fleet[index][0])/car_fleet[index][1];
            
            if (ans.size() == 0 || ans.back() < time){
                ans.push_back(time);
            }
            cout<<time<<" "<<ans.back()<<endl;
        }
        return ans.size();
    }
};
// 0 1 4 7
///1 2 2 1
// 10, 4.5 3 3
// 1 1 12 7 3