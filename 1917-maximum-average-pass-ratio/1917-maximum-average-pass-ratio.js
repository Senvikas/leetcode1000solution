var maxAverageRatio = function(cls, extra) {
    const maxHeap = new MaxPriorityQueue({
        priority: ([gain]) => gain
    });

    for (let [pass, total] of cls) {
        let gain = (pass + 1) / (total + 1) - pass / total;
        maxHeap.enqueue([gain, pass, total]);
    }

    while (extra-- > 0) {
        let [_, pass, total] = maxHeap.dequeue().element;

        pass++;
        total++;

        let newGain = (pass + 1) / (total + 1) - pass / total;
        maxHeap.enqueue([newGain, pass, total]);
    }

    let totalSum = 0.0;
    while (!maxHeap.isEmpty()) {
        let [_, pass, total] = maxHeap.dequeue().element;
        totalSum += pass / total;
    }

    return totalSum / cls.length;
};
