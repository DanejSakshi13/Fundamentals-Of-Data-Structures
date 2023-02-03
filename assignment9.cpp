/*A palindrome is a string of character that's the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is
in a droop” is a palindrome, as can be seen by examining the characters “poor danisina droop” and observing that they are the same forward and backward. One way to 
check for a palindrome is to reverse the characters in the string and then compare with them the original-if it is a palindrome, the sequence will be identical. 
Write C++ program with functions-
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not*/

#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
#define MAX 50
class stack{
private:
    char data[MAX], str[MAX];
    int top,count,length;
    void pushData(char);
    char popData();
public:
    stack(){
        top = -1;
        length = 0;
        count = 0;
    }
    void getString();
    void checkPalindrome();
    void extractString();
    void displayReverse(); 
};

//input string
void stack:: getString(){
cout<<"Enter the string : ";
cin.getline(str , MAX);
length = strlen(str);
}

void stack::extractString(){
    char temp[MAX];
    int i,j;
    for(int i = 0; i < length; i ++){
        temp[i] = str[i];
    }
    j=0;
    for(int i =0;i<length;i++){
        if(isalpha(temp[i])){
            str[j] = tolower(temp[i]);
            j++;
        }
    }
    length=j;
}

//function to check palindrome
void stack::checkPalindrome(){
    for(int i=0;i<length;i++){
        pushData(str[i]);
    }
    for(int i=0;i<length;i++){
        if(str[i]==popData())
        count++;
    }
    if (count==length){
        cout<<"Entered string is a palindrome.\n";
    }
    else{
        cout<<"Entered string is not a palindrome.\n";
    }
}

//string reversal
void stack::displayReverse(){
    cout<<"Reversed string is :";
    for(int i = length-1 ; i>=0 ; i--){
        cout<<str[i];
    }
}

void stack::pushData(char temp){
    if(top==MAX-1){
        cout<<"Stack overflow.";
        return;
    }
    top++;
    data[top] = temp;
}

char stack::popData(){
    if(top==-1){
        cout<<"Stack underflow";
        char ch = '\n';
        return ch;
    }
    char temp = data[top];
    top--;
    return temp;
}



int main(){
    stack obj;
    obj.getString();
    obj.extractString();
    obj.checkPalindrome();
    obj.displayReverse();
}
