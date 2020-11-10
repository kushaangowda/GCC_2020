#include <bits/stdc++.h>

using namespace std;

string encrypt(string word, int length) {
    int len=0;
    char words[length], answer[100000];
    for(int i=0;i<word.length();i++){
        if(word[i]!=' '){
            words[len] = word[i];
            len++;
        }
    }
    // words[len] = '\0';
    //cout<<words.length();
    int r,c;
    r = sqrt(len);
    c = r;
    if(r*r!=len)
    c++;
    if(r*c<len)
    r++;
    //cout<<r<<" "<<c<<"\n";
    int rem = 0,i=0,k;
    while(rem<c){
        k=rem;
        while(k<len){
            answer[i] = words[k];
            i++;
            k+=c;
        }
        answer[i] = ' ';
        i++;
        rem++;
    }
    answer[i-1] = '\0';
    return answer;
}


int main() {
    string words;
    getline(cin, words);

    string result = encrypt(words, words.length());

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}

// 90/90 test cases successful