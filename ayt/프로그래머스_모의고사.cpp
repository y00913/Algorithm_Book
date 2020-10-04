#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> spz = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    vector<int> result = {0,0,0};
    int cnt=0;
    
    //1번 수포자
    for(int i=0;i<answers.size();++i){
        if(cnt==spz[0].size()) cnt=0;  
        if(answers[i]==spz[0][cnt]) ++result[0];
        
        ++cnt;
    }
    //2번 수포자
    cnt=0;
    for(int i=0;i<answers.size();++i){
        if(cnt==spz[1].size()) cnt=0;      
        if(answers[i]==spz[1][cnt]) ++result[1];
        
        ++cnt;
    }
    //3번 수포자
    cnt=0;
    for(int i=0;i<answers.size();++i){
        if(cnt==spz[2].size()) cnt=0;
        if(answers[i]==spz[2][cnt]) ++result[2];
        
        ++cnt;
    }
    
    //결과
    int max = *max_element(result.begin(), result.end());
    for(int i=0;i<3;++i){
        if(max==result[i]) answer.push_back(i+1);
    }
    
    return answer;
}
