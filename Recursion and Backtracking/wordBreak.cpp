bool isValidWord(string &s, vector<string> &dictionary){
    for(auto &word : dictionary){
        if(s == word){
            return true;
        }
    }
    return false;
}

void recursion(int i, int n, string &s, vector<string> &dictionary, vector<string> &words, string word = ""){
    if(i == n){
        word = word.substr(1, word.size() - 1);
        words.push_back(word);
        return;
    }
    string str = "";
    for(int ind = i; ind < n; ind++){
        str += s[ind];
        if(isValidWord(str, dictionary)){
            recursion(ind + 1, n, s, dictionary, words, word + " " + str);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    int n = s.size();
    vector<string> words;
    recursion(0, n, s, dictionary, words);
    return words;
}
