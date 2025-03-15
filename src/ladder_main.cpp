#include "ladder.h"

int main() {
    string dict_file, start_word, end_word;

    cout << "Enter dictionary file name: ";
    cin >> dict_file;

    cout << "Enter start word: ";
    cin >> start_word;

    cout << "Enter end word: ";
    cin >> end_word;

    if (start_word == end_word) 
    {
        cerr << "Error: Start and end words must be different (" << start_word << " -> " << end_word << ")\n";
        return 1;
    }

    set<string> word_list;
    load_words(word_list, dict_file);

    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);

    return 0;
}