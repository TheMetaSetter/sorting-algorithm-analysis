project(SortingAlgorithm)

add_executable(
    SortingAlgorithm

    main.cpp

    sorting-algo/BubbleSort.cpp
    sorting-algo/CountingSort.cpp
    sorting-algo/FlashSort.cpp
    sorting-algo/HeapSort.cpp
    sorting-algo/InsertionSort.cpp
    sorting-algo/MergeSort.cpp
    sorting-algo/QuickSort.cpp
    sorting-algo/RadixSort.cpp
    sorting-algo/SelectionSort.cpp
    sorting-algo/ShakerSort.cpp
    sorting-algo/ShellSort.cpp

    helper/DataGenerator.cpp
    helper/HandlingArrays.cpp
)