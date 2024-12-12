# @param {Integer[]} gifts
# @param {Integer} k
# @return {Integer}
def pick_gifts(gifts, k)
    pq = gifts.sort.reverse
    
    while k > 0
        max_gifts = pq.shift
        if max_gifts == 1
            pq.push(1) # Add 1 back to the heap
            break
        end
        
        leave = Math.sqrt(max_gifts).floor
        pq.push(leave)
        pq.sort!.reverse!
        k -= 1
    end
    
    pq.sum
end
