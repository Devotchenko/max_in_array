#include <iostream>
#include <cstdlib> 
#include <ctime>   

int countMaxRepetitions(const int* array, int size) {
    if (size <= 0) {
        return 0; 
    }

    int maxElement = array[0];
    int count = 1; 

    for (int i = 1; i < size; ++i) {
        if (array[i] > maxElement) {
            maxElement = array[i];
            count = 1; 
        }
        else if (array[i] == maxElement) {
            ++count; 
        }
    }

    return count;
}

int main() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));
        
    int array1[] = { -10, -3, -5, -3, -5, -5 };
    int array2[] = { -2, -2, -2, -2, -2 };
    int array3[] = { -1, 1, -2, 2, -3, 3, 4, -4, 5, -5, 5 };

    std::cout << "Array 1 max repetitions: " << countMaxRepetitions(array1, sizeof(array1) / sizeof(array1[0])) << std::endl;
    std::cout << "Array 2 max repetitions: " << countMaxRepetitions(array2, sizeof(array2) / sizeof(array2[0])) << std::endl;
    std::cout << "Array 3 max repetitions: " << countMaxRepetitions(array3, sizeof(array3) / sizeof(array3[0])) << std::endl;

    std::cout << "Enter the size of the dynamic array: ";
    int dynamicSize;
    std::cin >> dynamicSize;

    if (dynamicSize > 0) {
        int* dynamicArray = new int[dynamicSize];

        
        for (int i = 0; i < dynamicSize; ++i) {
            dynamicArray[i] = rand() % 200 - 100; 
            std::cout << dynamicArray[i] << " "; 
        }
        std::cout << std::endl;

      
        std::cout << "Dynamic array max repetitions: " << countMaxRepetitions(dynamicArray, dynamicSize) << std::endl;

        delete[] dynamicArray; 
    }
    else {
        std::cout << "Invalid size for dynamic array." << std::endl;
    }

    return 0;
}
