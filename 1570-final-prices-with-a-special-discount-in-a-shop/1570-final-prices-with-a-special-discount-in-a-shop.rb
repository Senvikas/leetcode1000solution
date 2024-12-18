def final_prices(prices)
    n = prices.size
    ans = prices.clone
    stack = []

    (0...n).each do |i|
        while !stack.empty? && prices[stack.last] >= prices[i]
            ans[stack.pop] -= prices[i]
        end
        stack.push(i)
    end

    ans
end
