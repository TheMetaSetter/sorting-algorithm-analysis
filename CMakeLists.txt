cmake_minimum_required(VERSION 3.0.0)
project(SortingAlgorithm)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
set(SANITIZE_ADDRESS TRUE)
set(CMAKE_CXX_STANDARD 17)
find_package(Sanitizers)

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
    helper/Utilities.cpp
)

add_sanitizers(SortingAlgorithm)