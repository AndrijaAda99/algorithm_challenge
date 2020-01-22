#include <iostream>
#include <vector>

using namespace std;

double weight_diff(vector<double>& weights, int k, double target_weight, 
                   double remain_weight, double taken_weights)
{
    if (k == weights.size()) {
        return abs(target_weight - taken_weights);
    }

    
    double min_diff = weight_diff(weights, k + 1, target_weight - weights[k],
                                  remain_weight - weights[k], taken_weights);
    if (taken_weights + remain_weight > taken_weights - min_diff &&
        taken_weights + weights[k] < taken_weights + min_diff) {
        double diff = weight_diff(weights, k + 1, taken_weights, 
                                  remain_weight - weights[k], 
                                  taken_weights + weights[k]);
        if (min_diff > diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}

int main(void)
{
    double target_weight = 8;
    vector<double> weights = {1, 5, 10};

    double remain_weight = 0;
    for (int i = 0; i < weights.size(); i++) {
        remain_weight += weights[i];
    }

    cout << weight_diff(weights, 0, target_weight, remain_weight, 0) << endl;
    
    return 0;
}
