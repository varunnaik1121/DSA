class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n=len(nums)
        def findPivot(nums):

            for x in range(n-1):
                if nums[x+1]<nums[x]:
                    return x+1
            return -1
        pivotIdx=findPivot(nums)
     
        
        def binarySearch(nums,start,end,target):
            while start<=end:
                mid=start+(end-start)//2
                if target==nums[mid]:
                    return True
                else:
                    if target>nums[mid]:
                        start=mid+1
                    else:
                        end=mid-1
            return False
        if pivotIdx==-1:
            return binarySearch(nums,0,n-1,target)
        else:
            return binarySearch(nums,0,pivotIdx-1,target) or binarySearch(nums,pivotIdx,n-1,target)
        return false
    
        