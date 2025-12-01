def merge_sort(arr):
	if len(arr) <= 1:
		return arr
	
	mid = len(arr) // 2
	
	left_arr = merge_sort(arr[:mid])
	right_arr = merge_sort(arr[mid:])
	
	return merge(left_arr, right_arr)

def merge(arr1, arr2):
	i=0
	lst=[]
	j=0
	while (i < len(arr1) and j < len(arr2)):
		if arr1[i] < arr2[j]:
			lst.append(arr1[i])
			i+=1
		else:
			lst.append(arr2[j])
			j+=1
	
	while i < len(arr1):
		lst.append(arr1[i])
		i+=1
	
	while j < len(arr2):
		lst.append(arr2[j])
		j+=1	
	
	return lst


lsstt = [12, 21, 65, 2, 34, 7, 9]
print(merge_sort(lsstt))
