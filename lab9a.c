
char* removeDuplicateLetters(char* s) {

    int freq[26] = {0};
    int visited[26] = {0};

    int n = strlen(s);

    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;

    for(int i = 0; i < n; i++) {

        char ch = s[i];

        freq[ch - 'a']--;

        if(visited[ch - 'a'])
            continue;

        while(top >= 0 &&
              result[top] > ch &&
              freq[result[top] - 'a'] > 0) {

            visited[result[top] - 'a'] = 0;
            top--;
        }

        result[++top] = ch;
        visited[ch - 'a'] = 1;
    }

    result[top + 1] = '\0';

    return result;
}
