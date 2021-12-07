#include "segtree.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Tree::Tree(vector<int> input_array) {
    this->input_array = input_array;
    // Fills up the tree vector with dud values
    for (int i = 0; i < (4*input_array.size()); i ++) {
        tree_array.push_back(-100);
    }
}

Tree::~Tree(){}

void Tree::generate(int tree_index, int low, int high) {
    // Checks if current index is a leaf node and inputs value directly from input array if so
    if (low == high) {
        tree_array[tree_index] = input_array[low];
    } else {
        int midpoint = (low + high) / 2;
        // Recurses down to the left
        generate((tree_index * 2) + 1, low, midpoint);
        // Recurses down to the right
        generate((tree_index * 2) + 2, midpoint + 1, high);
        // Sets node value to sum of its two child nodes as function calls come off of stack
        tree_array[tree_index] = tree_array[(tree_index * 2) + 1] + tree_array[(tree_index * 2) + 2];
    }
}

int Tree::sum(int tree_index, int start, int end, int low, int high) {
    // start -> lower index of current section of tree
    // end   -> upper index of current section of tree
    // low   -> lower index of query interval
    // high  -> upper index of query interval
    
    // Range of node is completely outside given interval
    if (high < start || end < low) {
        return 0;
    }
    // Check if the interval of our query is inside interval of current node
    // If not then continue down the tree
    if (low <= start && end <= high) {
        return tree_array[tree_index];
    }
    int midpoint = (start + end) / 2;
    // Make a recursive call to the left and the right and adds up those values
    return sum((tree_index*2) + 1, start, midpoint, low, high) +
           sum((tree_index*2) + 2, midpoint + 1, end, low, high);
}

void Tree::alter(int tree_index, int start, int end, int pos, int value) {
    
    if (start == end) {
        // function has reached leaf node to be altered
        tree_array[tree_index] = value;
    } else {
        int midpoint = (start + end) / 2;
        if (pos <= midpoint) {
            // recurse down the left side of the tree
            alter((tree_index * 2) + 1, start, midpoint, pos, value);
        } else {
            // recurse down the right side of the tree
            alter((tree_index * 2) + 2, midpoint + 1, end, pos, value);
        }
        // change the values of parent nodes as function calls come off of the stack
        tree_array[tree_index] = tree_array[(tree_index * 2) + 1] + tree_array[(tree_index * 2) + 2];
    }
}

void Tree::display() {
    
    for (int i = 0; i < tree_array.size(); i++) {
        cout << tree_array[i] << ' ';
    }
    cout << endl;
    
}

void Tree::output_to_file() {
    
    
    
}
