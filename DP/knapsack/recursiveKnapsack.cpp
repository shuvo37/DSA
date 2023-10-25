#include <iostream>
#include <vector>

using namespace std;
struct Item {
    int weight;
    int value;
};

int knapsackRecursive(int W, const vector<Item>& items, int n) {
    if (n == 0 || W == 0)
        return 0;
    if (items[n - 1].weight > W)
        return knapsackRecursive(W, items, n - 1);

    int includeItem = items[n - 1].value +
     knapsackRecursive(W - items[n - 1].weight, items, n - 1);
    int excludeItem = knapsackRecursive(W, items, n - 1);
    return max(includeItem, excludeItem);
}

int main() {
    int W; 
    int n;  

  
    cin >> W;

    
    cin >> n;

    vector<Item> items(n);

   
    for (int i = 0; i < n; ++i) {
      
     
        cin >> items[i].weight;
     
        cin >> items[i].value;
    }

    int maxValue = knapsackRecursive(W, items, n);

    cout << maxValue << endl;

    return 0;
}