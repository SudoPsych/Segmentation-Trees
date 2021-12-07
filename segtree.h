#include <vector>
#include <utility>
using namespace std;

class Tree {
    
    private:
        
        vector<int> input_array;
        vector<int> tree_array;
        
    public:
        
        // Constructor
        Tree(vector<int> input_array);
        // Destructor
        ~Tree();
        
        // Generate the values for the segment tree to be stored into seg_array
        void generate(int tree_index, int low, int high);
        // Recursive function that returns sum in a given interval
        int sum(int tree_index, int start, int end, int low, int high);
        // Change value at pos to val (also recursive)
        void alter(int tree_index, int start, int end, int pos, int value);
        // Outputs the completed tree to a dot file
        void output_to_file();
        void display();
        
};