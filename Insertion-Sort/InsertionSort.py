def insertionSort(arr):
    for i in range(1, len(arr)):

        curVal = arr[i]
        pos = i

        while pos > 0 and curVal < arr[pos - 1]:
            swap = arr[pos]
            arr[pos] = arr[pos - 1]
            arr[pos - 1] = swap
            pos -= 1
