#include<iostream>
#include<string>
using namespace std;

typedef int Input;
typedef string ExpectedOutput;

typedef struct{
    Input input;
    ExpectedOutput expected;
    bool passed;
    string message;
}TestResult;

string fizzbuzz(Input n) {
    if (n % 3 == 0 && n % 5 == 0) return "FizzBuzz";
    if (n % 3 == 0) return "Fizz";
    if (n % 5 == 0) return "Buzz";
    return to_string(n);
}

bool checkResult(Input input, ExpectedOutput expected) {
    return fizzbuzz(input) == expected;
}

TestResult runTest(Input input, ExpectedOutput expected) {
    TestResult result;
    result.input = input;
    result.expected = expected;
    result.passed = checkResult(input, expected);
    
    if (result.passed) {
        result.message = "Test passed.";
    } else {
        result.message = "Test failed: expected '" + expected + "', got '" + fizzbuzz(input) + "'.";
    }
    
    return result;
}

TestResult runTests1(){
    TestResult result;
    result = runTest(1, "1");
    cout << result.message << endl;
    result = runTest(3, "Fizz");
    cout << result.message << endl;
    result = runTest(4, "4");
    cout << result.message << endl;
    result = runTest(5, "Buzz");
    cout << result.message << endl;
    result = runTest(6, "Fizz");
    cout << result.message << endl;
    result = runTest(9, "Fizz");
    cout << result.message << endl;
    result = runTest(10, "Buzz");
    cout << result.message << endl;
    result = runTest(12, "Fizz");
    cout << result.message << endl;
    result = runTest(15, "FizzBuzz");
    cout << result.message << endl;
    result = runTest(20, "Buzz");
    cout << result.message << endl;
    result = runTest(30, "FizzBuzz");
    cout << result.message << endl;
    return result;
}

int main(int argc,char** argv){
    runTests1();
    return 0;
}