class Solution(object):
    def update_total_and_count(self, total, count, pixel):
        return total + pixel, count + 1

    def imageSmoother(self, img):
        """
        :type img: List[List[int]]
        :rtype: List[List[int]]
        """
        row = len(img)
        column = len(img[0])
        smothed_img = [[] for _ in range(row)]
        
        for i, pixels in enumerate(img):
            for j, pixel in enumerate(pixels):
                total = pixel
                count = 1
                if 0 <= i - 1 and 0 <= j - 1:
                    total, count = self.update_total_and_count(
                        total, count, img[i - 1][j - 1]
                    )
                if 0 <= i - 1:
                    total, count = self.update_total_and_count(
                        total, count, img[i - 1][j]
                    )
                if 0 <= i - 1 and j + 1 < column:
                    total, count = self.update_total_and_count(
                        total, count, img[i - 1][j + 1]
                    )

                if 0 <= j - 1:
                    total, count = self.update_total_and_count(
                        total, count, img[i][j - 1]
                    )
                if j + 1 < column:
                    total, count = self.update_total_and_count(
                        total, count, img[i][j + 1]
                    )

                if i + 1 < row and 0 <= j - 1:
                    total, count = self.update_total_and_count(
                        total, count, img[i + 1][j - 1]
                    )
                if i + 1 < row:
                    total, count = self.update_total_and_count(
                        total, count, img[i + 1][j]
                    )
                if i + 1 < row and j + 1 < column:
                    total, count = self.update_total_and_count(
                        total, count, img[i + 1][j + 1]
                    )

                smothed_img[i].append(total // count)

        return smothed_img