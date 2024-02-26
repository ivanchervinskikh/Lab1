#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

void func()
{
    std::cout<<"HW";
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int a;
    double times[499] = {};
    int arrays[499] = {};
    double t;


    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 9);

    clock_t startTime = clock();
    for (int i = 1000; i < 500000; i+=1000){
        int nums[i] = {}; 
        for (unsigned counter = i; counter != 0; --counter){
            nums[i - counter] = arr[dstr(rng)] << '\n';
        }
        a = nums[dstr(rng)];
        for (int j; j < i; j++){
            if (nums[j] == a){
                clock_t endTime = clock();
                double executionTime = double(endTime - t) / CLOCKS_PER_SEC;
                times[(i - 1000)/1000] = executionTime;
                arrays[(i - 1000)/1000] = i;
                t = executionTime;
                break;
            }
        }
    }
    std::cout<<std::endl;
    


    std::ofstream file("data.txt");
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
