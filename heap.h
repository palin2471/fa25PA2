//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx; //Insert element at end
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size==0) return -1; //Conditional if empty

        int smallest = data[0]; //Copy root (smallest index)
        data[0] = data[size-1]; //Replace
        size--;

        downheap(0, weightArr); //Downheap to restore heap order
        return smallest;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) //Guarantees position is not at the root
        {
            int par = (pos-1)/2; //Stores parent value
            if (weightArr[data[par]] > weightArr[data[pos]]) //Conditional when parent > child
            {
                swap(data[par], data[pos]);
                pos = par;
            } else
            {
                return; //Stops when parent is smaller
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true)
        {
            int left = (pos*2)+1;
            int right = (pos*2)+2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) //Compare left child
            {
                smallest = left;
            }

            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) //Compare right child
            {
                smallest = right;
            }

            if (smallest != pos) //If child is smaller, swap
            {
                swap(data[pos], data[smallest]);
                pos = smallest; //Moves down
            } else
            {
                return;
            }
        }
    }
};

#endif