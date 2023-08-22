#include <iostream>
#include <string>
using namespace std;
int combinationCounter{}, permutationCounter{};

void permute(string& a, int l, int r) {
    if (l == r){
        cout << a << endl;
        permutationCounter ++;
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}

void Combination(string& arr, int n) {
    int counter = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cout << arr[j] << " ";
        cout << endl;
        combinationCounter++;
    }
}

int main() {
    string str = "Tnq";  //beshi boro string dile sara din run hobe
    int n = str.size();
    cout<<"Permutation:\n";
    permute(str, 0, n - 1);
    cout<<"\nCombination:\n";
    Combination(str, n);
    cout<<"\nNumber of permutation is : "<< permutationCounter <<endl;
    cout << "Total number of combinations: " << combinationCounter << endl;
    return 0;
}
