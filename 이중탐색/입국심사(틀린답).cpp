#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdint.h>

using namespace std;


bool check(vector<int> times,int a){
    for(int i=0;i<times.size();i++){
       if(a%i==0){return true;}
    }
    return false;
}


long long solution(int n, vector<int> times) {
    long long answer1 = 0,answer2=0,answer=0;
    long long  num;
    long long count = 0;
    long long left = 0, right = 0, mid = 0;
    sort(times.begin(),times.end());
    left = 0;
    right = 1000000001;
    while (left<=right) {
        mid = (right + left) / 2;
        //cout << mid;
        for (int j = 0;j < times.size();j++) {
            count =count+ (mid / times[j]);
        }
        //cout << count;
        if (count == n-1) {
            answer1 = mid;
            //cout << 3;
            break;
        }
        else if (count < n-1) {
            left = mid + 1;
            //cout << 2;
        }

        else if(count>=n){
            right = mid - 1;
            //cout << 1;
        }
        count = 0;
    }
    count=0;
    left = 0;
    right = 1000000001;
    while (left<=right) {
        mid = (right + left) / 2;
        //cout << mid;
        for (int j = 0;j < times.size();j++) {
            count =count+ (mid / times[j]);
        }
        //cout << count;
        if (count == n) {
            answer2 = mid;
            //cout << 3;
            break;
        }
        else if (count < n) {
            left = mid + 1;
            //cout << 2;
        }

        else if(count>n){
            right = mid - 1;
            //cout << 1;
        }
        count = 0;
    }

    count=0;
    for(int k=answer1;k<=answer2;k++){
        for (int j = 0;j < times.size();j++) {
            count =count+ (k / times[j]);
        }
        if(count==n){
            answer=k;
            break;
        }
        count=0;
    }


    return answer;
}
