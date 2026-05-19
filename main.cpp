#include "common.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global variables
Product inventory[500];
int currentSize = 0;

// Function declarations (to be implemented by M4)
void loadData(Product arr[], int& n, string filename);
void displayData(Product arr[], int n);
void generateRandomData(Product arr[], int n);
void generateLongTailData(Product arr[], int n);

// Show menu
void showMenu() {
    cout << "\n=== WAREHOUSE INVENTORY SYSTEM ===\n";
    cout << "1. Load Dataset\n";
    cout << "   1a. 100 records (Random Distribution)\n";
    cout << "   1b. 100 records (Long-tail Distribution)\n";
    cout << "   1c. 500 records (Random Distribution)\n";
    cout << "   1d. 500 records (Long-tail Distribution)\n";
    cout << "2. Display Current Inventory\n";
    cout << "3. Radix Sort\n";
    cout << "4. Bucket Sort\n";
    cout << "5. Show Performance Report\n";
    cout << "6. Export Sorted Results to File\n";
    cout << "7. Exit\n";
    cout << "Choose: ";
}

// Show performance report
void showPerformanceReport() {
    cout << "\n========== PERFORMANCE REPORT ==========\n";
    cout << "Dataset size: " << currentSize << " records\n";
    cout << "-----------------------------------------\n";
    cout << "Radix Sort:\n";
    cout << "  - Execution time: " << getRadixTime() << " ms\n";
    cout << "  - Comparisons: " << getRadixComparisons() << "\n";
    cout << "\nBucket Sort:\n";
    cout << "  - Execution time: " << getBucketTime() << " ms\n";
    cout << "  - Comparisons: " << getBucketComparisons() << "\n";
    cout << "=========================================\n";
}

int main() {
    int choice;
    string subChoice;
    
    while (true) {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Select distribution (a/b/c/d): ";
                cin >> subChoice;
                if (subChoice == "a") {
                    generateRandomData(inventory, 100);
                    currentSize = 100;
                    cout << "Loaded 100 random distribution records\n";
                } else if (subChoice == "b") {
                    generateLongTailData(inventory, 100);
                    currentSize = 100;
                    cout << "Loaded 100 long-tail distribution records\n";
                } else if (subChoice == "c") {
                    generateRandomData(inventory, 500);
                    currentSize = 500;
                    cout << "Loaded 500 random distribution records\n";
                } else if (subChoice == "d") {
                    generateLongTailData(inventory, 500);
                    currentSize = 500;
                    cout << "Loaded 500 long-tail distribution records\n";
                }
                break;
            case 2:
                displayData(inventory, currentSize);
                break;
            case 3:
                radixSort(inventory, currentSize);
                cout << "Radix Sort completed! Time: " << getRadixTime() << " ms\n";
                break;
            case 4:
                bucketSort(inventory, currentSize);
                cout << "Bucket Sort completed! Time: " << getBucketTime() << " ms\n";
                break;
            case 5:
                showPerformanceReport();
                break;
            case 6:
                cout << "Export function to be implemented\n";
                break;
            case 7:
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}