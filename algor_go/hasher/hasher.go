package hasher

import "fmt"

// hashSize заменяет макрос #define hashsize(n)
func hashSize(n uint) uint64 {
	return uint64(1) << n
}

// hashMask заменяет макрос #define hashmask(n)
func hashMask(n uint) uint64 {
	return hashSize(n) - 1
}

// oaat реализует хэш Дженкинса
func oaat(key []byte, bits uint) uint64 {
	var hash uint64 = 0

	for i := 0; i < len(key); i++ {
		hash += uint64(key[i])
		hash += (hash << 10)
		hash ^= (hash >> 6)
	}

	hash += (hash << 3)
	hash ^= (hash >> 11)
	hash += (hash << 15)

	return hash & hashMask(bits)
}

func Hashmain() {
	hasher.Runner()
	key := []byte("hello world")
	var bits uint = 16

	//result := oaat(key, bits)
	fmt.Printf("Hash: %d\n", oaat(key, bits))
}
