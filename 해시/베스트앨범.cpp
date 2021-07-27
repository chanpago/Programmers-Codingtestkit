def solution(genres, plays):
    answer = []
    firstorder={}
    secondorder={}

    for i in range(len(genres)):
        genre=genres[i]
        play=plays[i]
        firstorder[genre]=firstorder.get(genre,0)+play
        secondorder[genre]=secondorder.get(genre,[])+[(play,i)]
            #키가 없으면 새로추가 있으면 있는거에 더하기
    #첫번째 정렬: 새로운 딕셔너리에 장르와 플레이수 정렬

    firstordersort=sorted(firstorder.items(),key=lambda x:x[1],reverse=True)
    #내림차순 정렬

    for(genre,total) in firstordersort:
        secondorder[genre]=sorted(secondorder[genre],key=lambda x: (-x[0],x[1]))
        answer+=[idx for (play,idx)in secondorder[genre][:2]]




    return answer
