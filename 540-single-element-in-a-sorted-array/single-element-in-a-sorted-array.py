class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        start=1
        n=len(nums)
        end=n-2
        if n==1:
            return nums[0]
        elif n>1 and nums[0]!=nums[1] :
            return nums[0]
        elif n>1 and nums[n-1]!=nums[n-2]:
            return nums[n-1]
        else:
            while start<=end:
                mid=start+(end-start)//2
                curr=nums[mid]
                prev=nums[mid-1]
                next=nums[mid+1]
                if curr!=prev and curr!=next:
                    return curr
                elif mid%2!=0:
                    if curr!=next:
                        start=mid+1
                    else:
                        end=mid-1
                else:
                    if curr!=next:
                        end=mid-1
                    else:
                        start=mid+1
        return -1   
        