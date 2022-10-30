#include <QCoreApplication>
#include <QRandomGenerator>
#include <iostream>
#include "calculator.h"
using namespace std;

void enterArr(std::string arr[], int numOfNumbers){
    std::cout << "Enter number: \n";
    for(int i = 0; i < numOfNumbers; i++){
        std::cout << "Enter number " << i + 1 << " : ";
        std::cin >> arr[i];
    }
}

void showArr(std::string arr[], int numOfNumbers){
    std::cout <<"Value Arr: ";
    for(int i = 0; i < numOfNumbers; i++){
        std::cout << arr[i] << " ";
    }
    std::cout <<"\n";
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int numOfNumbers = 0;
    std::cout << "Enter number of numbers: ";
    std::cin >> numOfNumbers;
    if(numOfNumbers>10){
       std::cout << "Re-enter number of numbers: ";
       std::cin >> numOfNumbers;
    }
    std::string* arr = new std::string[numOfNumbers];

    enterArr(arr, numOfNumbers);

    bubbleSort(arr, numOfNumbers);

    //showArr(arr, numOfNumbers);

    calculateMinMax(arr, numOfNumbers);

    return a.exec();
}

