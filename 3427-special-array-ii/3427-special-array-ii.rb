def is_array_special(nums, queries)
  n = nums.length
  index = []
  prev = nums[0].odd?

  # Find indices where parity is the same
  (1...n).each do |i|
    curr = nums[i].odd?
    index << (i - 1) if prev == curr
    prev = curr
  end

  # Process queries
  result = []
  queries.each do |from, to|
    left, right, found = 0, index.size - 1, -1

    # Binary search to find the first index >= 'from'
    while left <= right
      mid = (left + right) / 2
      if index[mid] >= from
        found = mid
        right = mid - 1
      else
        left = mid + 1
      end
    end

    # Check if the subarray is special
    result << (found == -1 || to <= index[found])
  end

  result
end
