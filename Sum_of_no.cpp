#include <iostream>
using namespace std;

int sum(int k){
    if(k>0){
        return k + sum(k-1);
    }else{
        return 0;
    }
}

int main() {
    int result = sum(5);
    cout << "The sum of numbers from 1 to 5 is: " << result << endl;
    
}
