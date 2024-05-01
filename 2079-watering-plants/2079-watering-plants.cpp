class Solution {
public:
  
        
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int currCapacity = 0;

        for (int i = 0; i < plants.size(); ++i) {
            if (currCapacity + plants[i] <= capacity) {
                currCapacity += plants[i];
            } else {
                currCapacity = plants[i]; // Reset
                ans += i * 2;
            }
        }

        return ans + plants.size();
    }
    
};