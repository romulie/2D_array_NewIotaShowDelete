#include<iostream>
#include<numeric>

// Taking the dimensions and starting value of the 2D-array from std::cin
// Creating a 2D array of the size Y*X on the heap
// Filling it with numbers from START to Y*X-1
// Printing the array to std::cout
// Deallocating memory from the heap

int** create_2d_arr(int y, int x, int start){
    int** arr = new int*[y];
    for (int i = 0; i < y; ++i){
        arr[i] = new int[x];
        std::iota(arr[i], arr[i]+x, start + i*x);
    }
    return arr;
}

void show_2d_arr(int* arr[], int y, int x){ // or int* arr[]
    for (int i = 0; i < y; ++i){
        for (int j = 0; j < x; ++j){
            std::cout<<arr[i][j]<<'\t';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void delete_2d_arr(int** arr, int y){
    for (int i = 0; i < y; ++i){
        delete[] arr[i];
    }
    delete[] arr;
}

int main(){

    std::cout<<"The program creates 2D-array of size Y*X of integers"<<std::endl;
    std::cout<<"and fills it with numbers from START-value to Y*X-1"<<std::endl;
    std::cout<<"Please specify the Y-SIZE of the 2d-array and press Enter: ";
    int y;
    std::cin >> y;
    if (y < 0) y *= -1;
    std::cout<<"Please specify the X-SIZE of the 2D-array and press Enter: ";
    int x;
    std::cin >> x;
    if (x < 0) x *= -1;
    std::cout<<"Please specify the START-value for the first element and press Enter: ";
    int start;
    std::cin >> start;
    std::cout<<'\n'<<'\n';

    int** arr = create_2d_arr(y, x, start);
    std::cout<<"Created 2D-array: "<<std::endl;
    show_2d_arr(arr, y, x);
    std::cout<<"Deallocating memory from 2D-array.... "<<std::endl;
    delete_2d_arr(arr, y);

    system("pause");
    return 0;
}
