#include <vector>
#include <iostream>
#include <fstream>

int main() {
    std::fstream fs;
    fs.open("text.txt");
    fs << "test input strings";
    fs.close();
    return 0;
}