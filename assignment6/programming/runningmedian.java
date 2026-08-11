import java.util.Collections;
import java.util.PriorityQueue;

class runningmedian {
    // MedianFinder median = new MedianFinder();
    PriorityQueue<Integer> minheap = new PriorityQueue<>();
    PriorityQueue<Integer> maxheap = new PriorityQueue<>(Collections.reverseOrder());  
    
    public void addNum(int num) {
        if(maxheap.isEmpty() || num < maxheap.peek()){
            maxheap.add(num);
        } 
        else{
            minheap.add(num);
        }

        if(maxheap.size() - minheap.size() >1) minheap.add(maxheap.poll());
        if(minheap.size() - maxheap.size() > 1) maxheap.add(minheap.poll());        
    }
    
    public double findMedian() { 
        if((maxheap.size() + minheap.size())%2==0){
            return ((double)maxheap.peek() + minheap.peek())/2;
        } 
        if(maxheap.size() > minheap.size()){
            return maxheap.peek();
        }
        return minheap.peek();
    }
}
