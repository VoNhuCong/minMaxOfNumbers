#include <QCoreApplication>
#include <calculator.h>
#include <iostream>
using namespace std;


void equal_length(string &a, string &b)
{
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
}

string add(string a, string b)
{
    equal_length(a, b);
    int carry = 0;
    string res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        carry = d / 10;
        res = (char)(d % 10 + '0') + res;
    }
    if (carry)
        res = '1' + res;

    return res;
}

bool compareGreater(string a, string b)
{
    equal_length(a, b);

    bool aGreaterThanB = false;

    for(int i = 0; i < a.size(); i++){
        if(int(a[i]) > int(b[i])){
            aGreaterThanB = true;
            break;
        }
        if(int(a[i]) < int(b[i])){
            aGreaterThanB = false;
            break;
        }
    }
    return aGreaterThanB;
}

void bubbleSort(std::string arr[], int N){
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-i-1; j++){
            if(compareGreater(arr[j], arr[j+1])){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void calculateMinMax(const string arr[], int numOfNumber)
{
    std::string minValue = "0";
    std::string maxValue = "0";
    for(int i = 0; i < numOfNumber - 1; i++){
        minValue = add(minValue, arr[i]);
    }
    for(int i = 1; i < numOfNumber; i++){
        maxValue = add(maxValue, arr[i]);
    }
    std::cout << "min-max: " << minValue << "-" << maxValue << endl;

}
