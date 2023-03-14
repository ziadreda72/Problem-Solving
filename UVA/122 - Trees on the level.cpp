#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

pair < string , i64 > parse(string s){
    string path = "" , num = "";
    pair < string , i64 > ret = {"" , -1};
    int i = 1;
    while (i < (int) s.size() && s[i] != ',') num += s[i++];
    if(num.empty()){
        return ret;
    }
    i++;
    while (i < (int) s.size() && s[i] != ')') path += s[i++];
    bool ok = true;
    for(auto c : path){
        if(c != 'L' && c != 'R') ok = false;
    }
    if(ok){
        ret = {path , stoll(num)};
    }
    return ret;
}

bool check(pair < string , i64 > node){
    return node.S != -1;
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    string s;
    vector < string > v;
    while (cin >> s){
        v.clear();
        v.emplace_back(s);
        while (cin >> s && s != "()") v.emplace_back(s);
        vector < pair < string , i64 > > nodes;
        bool ok = true;
        for(auto x : v){
            pair < string , i64 > node = parse(x);
            ok &= check(node);
            if(ok) nodes.emplace_back(node);
        }
        if(!ok){
            cout << "not complete\n";
        }else{
            map < string , int > mp;
            int mx = -100;
            for(auto [path , n] : nodes){
                mp[path]++;
                mx = max(mx , (int) path.size());
            }
            for(auto [path , cnt] : mp){
                if(cnt > 1){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                cout << "not complete\n";
                continue;
            }
            vector < int > cnt(mx + 1 , 0);
            for(auto [path , _] : mp){
                int x = (int) path.size();
                cnt[x]++;
            }
            ok = cnt[0] == 1;
            for (int i = 1; i <= mx ; ++i) {
                ok &= (0 < cnt[i] && cnt[i] <= 2 * cnt[i - 1]);
            }
            if(!ok){
                cout << "not complete\n";
                continue;
            }
            sort(nodes.begin(), nodes.end() , [](pair < string , int > a , pair < string , int > b){
                if((int) a.F.size() == (int) b.F.size()){
                    return a.F < b.F;
                }
                return (int) a.F.size() < (int) b.F.size();
            });
            for (int i = 0; i < (int) nodes.size(); ++i) {
                cout << nodes[i].S;
                if(i != (int) nodes.size() - 1) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
