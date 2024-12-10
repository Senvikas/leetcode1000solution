# @param {String} s
# @return {Integer}
def find_twice(s, special, ind)
    cnt = 2
    n = s.length
    len = special.length
    (ind..n - len).each do |j|
        sub = s[j, len]
        if sub == special
            cnt -= 1
            return true if cnt == 0
        end
    end
    false
end

def maximum_length(s)
    n = s.length
    ans = -1

    (0...n).each do |i|
        special = ""
        (i...n).each do |j|
            if !special.empty? && special[-1] != s[j]
                break
            end
            special += s[j]
            if find_twice(s, special, i + 1)
                ans = [ans, special.length].max
            end
        end
    end

    ans
end

