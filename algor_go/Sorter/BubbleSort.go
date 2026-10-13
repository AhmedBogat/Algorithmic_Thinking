package sorter

func BubbleSorter(array []int, lengh int) {
	for i := 0; i < lengh-1; i++ {
		for j := 0; j < lengh-i-1; j++ {
			if array[j] > array[j+1] {
				var flag = array[j]
				array[j] = array[j+1]
				array[j+1] = flag
			}
		}
	}
}
