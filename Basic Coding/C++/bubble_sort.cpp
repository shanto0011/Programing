#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(int a, int b) {
    return a > b;
}

//using reference of vector
void bubble_sort(vector<int>& vec) {
    int n = vec.size();
    printf("\n------%d---------\n", n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(vec[j], vec[j + 1])) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> vec{-2,  4, -1, 6, 1, 3};

    //call by reference
    bubble_sort(vec);

    cout << "Sorted vector: ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
