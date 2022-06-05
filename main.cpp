#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#pragma hdrstop
#include "histogram.h"

using namespace std;

vector<double>input_numbers(istream& in,size_t count) //функция ввода чисел
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}

void show_histogram_text(const vector <double> bins)
{
    const size_t SCREEN_WIDTH =80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH-3-1;// длина звездочек
    size_t max_bin = 0;
    for(size_t bin:bins)
    {
        if(bin>max_bin)
        {
            max_bin=bin;
        }
    }
       const bool check = max_bin > MAX_ASTERISK;
    for (size_t bin : bins) {
        if (bin < 100) {
            cout << ' ';
        }
        if (bin < 10) {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (check) {
            const double scaling_factor = (double)MAX_ASTERISK / max_bin;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';


}
}
int main()
{
    size_t number_count;
    cerr << "Enter number count:";
    cin >> number_count;
 const auto numbers = input_numbers(cin,number_count); //вызов функции ввода чисел
    size_t bin_count; // количество корзин
    cerr<<"Enter bin count:";
    cin>>bin_count;
    double min,max;
    find_minmax( numbers, min,max);
    const auto bins = make_histogram(numbers,min,max,number_count,bin_count);
    show_histogram_svg(bins,bin_count);
    return 0;
}


