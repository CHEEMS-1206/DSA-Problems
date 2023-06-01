class Solution {
public:
    void fillColor(int color,int val, vector<int>& nums){
        while(color != 0){
            nums.push_back(val);
            color--;
        }
    }
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                red++;
            }else if(nums[i] == 1){
                white++;
            }else{
                blue++;
            }
        }
        nums.clear();
        fillColor(red,0,nums);
        fillColor(white,1,nums);
        fillColor(blue,2,nums);
    }
};