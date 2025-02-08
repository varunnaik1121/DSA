class NumberContainers {
    map<int,set<int>> mpp;
    unordered_map<int,int> prevEle;


public:
    NumberContainers() {
       
        
    }
    
    void change(int index, int number) {
       if(prevEle.find(index)==prevEle.end()){
        prevEle[index]=number;
        mpp[number].insert(index);
       }else{
        int num=prevEle[index];
        mpp[num].erase(index);
        mpp[number].insert(index);
        prevEle[index]=number;
       }
    }
    
    int find(int number) {
      if(mpp.find(number)!=mpp.end() && mpp[number].size()>0){
        return *mpp[number].begin();
      }
      return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */