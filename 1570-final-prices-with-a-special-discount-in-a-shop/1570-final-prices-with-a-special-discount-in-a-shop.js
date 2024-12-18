var finalPrices = function(prices) {
    let n = prices.length;
    let ans = [...prices];
    let stack = [];

    for (let i = 0; i < n; i++) {
        while (stack.length > 0 && prices[stack[stack.length - 1]] >= prices[i]) {
            ans[stack.pop()] -= prices[i];
        }
        stack.push(i);
    }

    return ans;
};
