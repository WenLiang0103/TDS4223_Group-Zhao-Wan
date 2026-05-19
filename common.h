// common.h
#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;      
    double price;
    string category;
};

void radixSort(Product arr[], int n);
void bucketSort(Product arr[], int n);

double getRadixTime();
long long getRadixComparisons();
double getBucketTime();
long long getBucketComparisons();

#endif