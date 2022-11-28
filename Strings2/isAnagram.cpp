bool isAnagram(string s, string t) {
    vector<int> hashTable(26, 0);
    for(auto c : s){
        hashTable[c - 'a']++;
    }
    for(auto c : t){
        hashTable[c - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(hashTable[i] != 0){
            return false;
        }
    }
    return true;
}
