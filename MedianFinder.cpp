/*thoughts:
The idea is to use two heaps (one max heap, one mn heap) to save the input data. 
max_heapis a max_heap to save the first half of the data with smaller values, 
and min_heap is a min_heap to save the second half of the data with bigger values. 
Everytime when inserting a new value, we first compare if it is smaller than the top of firstQ (the largest value of the first half), 
if so, insert into firstQ. Otherwise, it belongs to the second half. 
After inserting, we have to balance the first half and the second half to make sure 
either they have the same length or the length difference is only 1.
The median will be the mean of two top elements (when they have the same length) or the top element of the queue with a larger length.
*/

class MedianFinder {
private:
    priority_queue<int> max_heap; //smaller half of the stream
    priority_queue<int, vector<int>, greater<int> > min_heap; //larger half of the stream
public:
    /** initialize your data structure here. */
    MedianFinder() {
        //do nothing
    }
    
    void addNum(int num) {
        if(max_heap.empty() || max_heap.top() > num)
            max_heap.push(num);
        else
            min_heap.push(num);     //insert the element to appropritate heap first
            
        if(max_heap.size() > (min_heap.size() + 1)){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size() + 1 < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        return;
        
    }
    
    double findMedian() {
        if(max_heap.empty() && min_heap.empty() )
            return 0.0;
        
        if(max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top())/2.0;
        else
            return max_heap.size() > min_heap.size()?max_heap.top():min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */