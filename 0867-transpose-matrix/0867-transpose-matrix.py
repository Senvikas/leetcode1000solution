class Solution(object):
    def transpose(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        rows, cols = len(matrix), len(matrix[0])
        transposeM = [[0] * rows for _ in range(cols)]
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                transposeM[j][i] = matrix[i][j]
        return transposeM