class SmallestInfiniteSet {
public:
    set<int> st;
    
    SmallestInfiniteSet() {
        for (int i = 0; i < 1000; i++) {
            st.insert(i + 1);
        }
    }
    
    int popSmallest() {
        int val = *(st.begin());
        st.erase(st.begin());
        return val;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */