#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

// version 1 of the solution (this has a slow runtime)
long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long output = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) { //
          if(((long long)numbers[first]) * numbers[second] > output){

            output = ((long long)numbers[first])  * numbers[second];

          }
        }
    }

    return output;
}


// version 2 of the solution (fast runtime)
long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();

    // this section below is scanning the array(vector<int>) twice


    // this is scanning for the first maximum element and storing it in max_index1
    int max_index1 = -1; // assigns max_index1 to -1
    for (int i = 0; i < n; ++i)
        if((max_index1 = -1) || (numbers[i] > numbers[max_index1])) //this compares (-1) to numbers[i]
          max_index1 = i; // assigns max_index1 to i (the index)


    // this is scanning the second array(vector<int>)
    int max_index2 = -1; // assigns max_index2 to -1
    for (int j = 0; j < n; ++j)
        if((numbers[j] != numbers[max_index1]) // this skips the first maximum element (first element in the array)
        && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))) //this compares (-1) to numbers[i]
        max_index2 = j; // assigns max_index1 to j (the index)

    // this returns the the product of the first and second array elements
    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    // int n; // assigning an empty variable to n
    // cin >> n; // user input for a number for the empty variable
    // vector<int> numbers(n); // creating an array with the name numbers and passing in the the user number
    // for (int i = 0; i < n; ++i) { // this for loop is passing in a max number from user and then loop asks from user numbers untill max is reached
    //     cin >> numbers[i]; //user input of numbers
    // }

    long long output = MaxPairwiseProductFast(vector<int>(100000, 0)); // this is calling the function MaxPairwiseProduct and assign it yo output
    cout << output << "\n"; //outputs function
    return 0;
}
