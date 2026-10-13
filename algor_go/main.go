package main

import (
	"algor_go/Sorter"
	"fmt"
)

func main() {
	var scores = []int{90, 70, 50, 65, 85}
	var length = len(scores)
	
	sorter.BubbleSorter(scores, length)
	
	for _, scores := range scores {
		fmt.Printf("%d\t", scores)
	}
	fmt.Println()
}
