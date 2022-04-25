#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#pragma hdrstop
#include "histogram.h"
using namespace std;
int main()
{
    size_t number_count;
    cerr << "Enter number count:";
    cin >> number_count;
    const  auto  numbers = input_numbers(number_count); //вызов функции ввода чисел
    size_t bin_count; // количество корзин
    cerr<<"Enter bin count:";
    cin>>bin_count;
    double min,max;
    find_minmax( numbers, min,max);
    const auto bins = make_histogram(numbers,min,max,number_count,bin_count);
    show_histogram_svg(bins,bin_count);
    return 0;
}


