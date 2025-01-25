
#include <iostream>
using namespace std;
struct Heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        arr[size] = val;
        int i = size;
        size++;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i])
            {
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;
                i = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        arr[0] = arr[size - 1]; // replacing root with last element

        size--; // remove last element

        int i = 0;

        // take root node to its correct position

        while (i < size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[i] < arr[left])
            {
                int temp = arr[i];
                arr[i] = arr[left];
                arr[left] = temp;
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                int temp = arr[i];
                arr[i] = arr[right];
                arr[right] = temp;
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    h.insert(50);
    h.insert(100);
    h.insert(25);
    h.insert(45);
    h.insert(60);
    h.insert(200);
    h.print();

    h.deletefromheap();

    h.print();
    return 0;
}
