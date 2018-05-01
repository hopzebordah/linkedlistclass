/*
Alexander Peters
Linked list monthy rainfall driver function
*/

#include <iostream>
#include "linkedlist.h"

using namespace std;

double findMax(int numElements, linkedlist<double> &data)
{
    double max = data.get(0);
    for (int i=1; i<numElements; i++)
    {
        if (max < data.get(i))
            max = data.get(i);
    }
    return max;
}

double findMin(int numElements, linkedlist<double> &data)
{
    double min = data.get(0);
    for (int i=0; i<numElements; i++)
    {
        if (min > data.get(i))
            min = data.get(i);
    }
    return min;
}

int main()
{
    double numMonths = 0; 
    cout << "Please enter number of months --> ";
    cin >> numMonths;
    cout << endl;
    
    linkedlist<double> monthData;
    double input = 0; 
    for (int i=0; i<numMonths; i++)
    {
        cout << "Enter total rainfall for month " << i << ": ";
        cin >> input; 
        monthData.append(input);
    }
    cout << endl;   
 
    double sum = 0;
    for (int i=0; i<numMonths; i++)
    {
        sum += monthData.get(i); 
    }
    
    cout << "Total rainfall for " << numMonths << " months: " << sum << endl;
    cout << "Average monthly rainfall: " << (sum / numMonths) << endl; 
    cout << "Month with highest rainfall: " << findMax(numMonths, monthData) << endl;
    cout << "Month with lowest rainfall: " << findMin(numMonths, monthData) << endl; 
     
    return 0;
}
