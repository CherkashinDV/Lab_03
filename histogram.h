
#pragma once
#include <vector>

using namespace std;
vector<double>input_numbers(size_t count);
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double>make_histogram(const vector<double>numbers,double min, double max,size_t number_count,size_t bin_count);
void show_histogram_text(const vector <double> bins);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height,string stroke ="red" , string fill="red" );
void show_histogram_svg(const vector<double>& bins,size_t bin_count);



