#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define MAX 100000
std::unordered_map<long int,long int>Swapsmap;

using namespace std;

class MinHeap
{
private:
    vector<long int> _vector;
    void BubbleDown(long int index);
    void BubbleUp(long int index);
    void Heapify();

public:
    MinHeap(long int* array, long int length);
    MinHeap(const vector<long int>& vector);
    MinHeap();

    void Insert(long int newValue);
    long int GetMin();
    void DeleteMin();
};
MinHeap::MinHeap(long int* array, long int length) : _vector(length)
{
    for(long int i = 0; i < length; ++i)
    {
        _vector[i] = array[i];
    }

    Heapify();
}

MinHeap::MinHeap(const vector<long int>& vector) : _vector(vector)
{
    Heapify();
}

MinHeap::MinHeap()
{
}

void MinHeap::Heapify()
{
    long int length = _vector.size();
    for(long int i=length-1; i>=0; --i)
    {
        BubbleDown(i);
    }
}

void MinHeap::BubbleDown(long int index)
{
    long int length = _vector.size();
    long int leftChildIndex = 2*index + 1;
    long int rightChildIndex = 2*index + 2;

    if(leftChildIndex >= length)
        return; //index is a leaf

    long int minIndex = index;

    if(_vector[index] > _vector[leftChildIndex])
    {
        minIndex = leftChildIndex;
    }

    if((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex]))
    {
        minIndex = rightChildIndex;
    }

    if(minIndex != index)
    {
        //need to swap
        Swapsmap.insert(std::make_pair(minIndex,index));
        long int temp = _vector[index];
        _vector[index] = _vector[minIndex];
        _vector[minIndex] = temp;
        BubbleDown(minIndex);
    }
}

void MinHeap::BubbleUp(long int index)
{
    if(index == 0)
        return;

    long int parentIndex = (index-1)/2;

    if(_vector[parentIndex] > _vector[index])
    {
        long int temp = _vector[parentIndex];
        _vector[parentIndex] = _vector[index];
        _vector[index] = temp;
        BubbleUp(parentIndex);
    }
}

void MinHeap::Insert(long int newValue)
{
    long int length = _vector.size();
    _vector[length] = newValue;

    BubbleUp(length);
}

long int MinHeap::GetMin()
{
    return _vector[0];
}

void MinHeap::DeleteMin()
{
    long int length = _vector.size();

    if(length == 0)
    {
        return;
    }

    _vector[0] = _vector[length-1];
    _vector.pop_back();

    BubbleDown(0);
}

int main(int argc, char const *argv[]) {
    long int a[MAX],count;
    std::cin >> count;
    for (size_t i = 0; i < count; i++) {
      std::cin >> a[i];
    }
    long int i;
    for (i= 0; i < count; i++) {
      if (i> 0 && a[i] < a[i-1]) {
        break;
      }
    }
    if (i==count) {
      std::cout << "0" << '\n';
      return 0;
    }
    MinHeap minHeap(a, count);
    for (std::unordered_map<long int,long int>::const_iterator it=Swapsmap.begin();it!=Swapsmap.end();++it) {
      std::cout << it->second <<" "<<it->first<< '\n';
    }
  return 0;
}
