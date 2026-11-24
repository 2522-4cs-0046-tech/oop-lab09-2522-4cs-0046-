#include<iostream>
using namespace std;

class IntList {
private:
    int* data;
    int count;
    int capacity;

    void grow() {
        int oldCapacity = capacity;
        int newCapacity = capacity * 2;
        cout << "Resizing: " << oldCapacity << " -> " << newCapacity << endl;

        int* newData = new int[newCapacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    IntList() {
        capacity = 2;
        count = 0;
        data = new int[capacity];
    }

    ~IntList() {
        delete[] data;
        data = nullptr;
        cout << "IntList memory freed" << endl;
    }

    void add(int value) {
        if (count == capacity) {
            grow();
        }
        data[count] = value;
        count++;
    }

    int get(int index) const {
        if (index < 0 || index >= count) {
            cout << "Invalid index " << index << endl;
            return -1;
        }
        return data[index];
    }

    int size() const {
        return count;
    }

    void print() const {
        cout << "Size/Capacity: " << count << "/" << capacity << " | Items: [";
        for (int i = 0; i < count; i++) {
            cout << data[i];
            if (i < count - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    IntList list;

    for (int val = 10; val <= 60; val += 10) {
        list.add(val);
    }

    list.print();

    int item3 = list.get(3);
    if (item3 != -1) {
        cout << "Item at index 3: " << item3 << endl;
    }

    int item10 = list.get(10);
    if (item10 != -1) {
        cout << "Item at index 10: " << item10 << endl;
    }

    cout << "Current size: " << list.size() << endl;

    return 0;
}