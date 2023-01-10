#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string, int> umap;

    //insert
    pair<string,int> p("abc",1);
    umap.insert(p);
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

    //find or access
    cout<<umap["abc"]<<endl;
    cout<<umap.at("abc")<<endl;

    //check if present
    if(umap.count("abc"))
        cout<<"abc is present"<<endl;
    else
        cout<<"abc is not present"<<endl;
    //erase
    umap.erase("abc");
    for (auto x : umap)
        cout << x.first << " " << x.second << endl;
    return 0;
} 