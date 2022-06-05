#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#include <curl/curl.h>
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


void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (size(numbers) > 0)
    {


    min=numbers[0];    // границы корзины
    max = numbers[0];

    for(double number : numbers) // проходимся по всем элементам и находим минимальную и максимальную границу корзины
    {
            if(min>number)
        {
            min=number ;
        }
        else if(max<number)
        {
            max=number;
        }



    }
    }
}
Input
read_input(istream& in,bool prompt) {
    Input data;
if (prompt){
    cerr << "Enter number count: ";
}
    size_t number_count;
    in >> number_count;
if (prompt){
    cerr << "Enter numbers: ";
}
    data.numbers = input_numbers(in,number_count);
if (prompt){
    cerr << "Enter bin count: ";
}
    in >> data.bin_count;

    return data;
}

vector<double>make_histogram(Input data){
    double min, max;
     find_minmax(data.numbers, min, max);
 vector<double> bins(data.bin_count, 0);
    for (double number : data.numbers) {
        size_t bin = (size_t)(((number - min) / (max - min)) * data.bin_count);
        if (bin == data.bin_count) {
 bin--;
        }
 bins[bin]++;
    }
    return(bins);
}


void show_histogram_text(const vector <double> &bins)
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


int
main(int argc, char* argv[]) {
  if (argc > 1){

        CURL *curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
                             res = curl_easy_perform(curl);
                             curl_easy_cleanup(curl);

        }
        return 0;
    }
curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin,1);
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
}


