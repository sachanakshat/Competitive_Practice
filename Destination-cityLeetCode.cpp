class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        string last = paths[0][1];
        for(int i=0; i<paths.size(); i++)
        {
            if((last == paths[i][0]))
                last = paths[i][1];
        }
        return last;
    }
};

/*
Input: [["pYyNGfBYbm","wxAscRuzOl"],["kzwEQHfwce","pYyNGfBYbm"]]
Output: "pYyNGfBYbm"
Expected: "wxAscRuzOl"
*/

/*
Input: [["qMTSlfgZlC","ePvzZaqLXj"],["xKhZXfuBeC","TtnllZpKKg"],["ePvzZaqLXj","sxrvXFcqgG"],["sxrvXFcqgG","xKhZXfuBeC"],["TtnllZpKKg","OAxMijOZgW"]]
Output: "xKhZXfuBeC"
Expected: "OAxMijOZgW"
*/