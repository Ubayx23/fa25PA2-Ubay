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
        //[Inserts] new node index into heap and calls on upheap to maintain order
        data[size] = idx;
        size++;
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        //[Helper function] moves the node upward until order property is restored
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        //[Helper function] moves the node downward until order property is restored
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int small = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[small]]) {
                small = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[small]]) {
                small = right;
            }

            if (small != pos) {
                swap(data[pos], data[small]);
                pos = small;
            }
            else {
                break;
            }
        }
    }
};

#endif