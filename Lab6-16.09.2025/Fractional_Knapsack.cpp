#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cout << "Input the number of items: ";
    cin >> n;

    vector<int> value(n) , weight(n);
    for(int i=0; i<n; i++) {
        cout << "Input value and weight of " << i+1 << "th item: ";
        cin >> value[i] >> weight[i];
    }

    int capacity; cout << "Input the knapsack capacity: ";
    cin >> capacity;

    cout << "Given Values: ";
    for(int i=0; i<n; i++) {
        cout << i+1 <<" " << value[i] << " " << weight[i] << '\n';
    }

    //since, we've got a constraint on the amount of weight we can pick :> we'll pick the most valuable a/c weight
    //item first 

    //{val/wt , idx}
    vector<pair<double , int>> vec(n);
    for(int i=0; i<n; i++) {
        vec[i] = {(double)value[i]/weight[i] , i};
    }

    sort(vec.begin() , vec.end() , [](auto a , auto b) {
        return a.first > b.first;
    });

    double totalValue = 0;
    int currCapacity = capacity;
    for(int i=0; i<n; i++) {
        int currIdx = vec[i].second;
        
        if(currCapacity - weight[currIdx] >= 0) {
            totalValue += value[currIdx];
            currCapacity -= weight[currIdx];
        } else {
            if(currCapacity == 0) break;

            totalValue += vec[i].first * value[currIdx];
            currCapacity = 0;
        }
    }

    cout << totalValue;
 

}