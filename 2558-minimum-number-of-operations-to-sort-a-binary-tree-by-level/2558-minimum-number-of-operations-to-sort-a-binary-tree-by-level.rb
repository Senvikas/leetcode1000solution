    def min_steps(level)
        n = level.size
        ele_ind = level.each_with_index.map { |val, i| [val, i] }
        ele_ind.sort_by! { |x| x[0] }

        vis = Array.new(n, false)
        ans = 0

        (0...n).each do |i|
            next if vis[i] || ele_ind[i][1] == i

            cycle = 0
            j = i

            while !vis[j]
                vis[j] = true
                j = ele_ind[j][1]
                cycle += 1
            end

            ans += cycle - 1
        end

        ans
    end

    def minimum_operations(root)
        return 0 if root.nil?

        ans = 0
        q = [root]

        until q.empty?
            level = []
            next_level = []

            q.each do |node|
                level << node.val
                next_level << node.left if node.left
                next_level << node.right if node.right
            end

            q = next_level
            ans += min_steps(level)
        end

        ans
    end
