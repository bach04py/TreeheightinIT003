#include <bits/stdc++.h>
using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomN(100000, 1000000); // Min-max of N (~10^6)
    uniform_int_distribution<int> randomNumber(10000, 10000000); // Min-max of elements in tree
    ofstream fo("logN&145logN.txt"); // This file contains logN and 1.45logN values of 10 datasets
    for (int i = 1; i <= 10; ++i) {
        string filename = "input" + std::to_string(i) + ".txt"; // Name of dataset file
        ofstream file(filename);
        int N = randomN(gen);
        file << N <<'\n';

        if (i < 3) {
            set<int> uniqueNumbers;
            while (uniqueNumbers.size() < N) {
                uniqueNumbers.insert(randomNumber(gen));
            }
            if (i == 1) { // dataset1.txt has ascending elements
                for (const int& num : uniqueNumbers) {
                    file << num << ' ';
                }
            } else { // dataset2.txt has descending elements
                set<int>::reverse_iterator rit;
                for (rit = uniqueNumbers.rbegin(); rit != uniqueNumbers.rend(); rit++)
                    file << *rit << " ";
            }
        } else { // dataset3.txt ... dataset10.txt has random ordered elements
            unordered_set<int> uniqueNumbers;
            while (uniqueNumbers.size() < N) {
                uniqueNumbers.insert(randomNumber(gen));
            }
            for (const int& num : uniqueNumbers) {
                file << num << ' ';
            }
        }
        fo << log2(N) <<' '<< 1.45*log2(N) <<'\n';
        file.close();
    }
    return 0;
}
