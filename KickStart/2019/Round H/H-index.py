def solve(N, A):
    '''H = {}
    s = ""
    curmax = 1
    for item in A:
        if item not in H:
            H[item]=1
        else:
            H[item]+=1
        if H[item]>=int(item) and curmax<int(item):
            curmax = int(item)
        s+=str(curmax)+' '
    H = [0]*N
    H[0]+=1
    for i in range(1, N):
        if int(A[i])>H[i-1]:
            H[i] = H[i-1]+1
        else:
            H[i] = H[i-1]
    s = ""
    for item in H:
        s+=str(item)+' '
        '''
    H = [0]*100000
    s = ""
    curmax = 1
    for i in range(N):
        for j in range(1, int(A[i])+1):
            H[j]+=1
            if H[j]>=j and curmax<j:
                curmax = j
        s+=str(curmax)+' '
    return s
    
    
def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        a = input().split()
        out = solve(n, a)
        print("Case #{}: {}".format(_+1, out))
        
main()
