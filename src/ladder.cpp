#include "ladder.h"

bool is_adjacent(const string& word1, const string& word2) 
{
    int len1 = word1.length(), len2 = word2.length();
    if (abs(len1 - len2) > 1) 
        return false;

    int diff_count = 0;
    int i = 0, j = 0;

    while (i < len1 && j < len2) 
    {
        if (word1[i] != word2[j]) 
        {
            if (++diff_count > 1) 
                return false; 
            if (len1 > len2) 
                ++i;
            else if (len1 < len2) 
                ++j;
            else { 
                ++i; 
                ++j; 
            }
        } else {
            ++i; 
            ++j;
        }
    }

    return true;
}

void load_words(set<string>& word_list, const string& file_name) 
{
    ifstream file(file_name);
    if (!file) 
    {
        cerr << "Error: Unable to open file " << file_name << endl;
    }
    
    string word;
    while (file >> word) 
    {
        word_list.insert(word);
    }
    file.close();
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) 
{
    queue<vector<string>> ladder_queue;
    set<string> visited;

    ladder_queue.push({begin_word});
    visited.insert(begin_word);

    while (!ladder_queue.empty()) 
    {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const string& word : word_list) 
        {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) 
            {
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);
                visited.insert(word);

                if (word == end_word) 
                    return new_ladder;
                ladder_queue.push(new_ladder);
            }
        }
    }

    return {};
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length(), len2 = str2.length();
    if (abs(len1 - len2) > d) 
        return false;

    int diff_count = 0;
    int i = 0, j = 0;

    while (i < len1 && j < len2) 
    {
        if (str1[i] != str2[j]) 
        {
            if (++diff_count > d) 
                return false;
            if (len1 > len2) 
                ++i;
            else if (len1 < len2) 
                ++j;
            else { 
                ++i; 
                ++j; 
            } 
        } else {
            ++i; 
            ++j;
        }
    }

    return diff_count <= d;
}


void print_word_ladder(const vector<string>& ladder) 
{
    if (ladder.empty()) 
    {
        cout << "No word ladder found." << endl;
    } 
    else {
        for (size_t i = 0; i < ladder.size(); ++i) 
        {
            cout << "Word ladder found: ";
            cout << ladder[i];
            if (i + 1 < ladder.size()) 
                cout << " ";
        }
        cout << endl;
    }
}
