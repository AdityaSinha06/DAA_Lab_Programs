#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cout << "Input the number of Jobs: ";
    cin >> n;

    cout << "Input the deadline and profit for each job: \n";
    vector<int> deadlines(n) , profit(n);
    for(int i=0; i<n; i++) {
        cout << "Input deadline & profit for " << i+1 << "th Job:";
        cin >> deadlines[i] >> profit[i];
    }

    cout << "Given Input: \n" ;
    for(int i=0; i<n; i++) {
        cout << i+1 << ":" << deadlines[i] << " " << profit[i] << '\n';
    }


    vector<pair<int , int>> vec(n);
    for(int i=0; i<n; i++) {
        vec[i] = {profit[i] , deadlines[i]};
    }

    sort(vec.begin() , vec.end() , [](auto a , auto b) {
        if(a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    });

    int maxDeadline = *max_element(deadlines.begin() , deadlines.end());
    vector<int> appointments(maxDeadline+1 , -1);

    for(int i=0; i<n; i++) {
        int day = vec[i].second;

        while(day >= 1 && appointments[day] != -1) --day;
        if(day >= 1) appointments[day] = i;
    }

    cout << "Job's Sub-Sequence : " ;
    for(auto jobs : appointments) {
        if(jobs!= -1) cout << jobs+1 << " ";
    }

    return 0;
}