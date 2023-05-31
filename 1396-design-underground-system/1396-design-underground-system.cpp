class UndergroundSystem {
public:
map<int,pair<string,int>> mp;
map<pair<string,string>,pair<double,int>> mp1;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [a,b]=mp[id];
        auto itr=mp1.find({a,stationName});
        double sum=t-b;
        int n=1;
        if(itr!=mp1.end()){
            sum+=itr->second.first;
            n+=itr->second.second;
        }
        mp1[{a,stationName}]={sum,n};
        mp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto itr=mp1.find({startStation,endStation});
        return (itr->second.first)/(itr->second.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */