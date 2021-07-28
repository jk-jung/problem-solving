def pick_peaks(arr):
    a = []
    b = []
    for i in range(1, len(arr) - 1):
        if arr[i - 1] < arr[i]:
            t = 0
            for j in range(i + 1, len(arr)):
                if arr[j] > arr[i]:
                    break
                if arr[j] < arr[i]:
                    t = 1
                    break

            if t:
                a.append(i)
                b.append(arr[i])

    return {'pos': a, 'peaks': b}
