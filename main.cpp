///HeapSort static
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector <int> CreateArray(){ //Creating a random massive
    srand (static_cast <unsigned int>(time(0))); //Seed
    vector <int> array(rand() % 13 + 1);
    for (int i = 0; i < array.size(); i++)
        array[i] = rand() % 100;
    return array;
}

void Vypis(vector <int> array){
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

void Heapify(vector <int> &array, int i, int n){ // Creating heap/ i - index na ktery se vola HEAPIFY/n - pocet uzlu
    int max = i;
    int leftSon = 2 * i + 1; //index of LSon
    int rightSon = 2 * i + 2; //index of RSon
    if (leftSon < n && array[leftSon] < array[i]) { //dad < Lson
        max = leftSon;
    }

    if (rightSon < n && array[rightSon] < array[max]){ //dad < Rson
        max = rightSon;
    }

    if (max != i){
        swap(array[i], array[max]);
        Heapify(array, max, n);
    }
}

void BuildHeap(vector <int> &array){
    for (int i = (array.size() - 1) / 2; i >= 0; i--)
        Heapify(array, i, array.size());
}

void HeapSort(vector <int> &array){
    BuildHeap(array);
    for(int i = array.size() - 1; i > 0; i --) {
        swap(array[0], array[i]);
        Heapify(array, 0, i);
    }
}

int main() {
    vector <int> input = CreateArray();
    cout << "Its the created array: " << endl;
    Vypis(input);
    HeapSort(input);
    cout << "Heap-sorted array: " << endl;
    Vypis(input);
    return 0;
}
