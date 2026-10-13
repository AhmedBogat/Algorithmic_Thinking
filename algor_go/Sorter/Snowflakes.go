package sorter

import (
	"fmt"
)

// longestPalindrome находит самый длинный палиндром за O(N) по памяти и O(N^2) по времени
func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}

	start, end := 0, 0

	for i := 0; i < len(s); i++ {
		// Центр — один символ (для нечетной длины, например "aba")
		len1 := expandAroundCenter(s, i, i)
		// Центр — между символами (для четной длины, например "abba")
		len2 := expandAroundCenter(s, i, i+1)

		maxLen := max(len1, len2)

		if maxLen > end-start {
			start = i - (maxLen-1)/2
			end = i + maxLen/2
		}
	}

	return s[start : end+1]
}

func expandAroundCenter(s string, left, right int) int {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	// Длина найденного палиндрома равна (right - 1) - (left + 1) + 1
	return right - left - 1
}

func SnowflakesRun() {
	var s string

	fmt.Print("Введите строку: ")
	// fmt.Scanf считывает форматированный ввод.
	// Обязательно передаем указатель &s, чтобы функция могла записать значение в переменную.
	_, err := fmt.Scanf("%s", &s)
	if err != nil {
		fmt.Printf("Ошибка ввода: %v\n", err)
		return
	}

	result := longestPalindrome(s)
	fmt.Printf("Самый длинный палиндром: %s\n", result)
}
