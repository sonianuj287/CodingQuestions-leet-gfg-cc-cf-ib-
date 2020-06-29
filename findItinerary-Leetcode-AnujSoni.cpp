some test case remain

class Solution {
public:
    string searcher(vector<vector<string>>& tickets,string search,vector<string>& res){
        for(int i=0;i<tickets.size();i++){
            if(tickets[i][0] == search){
                res.push_back(tickets[i][1]);
                // search = tickets[i][1];
                tickets[i][0] = "0";
                return tickets[i][1];
            }
        }
        string e = "";
        return e;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        vector<string> res;
        res.push_back("JFK");
        string search = "JFK";
        while(search != ""){
            search = searcher(tickets,search,res);
        }
        
        return res;
    }
};
