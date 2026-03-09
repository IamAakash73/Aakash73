class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        pivot = -1

        # Step 1: Find the rightmost index 'i' such that nums[i] < nums[i + 1]
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                pivot = i
                break
        
        # If no such index exists, the array is in descending order.
        # Reverse it to get the lowest possible order (ascending).
        if pivot == -1:
            nums.reverse()
            return

        # Step 2: Find the rightmost index 'j' such that nums[j] > nums[pivot]
        for j in range(n - 1, pivot, -1):
            if nums[j] > nums[pivot]:
                # Swap pivot and j
                nums[pivot], nums[j] = nums[j], nums[pivot]
                break
        
        # Step 3: Reverse the sequence to the right of the pivot
        # This ensures we have the smallest lexicographical increase.
        left, right = pivot + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
