#include<bits/stdc++.h>
using namespace std;
stack<string>Back,Front;

void Clear(){
    while(!Back.empty())Back.pop();
    while(!Front.empty())Front.pop();
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int tc, cs, i;
    cin >> tc;getchar();
    for(cs = 1; cs <= tc; cs++){
        Clear();
        cout << "Case " << cs << ":" << endl;
        string command, url, Top;
        url = Top = "http://www.lightoj.com/";
        while(cin >> command){
            if(command=="QUIT")break;
            else if(command=="BACK"){
                if(!Back.empty()){
                    Front.push(Top);
                    Top = Back.top();
                    Back.pop();
                    cout << Top << endl;
                }
                else cout << "Ignored" << endl;
            }
            else if(command=="FORWARD"){
                if(!Front.empty()){
                    Back.push(Top);
                    Top = Front.top();
                    Front.pop();
                    cout << Top << endl;
                }
                else cout << "Ignored" << endl;
            }
            else if(command=="VISIT"){
                Back.push(Top);
                cin >> url;
                Top = url;
                cout << Top << endl;
                while(!Front.empty())Front.pop();
            }
        }
    }

    return 0;
}
