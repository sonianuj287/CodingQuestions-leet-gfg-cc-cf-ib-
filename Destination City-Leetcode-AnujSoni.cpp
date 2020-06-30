class Solution {
public:
    string searcher(vector<vector<string>> paths, string search){
        for(int i=0;i<paths.size();i++){
            if(search == paths[i][0])
                return paths[i][1];
        }
        return "";
    }
    
    string destCity(vector<vector<string>>& paths) {
        string temp = paths[0][0];
        string search = paths[0][1];
        while(search!=""){
            temp = search;
            search = searcher(paths,search);
        }
        return temp;
    }
};
