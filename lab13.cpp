// lab 13: debugging and testing

#include <iostream>
#include <vector>

using namespace std;

bool fail_lecture_correct(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 0; i < attendance_records.size(); ++i) {  // index starts at zero, includes first lecture
        absent_count += attendance_records[i] == 0;
    }
    return absent_count >= 3;
}

bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += attendance_records[i] == 0;
    }
    return absent_count >= 3;
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
}

int main() {
    cout << "test case 1: fault not executed\n";
    
    vector<int> tc2 = {1,0,1,1,1,1,1,1,1};

    vector<int> tc3 = {0,1,1,1,1,1,1,1,1};

    vector<int> tc4 = {0,0,0,1,1,1,1,1,1};

    vector<vector<int>> tests = {tc2, tc3, tc4};
    vector<string> labels = {
        "test case 2",
        "test case 3",
        "test case 4"
    };

    for (int i = 0; i < tests.size(); i++) {
        cout << labels[i] << "\n";
        cout << "attendance: ";
        printVector(tests[i]);
        cout << "\n";

        bool expected = fail_lecture_correct(tests[i]);
        bool actual = fail_lecture(tests[i]);

        cout << "expected output: " << (expected ? "FAIL" : "PASS") << "\n";
        cout << "actual output: " << (actual ? "FAIL" : "PASS") << "\n";

        if (expected != actual)
            cout << "failure detected\n";
        else
            cout << "no failure detected\n";
    }

    return 0;
}