#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#include <curl/curl.h>
#pragma hdrstop
#include "histogram.h"
#include <sstream>
#include <string>

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

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    size_t data_size = item_size * item_count;
 stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
 buffer->write(reinterpret_cast<const char*>(items), data_size);
    return data_size;
}

Input
download(const string& address) {
    char *ip;
    curl_global_init(CURL_GLOBAL_ALL);
 stringstream buffer;
 CURL* curl = curl_easy_init();
    if(curl){
 CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
 res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if(res != CURLE_OK){
 cerr<<" Error text = "<<curl_easy_strerror(res);
            exit(1);
        }
        curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &ip); // IP
 cerr << "ip: " << ip << '\n';
    }
    return read_input(buffer, false);
}

int main(int argc, char* argv[])
{

 const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    printf("n = %08x\n", 0x1234567);
    return 0;

    size_t number_count;
    cerr << "Enter number count: ";

    /*Input input;

        if (argc > 1)
        {
            input = download(argv [1]);
        }
        else
        {
            input = read_input(cin, 1);
        }
        return 0;



    const auto bins = make_histogram(input);
    show_histogram_svg(bins);*/
}


