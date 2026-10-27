#include <iostream>

using namespace std;


int main() {
    string s;
    while(cin >> s) {
        int sOldIndex = s.size() - 1;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count ++;
            }  
        }

        s.resize(s.size() + count * 5);
        int sNewIndex = s.size() - 1;
        while(sOldIndex >= 0) {
            if(s[sOldIndex] >= '0' && s[sOldIndex] <= '9') {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            } else {
                s[sNewIndex--] = s[sOldIndex];
            }
            sOldIndex--;
        }
        cout << s << endl;
    }
}