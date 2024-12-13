# @param {Integer[]} nums
# @return {Integer}
def find_score(nums)
    n = nums.size
    score = 0

    val_ind = nums.each_with_index.map { |val, ind| [val, ind] }
    val_ind.sort!

    marked = Array.new(n, false)

    val_ind.each do |val, ind|
        next if marked[ind]

        score += val

        marked[ind - 1] = true if ind > 0
        marked[ind] = true
        marked[ind + 1] = true if ind < n - 1
    end

    score
end
