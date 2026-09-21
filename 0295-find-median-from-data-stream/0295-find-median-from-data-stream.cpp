class MedianFinder {
public:
    MedianFinder() {
       
    }
    
    void addNum(int num) {
       maxheap.push(num);
       int tmp=maxheap.top();
       maxheap.pop();
       minheap.push(tmp);
       if(minheap.size()-maxheap.size()>1){
            int t=minheap.top();
            minheap.pop();
            maxheap.push(t);
       }
    }
    
    double findMedian() {
        if((maxheap.size()+minheap.size())%2==0){
            return (maxheap.top()+minheap.top())/2.0;
        }
        else return maxheap.size()>minheap.size()?maxheap.top():minheap.top();
    }
private:
   priority_queue<int>maxheap;
   priority_queue<int,vector<int>,greater<int>>minheap; 
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */