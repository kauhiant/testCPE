#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int main ()
{
/*
    constructor
*/
  string s0("Initial string");  //"Initial string"
  string s1;                    //""
  string s2(s0);                //"Initial string"
  string s3(s0, 8, 3);          //"str"
  string s4("A character sequence");            //"A character sequence"
  string s5("Another character sequence", 12);  //"Another char"
  string s6a (10, 'x');         //"xxxxxxxxxx"
  string s6b (10, 42);          //"**********"
  string s7(s0.begin(), s0.begin()+7);          //"Initial"
/*
    iterator like other container
    begin(),end(),rbegin(),rend()
*/
    for(string::reverse_iterator iter = s0.rbegin(); iter != s0.rend(); ++iter)
        cout<<*iter;
    cout<<endl;

/*
    size(),length() are same thing
*/
    cout<<"size of s0:"<<s0.size()<<endl;

/*
    void resize (size_t n);
    void resize (size_t n, char c);
*/
    s0.resize(5);
    cout<<"s0.resize(5):"<< s0 <<endl;
    s0.resize(10,'*');
    cout<<"s0.resize(10,'*'):"<< s0 <<endl;

/*
    void clear();
    bool empty() const;
*/
    s2.clear();
    cout<<"s2 is empty? " << s2.empty() <<endl;

/*
    char& operator[] (size_t pos);
    char& at (size_t pos);
*/
    cout<<"s4 : " << s4 << endl;
    for(int i=0; i<s4.size(); ++i)
        if(s4[i] == ' ')
            s4.at(i) = '_';
    cout<<"new s4 : "<< s4 <<endl;

/*
    string& operator+= (const string& str);
    string& operator+= (const char* s);
    string& operator+= (char c);
    string& append (const string& str);
    string& append (const char* s);
    string& append (size_t n, char c);

    string& append (const string& str, size_t subpos, size_t sublen);
    string& append (const char* s, size_t n);

    template <class InputIterator>
        string& append (InputIterator first, InputIterator last);
*/
    s1.append("Hello");
    s1.append(s1);
    s1.append(4,' ');
    s1.append(s5, 5, 10);
    cout<<s1<<endl;

/*
    void push_back (char c);
    like vector
*/

/*
    assign(...) like constructor
*/

/*
    string& insert (size_t pos, ... )
*/
    s2.clear();
    s2.assign("abcdefg");
    s2.insert(3,"thisIs3");
    cout<< "s2 : " << s2 << endl;

/*
    string&  erase (size_t pos = 0, size_t len = npos);
    iterator erase (iterator p);
    iterator erase (iterator first, iterator last);
*/
    cout<<"s1: "<<s1<<endl;
    for(int i=0; i<s1.length(); ++i){
        if(s1.at(i) == 'l'){
            s1.erase(i--,1);
        }
    }
    cout<<"s1: "<<s1<<endl;


/*
    string& replace (size_t pos,  size_t len,  const string& str);
    string& replace (size_t pos,  size_t len,  const string& str, size_t subpos, size_t sublen);
    string& replace (size_t pos,  size_t len,  const char* s);
    string& replace (size_t pos,  size_t len,  const char* s, size_t n);
    string& replace (size_t pos,  size_t len,  size_t n, char c);

    string& replace (iterator i1, iterator i2, const string& str);
    string& replace (iterator i1, iterator i2, const char* s);
    string& replace (iterator i1, iterator i2, const char* s, size_t n);
    string& replace (iterator i1, iterator i2, size_t n, char c);
*/
    cout<<"s5: "<<s5<<endl;
    s5.replace(3,5,"000000");
   /* s5.erase(3,5);
    s5.insert(3,"000000");*/
    cout<<"s5: "<<s5<<endl;

/*  other
    const char* c_str() const;  // end of '\0'
    const char* data() const;   // contain all char

    string substr (size_t pos = 0, size_t len = npos) const;

    size_t find (const string& str, size_t pos = 0) const;
    size_t find (const char* s, size_t pos = 0) const;
    size_t find (const char* s, size_t pos, size_t n) const;
    size_t find (char c, size_t pos = 0) const;

*/

  return 0;
}
