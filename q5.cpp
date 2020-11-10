#include <bits/stdc++.h>

using namespace std;
int calculateMinimumSession(int nb, int np, vector<vector<int>> bp, vector<vector<int>> pp) {
    set<pair<int,int>> s;
    for(int i=0;i<nb;i++){
        for(auto v: bp[i])
        s.insert(make_pair(i+1,v));
    }
    for(int i=0;i<np;i++){
        for(auto v: pp[i])
        s.insert(make_pair(v,i+1));
    }
    int a=0,b=0,c;
    for(auto x:s){
        // cout<<x.first<<" "<<x.second<<"\n";
        if(a==0){
            a++;
            b=max(a,b);
            c = x.first;
        }else{
            if(c == x.first){
                a++;
                b=max(a,b);
            }else{
                b=max(a,b);
                a=1;
                c=x.first;
            }
        }
    }
    s.clear();
    for(int i=0;i<nb;i++){
        for(auto v: bp[i])
        s.insert(make_pair(v,i+1));
    }
    for(int i=0;i<np;i++){
        for(auto v: pp[i])
        s.insert(make_pair(i+1,v));
    }
    int a1=0,b1=0,c1;
    for(auto x:s){
        // cout<<x.first<<" "<<x.second<<"\n";
        if(a1==0){
            a1++;
            b1=max(a1,b1);
            c1 = x.first;
        }else{
            if(c1 == x.first){
                a1++;
                b1=max(a1,b1);
            }else{
                b1=max(a1,b1);
                a1=1;
                c1=x.first;
            }
        }
    }
    // Participant's code will go here
    return max(b,b1);
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
    int numOfBankers, numOfParticipants;
    vector<vector<int>> bankersPreferences, participantsPreferences;

    cin >> numOfBankers;

    string bankersPreferencesStr;
    cin >> bankersPreferencesStr;
    vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

    for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin(); i != bankersPreferencesVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
        bankersPreferences.push_back(bankerPreferenceVecByAnd);
    }

    string participantsPreferencesStr;
    cin >> numOfParticipants;
    cin >> participantsPreferencesStr;
    vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

    for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin(); i != participantsPreferencesVecByComma.end(); ++i) {
        vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
        participantsPreferences.push_back(participantPreferenceVecByAnd);
    }

    int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}

// 90/90 test cases successful