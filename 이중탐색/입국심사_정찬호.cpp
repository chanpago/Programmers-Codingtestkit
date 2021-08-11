#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdint.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long  num;
    long long count = 0;
    long long left = 0, right = 0, mid = 0;
    sort(times.begin(),times.end());
    for (int i = 0;i < times.size();i++) {
        num = times[i];
        //cout << num;
        left = 1;
        right = 1000000000;
        while (left<=right) {
            mid = (right + left) / 2;
            //cout << mid;
            for (int j = 0;j < times.size();j++) {
                count =count+ ((mid*num) / times[j]);
            }
            //cout << count;
            if (count < n) {
                left = mid + 1;
                //cout << 2;
            }
            else if (count == n) {
                answer = mid*num;
                //cout << 3;
                break;
            }
            else if(count>n){
                right = mid - 1;
                //cout << 1;
            }
            count = 0;
        }
        if (answer != 0) { break; }
    }
    

    return answer;
}
