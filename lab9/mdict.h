struct Dictionary {
    char *engl;    // слово по-английски
    char *rus;     // слово по-русски
};

int compare(char *word1, char *word2);
void addWord(Dictionary *dict, int &num_w,const char *eng, const char *ru);
void deleteFromDict(Dictionary *dict, int &num_w,const char *eng);
void printDict(Dictionary *dict, int &num_w);
void writeToDict(Dictionary *dict, int &num_w);
void translateFromEnglish(Dictionary *dict, int &num_w,const char *eng);
void translateFromRussian(Dictionary *dict, int &num_w,const char *ru);