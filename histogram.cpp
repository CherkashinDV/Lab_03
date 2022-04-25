#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#pragma hdrstop

#include "histogram.h"



vector<double>input_numbers(size_t count) //функция ввода чисел
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
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




vector<double>make_histogram(const vector<double>numbers,double min, double max,size_t number_count,size_t bin_count)
{
    vector<double>bins(bin_count,0);
    double bin_size=(max-min)/bin_count;
    for(size_t i = 0 ; i<number_count; i++) // проходимся по элементам
    {
        bool found = false;
        for(size_t j=0; j<(bin_count-1) && !found; j++) // проходимся по корзинам
        {
            auto lo = min + bin_size*j;
            auto hi = min + bin_size*(j+1);

            if((lo<=numbers[i]) && (numbers[i]<hi)) // проверка на попадание элемента в корзину
            {
                bins[j]++;
                found=true;

            }
        }
        if(!found) // проверка ,чтобы  элементы соответсвующие правой границе гистограммы попадали в корзину
        {
            bins[bin_count-1]++;
        }
    }
    return bins;
}


void show_histogram_text(const vector <double> bins)
{
    const size_t SCREEN_WIDTH =80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH-3-1;// длина звездочек
    size_t max_bin = 0;
    for(size_t bin:bins)
    {

        if(max_bin<=bin)
        {
            max_bin=bin;
        }

    }
}

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text) {
    cout << "<text x='"<<left<<"' y='" <<baseline<< "'>"<<text<< "</text>";}

void svg_rect(double x, double y, double width, double height,string stroke , string fill )
{
 cout<<"<rect x='" << x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />" <<endl;

}
 void show_histogram_svg(const vector<double>& bins,size_t bin_count)
{
        const auto IMAGE_WIDTH = 400;
        const auto IMAGE_HEIGHT = 300;
        const auto TEXT_LEFT = 20;
        const auto TEXT_BASELINE = 20;
        const auto TEXT_WIDTH = 50;
        const auto BIN_HEIGHT = 30;
        const auto BLOCK_WIDTH = 10;
        const string stroke ="red";
        const string fill="red";



        svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
        double top = 0;
        for (size_t bin : bins)
        {
            const double bin_width = BLOCK_WIDTH * bin;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"red","green");
            top += BIN_HEIGHT;
        }
        svg_end();
    }




