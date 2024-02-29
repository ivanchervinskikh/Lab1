#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>



int getRandomElement(const std::vector<int>& arr) {
    srand(static_cast<unsigned int>(time(nullptr))); // устанавливаем seed для генерации случайных чисел
    int randomIndex = rand() % arr.size(); // генерируем случайный индекс в пределах размера массива
    return arr[randomIndex]; // возвращаем случайный элемент
}


int binarySearch(const std::vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}


std::vector<int> generateSortedArray(int size) {
    std::vector<int> array(size);

    // Генерируем случайные числа
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000);

    array[0] = dis(gen); // Генерируем первый элемент

    // Генерируем остальные элементы так, чтобы массив оставался отсортированным
    for (int i = 1; i < size; ++i) {
        array[i] = array[i - 1] + dis(gen); // Плюсуем случайное число к предыдущему элементу
    }

    return array;
}

int main() {

    double times[499] = {};
    int arrays[499] = {};
    double t;

    clock_t startTime = clock();
    for (int i = 1000; i < 500000; i += 1000) {
        std::vector<int> sortedArray = generateSortedArray(i);
        int key = getRandomElement(sortedArray);    
        int index = binarySearch(sortedArray, key);
        if (index != -1) {
            clock_t endTime = clock();
            double executionTime = double(endTime - t) / CLOCKS_PER_SEC;
            times[(i - 1000)/1000] = executionTime;
            arrays[(i - 1000)/1000] = i;
            t = executionTime;

        }
    }
    
    std::ofstream file("databin.txt");
    if (file.is_open()) {
        for (int i = 0; i < 499; i++) {
            file << arrays[i] << std::endl;
        }
        for (int i = 0; i < 499; i++) {
            file << times[i] << std::endl;
        }
        file.close();
        std::cout << "Data has been written to file data.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
        return 1;
    }
    
    return 0;
}


