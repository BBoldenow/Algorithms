import copy

def findPeak(arr):
    n = int(len(arr) / 2);

    if n > 0 and arr[n] < arr[n - 1]:
        return findPeak(arr[0:n])
    elif n + 1 < len(arr) and arr[n] < arr[n + 1]:
        return findPeak(arr[n:len(arr)])
    else:
        return True, arr[n]

def findPeak_2D(arr2D, row_start, row_end, col_start, col_end):
    col = int(col_start + (col_end - col_start) / 2)
    row = findGlobalMax(arr2D, col)

    if col > 0 and arr2D[row][col] < arr2D[row][col - 1]:
        return findPeak_2D(arr2D, row_start, row_end, col_start, col)
    elif col + 1 < len(arr2D) and arr2D[row][col] < arr2D[row][col + 1]:
        return findPeak_2D(arr2D, row_start, row_end, col, col_end)
    else:
        return True, arr2D[row][col]

def findGlobalMax(arr2D, col):
    ret = None
    
    for index in range(len(arr2D)):
        if ret is None or arr2D[index][col] > arr2D[ret][col]:
            ret = index

    return ret


nums = [
		[10, 10, 8, 10],
		[11, 12, 13, 14],
		[21, 11, 9, 15],
		[20, 19, 17, 16]
	]

found, val = findPeak_2D(nums, 0, len(nums), 0, len(nums[0]))

print(found, val)
