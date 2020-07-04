class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> starting_cells;
        vector<int> current_cells(cells.size(), 0);
        
        // compute the cells for day 1
        for (int i = 1; i < cells.size() - 1; ++i) {
            current_cells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
        }
        starting_cells = current_cells;
        cells = current_cells;

        // decrement N. if it's equal to 0, return cells
        if (--N == 0) return cells;

        auto day = 0;
        do {
            ++day; // increment days
            for (int i = 1; i < cells.size() - 1; ++i) {
                current_cells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            cells = current_cells;
            // the loop will keep going until N == 0 or the current
            // state of the cells is the same as it was on day 1 (there's a cycle)
        } while (--N > 0 && current_cells != starting_cells);

        // if N == 0, we return the cells because we didn't get to the cycle
        if (N == 0) return cells;

        // now that we know how many days are in a cycle
        // we can skip all the cycles and compute the remainder
        N = N % day;
        while (N--) {
            for (int i = 1; i < cells.size() - 1; ++i) {
                current_cells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            cells = current_cells;
        }

        return cells;
    }
};
