class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        four = [0] * 4
        for i in range(0,4):
            four[i] = nums[i]
        four = sorted(four)
        mi1, mi2, ma2, ma1 = four[0], four[1], four[2], four[3]
        
        for i in range(4, len(nums)):
            ele = nums[i]
            if(ele >= ma2 or ele >= ma1):
                if(ele > ma1):
                    ma2 = ma1
                    ma1 = ele
                else:
                    ma2 = ele
                    
            elif (ele <= mi2 or ele <= mi1):
                if(ele < mi1):
                    mi2 = mi1
                    mi1 = ele
                else:
                    mi2 = ele
                    
        return (ma1*ma2) - (mi1*mi2)