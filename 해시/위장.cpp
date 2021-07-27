from collections import Counter
def solution(clothes):
    answer = 1
    clotheslist=[]
    for clothe in clothes:
        clotheslist.append(clothe[1])
    order=Counter(clotheslist)
    for i in list(order.values()):
        answer=answer*(i+1)

    return answer-1
