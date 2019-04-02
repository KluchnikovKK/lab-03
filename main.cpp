#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t number_count=0;
    cout<<" Enter number count: ";
    cin>>number_count;
    vector<double> numbers;
    numbers.resize(number_count);
    cout<<" Enter numbers: ";
    for(size_t i=0; i<number_count; i++)
    {
        cin>>numbers[i];
    }
    size_t bin_count;
    cout<<" Enter bin_count: ";
    cin>>bin_count;
    vector<size_t> bins(bin_count,0);
    double min=numbers[0], max=numbers[0];
    for(double x: numbers)
    {
        if(x<min)
        {
            min=x;
        }
        else if(x>max)
        {
            max=x;
        }
    }
    for(double number:numbers)
    {
        size_t bin_index=(number-min)*bin_count/(max-min);
        if(bin_index==bin_count)
        {
            bin_index--;
        }
        bins[bin_index]++;
    }
    for(size_t bin: bins)
    {
        cout<<bin;
        cout<<"|";
        for(size_t i=0; i<bin; i++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
