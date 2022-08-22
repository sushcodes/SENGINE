#include<bits/stdc++.h>
using namespace std;
vector <char> Characters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
struct Trie{
    map < char , Trie* > children;
    bool found; // tells if a word ends here or not
    Trie(){
        found = false;
    }
};
void insert(Trie *&root, string s){
    if(root==NULL){
        root = new Trie();
    }
    Trie *temp = root;
    for(int i = 0;i<s.size();i++){
        if(temp->children[s[i]]==NULL){
            temp->children[s[i]] = new Trie();
        }
        temp = temp->children[s[i]];
    }
    temp->found = true;
}
bool search(Trie *root, string s){
    for(int i = 0;i<s.size();i++){
        if(root->children[s[i]]==NULL) return false;
        root = root->children[s[i]];
    }
    if(root and root->found) return true;
    return false;
}

void FindSuggestion(string currentString,Trie *root,vector <string> &response){
    bool found = false;
    for(char c : Characters){
        if(root->children[c]){
            found = true;
        }
    }
    if(root->found){
        response.push_back(currentString);
    }
    if(found==false){
        return ;
    }
    for(char c : Characters){
        if(root->children[c]){
            FindSuggestion(currentString+c,root->children[c],response);
        }
    }
}
void finder(string &s , Trie *root , vector <string> &response ){
       
        for(char c : s){
        if(root->children[c]==NULL){
            return;
        }
        root = root->children[c];
    }

    FindSuggestion(s,root,response);
    
}
int main(){
    Trie *root = new Trie();
    cout<<"ENTER THE NUMBER OF STRINGS YOU WANT TO STORE IN TEMPORARY DATABASE"<<endl;
    int n;
    cin >> n;
    string s;
    getline(cin,s);
    if (n)
    cout<<"ENTER "<<n<<" Strings "<<endl;
    while(n--){
        
        getline(cin,s);
        insert(root,s);
    }

cout<<endl;
cout<<"##.........................................................................................##"<<endl;
cout<<"##.........................................................................................##"<<endl;
cout<<"##............................ INTERNALLY IMPLEMENTED AS TRIE .............................##"<<endl;
cout<<"##.........................................................................................##"<<endl;
cout<<"##.........................................................................................##"<<endl;
cout<<endl;


    cout<<"ENTER NUMBER OF QUERIES "<<endl;
    int q;
    cin >> q;
    cin.clear();
fflush(stdin);
    while(q--){
        cout<<"ENTER THE SEARCH STRING"<<endl;
cout<<endl;
        getline(cin,s);
        vector <string> Suggestion;
        Suggestion.clear();
        finder(s ,  root , Suggestion);
        int i=0;
        if (Suggestion.size()>0 && Suggestion[0]==s)
{

cout<<"CONCLUSION -> THIS KEYWORD IS PRESENT IN DATABASE "<<endl;
i++;
if (Suggestion.size()>1)
cout<<"BELOW ARE SIMILAR WORDS"<<endl;
cout<<endl;
}
else if (Suggestion.size()!=0)
{
cout<<"CONCLUSION -> KEYWORD IS NOT PRESENT IN DATABASE "<<endl;
}
else
{
}
        if(Suggestion.size()==0){
            cout << "CONCLUSION -> Oops Word Not Found \n";
        } else {
            if (i==0)
            cout << "Do You Mean ?" << endl <<endl;
            for (i;i<Suggestion.size();i++)
cout<<Suggestion[i]<<endl;
            }
cout<<endl;
cout<<"####.........................................................................................####"<<endl;
cout<<endl;
    }
cin.clear();
fflush(stdin);
cout<<"ENTER ANY KEY TO CLOSE"<<endl;
getchar();
}
