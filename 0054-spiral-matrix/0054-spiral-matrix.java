class Solution {

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int i = 0, sn = -1, en = matrix.length, j = 0, sm = -1, em = matrix[0].length;
        while (isValid(i, j, sn, sm, en, em)) {
            while (isValid(i, j, sn, sm, en, em)) res.add(matrix[i][j++]);
            j--;
            i++;
            sn++;
            while (isValid(i, j, sn, sm, en, em)) res.add(matrix[i++][j]);
            i--;
            j--;
            em--;
            while (isValid(i, j, sn, sm, en, em)) res.add(matrix[i][j--]);
            j++;
            i--;
            en--;
            while (isValid(i, j, sn, sm, en, em)) res.add(matrix[i--][j]);
            i++;
            j++;
            sm++;
        }
        return res;
    }

    private static boolean isValid(int i, int j, int sn, int sm, int en, int em) {
        return (i > sn && j > sm && i < en && j < em);
    }
}
