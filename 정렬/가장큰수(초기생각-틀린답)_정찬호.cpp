#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool compare_first(int a, int b){
    while(a>9){
        a=a/10;
    }
    while(b>9){
        b=b/10;
    }
    if(a>b){return true;}
    else{return false;}
}//첫번째 자릿수의 크기대로 배열 조정
bool compare_second(int a,int b){
    int a1=a;
    int b1=b;
    while(a1>9){
        a1=a1/10;
    }
    while(b1>9){
        b1=b1/10;
    }
    if(a1==b1){
        if(a>99){
            a=a%100;
            a=a/10;
        }
        else if(a>9){
            a=a%10;
        }//두번째 자리 추출
        if(b>99){
            b=b%100;
            b=b/10;
        }
        else if(b>9){
            b=b%10;
        }//두번째 자리 추출
        if(a>b){return true;}
        else{return false;}

    }
    else{return false;}


}

bool compare_third(int a, int b){
    int a1=a;
    int b1=b;

    if(a1>99){a1=a1/10;}
    if(b1>99){b1=b1/10;}

    if(a1==b1){
        if(a>b){return true;}
    }
    else{return false;}
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),greater<>());
    sort(numbers.begin(),numbers.end(),compare_first);
    sort(numbers.begin(),numbers.end(),compare_second);
    sort(numbers.begin(),numbers.end(),compare_third);
    for(int i=0;i<numbers.size();i++){
        answer.append(to_string(numbers[i]));
    }
    return answer;
}
