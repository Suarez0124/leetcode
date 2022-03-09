#include <iostream>
#include <vector>


using namespace std;

class Solution{
public:
    void reverseString(vector<char>& s){
        int i=0 , j=s.size()-1;
        while(i < j){
            swap(s[i++] , s[j--]);
        }
    }
};


int main()
{
    vector<char> obj;
    obj.push_back('h');
    obj.push_back('e');
    obj.push_back('l');
    obj.push_back('l');
    obj.push_back('o');

    Solution app;
    app.reverseString(obj);
    for(int i=0; i<obj.size(); i++){
        cout << obj[i] << endl; 
    }

    return 0;
}