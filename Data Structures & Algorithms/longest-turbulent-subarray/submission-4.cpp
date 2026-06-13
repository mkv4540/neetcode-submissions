class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr1 = 0, curr2 = 0, ans = 1;
        for (int index = 0; index < arr.size()-1; index++){
            if ((index % 2) && arr[index] < arr[index+1]){
                if (curr2 == 0){
                    curr2=2;
                }else{
                    curr2++;
                }
            }else if ((index % 2 == 0) && arr[index] > arr[index+1]){
                if (curr2 == 0){
                    curr2=2;
                }else{
                    curr2++;
                }
            }else{
                curr2 =0;
            }

            if ((index % 2) && arr[index] > arr[index+1]){
                if (curr1 == 0){
                    curr1=2;
                }else{
                    curr1++;
                }
            }else if ((index % 2 == 0) && (arr[index] < arr[index+1])){
                if (curr1 == 0){
                    curr1=2;
                }else{
                    curr1++;
                }
            }else{
                curr1 = 0;
            }
            ans = max(ans, curr1);
            ans = max(ans, curr2);
        }
        return ans;
    }
};
// 2 < 4 > 3 