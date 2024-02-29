#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::vector<int> sortedArray = generateSortedArray(size);

    std::cout << "Отсортированный массив случайных чисел:\n";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}