/**
 * @param {number[]} gifts
 * @param {number} k
 * @return {number}
 */
var pickGifts = function(gifts, k) {
    const maxHeap = new MaxHeap(gifts);
    
    while (k > 0) {
        let maxGifts = maxHeap.pop();
        if (maxGifts === 1) 
        {
            maxHeap.push(1);
            break;
        }        
        let leave = Math.floor(Math.sqrt(maxGifts));
        maxHeap.push(leave);
        k--;
    }
    
    return maxHeap.sum();
};

class MaxHeap {
    constructor(arr) {
        this.heap = [...arr];
        this.heap.sort((a, b) => b - a);
    }
    
    pop() {
        return this.heap.shift();
    }
    
    push(val) {
        this.heap.push(val);
        this.heap.sort((a, b) => b - a);
    }
    
    sum() {
        return this.heap.reduce((a, b) => a + b, 0);
    }
}
