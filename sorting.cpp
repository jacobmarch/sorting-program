#include <iostream>
#include <string>
#include <vector>

using namespace::std;


vector<int> input;
int maximum, minimum, range, userInput, temp, i;
double avg, sum;
bool contInput = true;

int main(){
    maximum = 0;
    minimum = 100000000;
    range = 0;
    sum = 0;
    avg = 0.0;

    //Gets inputs
    cout << "Enter Data: ";
    while (contInput == true){
        
        cin >> userInput;
        if (userInput < 0){
            break;
        }
        input.push_back(userInput);
        sum += userInput;
    }

    //iterates through the vector
    for (i = 0; i < input.size(); i++){
        if (i != input.size() - 1){
            if (input.at(i) > input.at(i + 1)){
                temp = input.at(i);
                input.at(i) = input.at(i+1);
                input.at(i+1) = temp;
            }
        }
        if (i != 0){
            if (input.at(i) < input.at(i - 1)){
                temp = input.at(i);
                input.at(i) = input.at(i-1);
                input.at(i-1) = temp;
            }
        }

        if (input.at(i) > maximum){
            maximum = input.at(i);
        }
        if (input.at(i) < minimum){
            minimum = input.at(i);
        }
    }

    range = maximum - minimum;
    avg = sum / input.size();

    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Range:   " << range << endl;
    cout << "Mean:    " << avg << endl;

    //Outputs vector for testing purposes
    cout << "Vector:  ";
    for (auto j = input.begin(); j != input.end(); j++){
        cout << *j << " ";
    }
    return 0;
}