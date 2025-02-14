class ProductOfNumbers {
    vector<int> prefProd;
    int total;
    int zeroIdx;
public:
    ProductOfNumbers() {
        zeroIdx=-1;
        total=1;
    }
    
    void add(int num) {
        prefProd.push_back(total*num);
        if(total*num==0){
            total=1;
        }else{
            total=total*num;
        }
        if(num==0){
            zeroIdx=prefProd.size()-1;
        }
    }
    
    int getProduct(int k) {
        int n=prefProd.size();
        if(zeroIdx>=n-k && zeroIdx<n){
                return 0;
        }
        else if(n-k==0){
            return total;
        }else{
            if(prefProd[n-k-1]==0) return total;
           return prefProd[n-1]/prefProd[n-k-1];
        }
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */