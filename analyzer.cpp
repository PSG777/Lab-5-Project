#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "StringData.h"

using namespace std;
using namespace std::chrono;


int linear_search(const vector<string>& container, const string& element) {
    for(int i = 0; i < container.size(); i++)
    {
        if (container[i] == element)
            return i;
    }
    return -1;
}

int binary_search(const vector<string>& container, const string& element) {
    int low = 0;
    int high = container.size() - 1;
    int middle = (low + high) / 2;

    while(low <= high) {
        int middle = low + (high - low) / 2;
        if(container[middle] == element) {
            return middle;
        }
        else if(container[middle] < element) {
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }

    }
    return -1;
}

int main()
{
    vector<string>data = getStringData();
    cout << "Time difference between linear search and binary search" << endl;
    cout << "*******************************************************" << endl;

    auto start = chrono::system_clock::now();
    int index = linear_search(data, "not_here");
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "Linear search for 'not_here': index " << index << " and takes " << elapsed_seconds.count() << " seconds\n";

    // Measure time for binary search (for "not_here")
    auto start2 = chrono::system_clock::now();
    int index2 = binary_search(data, "not_here");
    auto end2 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "Binary search for 'not_here': index " << index2 << " and takes " << elapsed_seconds2.count() << " seconds\n";

    cout << endl;

    // Repeat for other searches (e.g., "mzzzz")
    auto start3 = chrono::system_clock::now();
    int index3 = linear_search(data, "mzzzz");
    auto end3 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds3 = end3 - start3;
    cout << "Linear search for 'mzzzz': index " << index3 << " and takes " << elapsed_seconds3.count() << " seconds\n";

    auto start4 = chrono::system_clock::now();
    int index4 = binary_search(data, "mzzzz");
    auto end4 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4 = end4 - start4;
    cout << "Binary search for 'mzzzz': index " << index4 << " and takes " << elapsed_seconds4.count() << " seconds\n";

    cout << endl;

    auto start5 = chrono::system_clock::now();
    int index5 = linear_search(data, "aaaaa");
    auto end5 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds5 = end4 - start4;
    cout << "Linear search for 'aaaaa': index " << index5 << " and takes " << elapsed_seconds5.count() << " seconds\n";

    auto start6 = chrono::system_clock::now();
    int index6 = binary_search(data, "aaaaa");
    auto end6 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds6 = end6 - start6;
    cout << "Binary search for 'aaaaa': index " << index6 << " and takes " << elapsed_seconds6.count() << " seconds\n";
}


