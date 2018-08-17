class Solution {
public:
    /**
     * @param sentence: a list of string
     * @param rows: an integer
     * @param cols: an integer
     * @return: return an integer, denote times the given sentence can be fitted on the screen
     */
    int wordsTyping(vector<string> sentence, int rows, int cols) {
        // Write your code here
        int x = 0, an = 0, cursor = 0;
        while (x < rows) {
            int y = 0;
            while (((int) sentence[cursor].size()) <= cols - y) {
                y += sentence[cursor++].size() + 1;
                if (cursor == sentence.size()) {
                    an++;
                    cursor = 0;
                }
            }
            x++;
        }
        return an;
    }
};
