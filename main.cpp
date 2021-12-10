#include "segtree.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
    
    ifstream data;
    data.open(argv[1]);
    string line;
    vector<vector<int>> input_data;
    
    // Read in each line from the input file and store values in a vector and place those into a 2D vector
    // The first line is the input array of the segment tree and consecutive lines are query/alter requests
    while (getline(data, line)) {
        istringstream ss(line);
        string num;
        vector<int> temp;
        while (ss >> num) {
            temp.push_back(stoi(num));
        }
        input_data.push_back(temp);
    }
    
    Tree Segment_Tree(input_data[0]);
    Segment_Tree.generate(0, 0, input_data[0].size() - 1);
    
    int sum_value;
    
    // Execute the query and alter requests
    for (int i = 1; i < input_data.size(); i++) {
        if (input_data[i][0] == 0) {
            // 0 indicates a query request
            sum_value = Segment_Tree.sum(0, 0, input_data[0].size() - 1, input_data[i][1], input_data[i][2]);
            cout << "Sum from position " << input_data[i][1] << " to " << input_data[i][2] << " is " << sum_value << endl;
        } else {
            Segment_Tree.alter(0, 0, input_data[0].size() - 1, input_data[i][1], input_data[i][2]);
            cout << "Altered value at position " << input_data[i][1] << " to be " << input_data[i][2] << endl;
            // 1 indicates an alter request
        }
    }
    
    // Output completed tree to file
    Segment_Tree.output_to_file();
    
}
