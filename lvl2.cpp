#include <iostream>
#include <vector>
using namespace std;

class IntervalMerger{
private:
    vector<pair<int, int>> intervals; //Stores merged intervals

public:
    void addInterval(int start, int end){
        vector<pair<int, int>> newIntervals;
        bool inserted = false;

        for(const auto& interval : intervals){
            if(end < interval.first) { //New interval comes before current interval
                if(!inserted) {
                    newIntervals.push_back({start, end});
                    inserted = true;
                }
                newIntervals.push_back(interval);
            } 
            else if(start > interval.second){ // New interval comes after current interval
                newIntervals.push_back(interval);
            } 
            else{ // Overlapping intervals, merge them
                start = min(start, interval.first);
                end = max(end, interval.second);
            }
        }
        if(!inserted){
            newIntervals.push_back({start, end});
        }
        intervals = newIntervals; // Update intervals with merged ones
    }

    vector<pair<int, int>> getIntervals(){
        return intervals;
    }

    void displayIntervals(){
        cout << "[ ";
        for (const auto& interval : intervals) {
            cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        cout << "]" << endl;
    }
};

int main(){
    IntervalMerger merger;
    merger.addInterval(1, 5);
    merger.addInterval(6, 8);
    cout << "Merged Intervals: ";
    merger.displayIntervals();
    merger.addInterval(4, 7);
    cout << "Merged Intervals: ";
    merger.displayIntervals(); // Expected Output: [[1, 8]]

    return 0;
}
