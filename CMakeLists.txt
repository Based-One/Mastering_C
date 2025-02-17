cmake_minimum_required(VERSION 3.29)
project(Mastering_C C)

set(CMAKE_C_STANDARD 23)

add_executable(Mastering_C "Use Cases/AiportSimulation (Aeroplanes) .c"
        "Data Structures/Queue.c"
        "Data Structures/GenericQueueDataStructure.c"
        "Data Structures/LinkedList.c"
        "Data Structures/StackImplementation.c"
        Strings.c
        "Use Cases/Factorial.c"
        Algorithms/QuickSort.c
        LeetCodes/SortColors.c
#        Examen.c
        "Data Structures/BTree.c"
        "Data Structures/HashTable.c"
        "Data Structures/GenericHashTable.c"
        Algorithms/BloomFilter/BloomFilter.c
        Algorithms/BloomFilter/hashf.h
        Algorithms/BloomFilter/hashf.c
        Algorithms/BloomFilter/bitArray.h
        Algorithms/BloomFilter/bitArray.c
        Algorithms/BloomFilter/BloomFilter.h
        LeetCodes/TwoSum.c
        "Algorithms/Dynamic Programming/MaxConsecutiveSum.c"
        Algorithms/Round.c
        Algorithms/WordsFrecuency.c
        Algorithms/Huffman.c
        Algorithms/O.c
)
