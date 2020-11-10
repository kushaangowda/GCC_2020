#include <bits/stdc++.h>

using namespace std;
string findSuspiciousUserId(int n, vector<vector<int>> v) {
    set <int> s,r;
    int a[n+1][n+1]={0},c,d;
    for(int i=0;i<n;i++){
        r.insert(i+1);
        for(int j=1;j<v[i].size();j++)
        {
            a[v[i][0]][v[i][j]]=1;
            if(a[v[i][j]][v[i][0]]){
                s.insert(v[i][j]);
                s.insert(v[i][0]);
                r.erase(v[i][j]);
                r.erase(v[i][0]);
            }
        }
    }
    do{
        d=0;
        for(auto i:r){
            c=0;
            for(auto x:s){
                if(a[i][x])
                c++;
                if(c==2)
                {
                    d=1;
                    s.insert(i);
                    r.erase(i);
                    break;
                }
            }
            if(d){
                break;
            }
        }
    }while(d);
    string ans = "";
    for(auto x:s){
        if(ans == ""){
            ans = to_string(x);
        }else{
            ans += ","+to_string(x);
        }
    }
    // Participant's code will go here
    return ans;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    int numOfQuestions = strtol(firstLine.c_str(), NULL, 10);;

    string questionAndAnswerStr;
    getline(cin, questionAndAnswerStr);

    vector<vector<int>> questionAndAnswerVecOfVec;
    vector<string> questionAndAnswerVecByComma = split(questionAndAnswerStr, ',');

    for (vector<string>::const_iterator i = questionAndAnswerVecByComma.begin(); i != questionAndAnswerVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, ' ');
        questionAndAnswerVecOfVec.push_back(bankerPreferenceVecByAnd);
    }

    string result = findSuspiciousUserId(numOfQuestions, questionAndAnswerVecOfVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}

// 90/90 test cases successful