/*vector 建構式.
//default
vector ();

//fill
    n  :塞幾個.
    val:塞什麼，可以不放，那就是該型態的初始值.
vector (size_type n, const value_type& val = value_type());


//range 把從first到last的內容都複製過來.
    InputIterator: iterator 的型態.
    區間:[first,last)
template <class InputIterator>
vector (InputIterator first, InputIterator last);


//copy 複製另一個vector
vector (const vector& x);
*/

#include <iostream>
#include <vector>
using namespace std;

int main ()
{
// 4種建構式.
    vector<int> first;                                // default
    vector<int> second (4,100);                       // fill
    vector<int> third (second.begin(),second.end());  // range
    vector<int> fourth (third);                       // copy

    // range : 可以把iterator想像成指標.
    int myints[] = {16,2,77,29};
    vector<int> fifth (myints, myints + 4 );

    cout << "fifth的內容:";
    for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

//4種iterator
/*      r = reverse (反轉)
    iterator begin()    :回傳 第一個元素的 iterator
    iterator end()      :回傳 最後一個元素的 iterator + 1
    iterator rbegin()   :回傳 最後一個元素的 iterator
    iterator rend()     :回傳 第一個元素的 iterator - 1
*/
    vector<int>::iterator iter = fifth.begin();
    cout<<"fifth的第一個元素"<< *iter    <<'\n';
    cout<<"fifth的第三個元素"<< *(iter+2)<<'\n';
    cout<<"fifth的最後一個的後面一個元素"<< *(fifth.end())<<'\n';

//容器的容量.
    cout<<"fifth的元素數量"<<fifth.size()<<'\n';
    cout<<"fifth是否是空的"<<fifth.empty()<<'\n';//1:true 0:false

//內容查訪.
    cout<<"fifth的第2個元素" << fifth[1]<<'\n';
    cout<<"fifth的第2個元素" << fifth.at(1)<<'\n';
    cout<<"fifth的第1個元素" << fifth.front()<<'\n';
    cout<<"fifth的最後個元素"<< fifth.back()<<'\n';

    //回傳值都是左值(傳參考).
    fifth[1]=100;
    fifth.at(2)=200;
    fifth.front()=0;
    fifth.back()=300;

    //fifth更新後.
    cout<<"更改後的新fifth:";
    for(auto each : fifth)  //這個for迴圈是C++11的標準，CPE好像不能用 可悲CPE 跟不上時代.
        cout<<each<<' ';    //C++11是2011年出的，現在已經2017了.
    cout<<endl;

//其他成員函式

//assign() 跟建構式的用法一樣
    first.assign(10,0);
    second.assign(fifth.rbegin(),fifth.rend());
    cout<<"更改後的新first:";
    for(auto each : first)  cout<<each<<' '; cout<<endl;
    cout<<"更改後的新second:";
    for(auto each : second) cout<<each<<' '; cout<<endl;

//push_back() 在尾端加入新元素
    second.push_back(999);
    cout<<"更改後的新second:";
    for(auto each : second) cout<<each<<' '; cout<<endl;

//pop_back()
    second.pop_back();
    cout<<"更改後的新second:";
    for(auto each : second) cout<<each<<' '; cout<<endl;

//insert(iterator position, T val)
//從 position 的位置插入一個 val
    first.insert(first.begin()+5, 87);
    cout<<"更改後的新first:";
    for(auto each : first) cout<<each<<' '; cout<<endl;


//insert(iterator position, size_t n, T val)
//從 position 的位置插入 n 個 val
    first.insert(first.begin()+3, 5, 1);
    cout<<"更改後的新first:";
    for(auto each : first) cout<<each<<' '; cout<<endl;

//insert(iterator position, iterator first, iterator last)
//從 position 的位置插入 first 到 last 的內容
    first.insert(first.begin(),fifth.begin(),fifth.end());
    cout<<"更改後的新first:";
    for(auto each : first) cout<<each<<' '; cout<<endl;

//刪除
//iterator erase(iterator position)
//把 position 位置的元素移除，並回傳原本指向位置的後一個
    iter = fifth.erase(fifth.end()-1);
    for(auto each : fifth) cout<<each<<' '; cout<<endl;
    cout<<(iter==fifth.end())<<endl;//iter會指向fifth.end()


//iterator erase(iterator first, iterator last)
    iter = first.erase(first.begin(), first.begin()+5);//把前5個刪掉
    for(auto each : first) cout<<each<<' '; cout<<endl;
    cout<<*iter<<endl;


//互換
//swap(vector x) 把兩個 vector 互換
    cout<<"原本的 first: ";
    for(auto each : first)cout<<each<<' ';cout<<endl;
    cout<<"原本的 second: ";
    for(auto each : second)cout<<each<<' ';cout<<endl;

    first.swap(second);

    cout<<"互換後的 first: ";
    for(auto each : first)cout<<each<<' ';cout<<endl;
    cout<<"互換後的 second: ";
    for(auto each : second)cout<<each<<' ';cout<<endl;

//清空
//clear() 把 vector 清空
    first.clear();

    cout<<"清空後的 first: ";
    for(auto each : first)cout<<each<<' ';cout<<endl;


    return 0;
}
