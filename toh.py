from visualiser.visualiser import Visualiser as vs

# Add decorator
# Decorator accepts optional arguments: ignore_args , show_argument_name, show_return_value and node_properties_kwargs
p=[30,35,15,5,20]
n = len(p)
m=[[0]*n for i in range(n)]
s=[[0]*n for i in range(n)]
counter=0
@vs(node_properties_kwargs={"shape":"record", "color":"#f57542", "style":"filled", "fillcolor":"grey"},show_argument_name=True)
def MatrixChainOrder(i, j):
    if i == j:
        m[i][j]=0
        return 0
    globals()['counter']+=1
    MatrixChainOrder(i,j-1)
    MatrixChainOrder(i+1,j)
    val1=m[i][j-1]+p[i-1]*p[j-1]*p[j]
    val2=m[i+1][j]+p[i-1]*p[i]*p[j]
    if(val1<val2):
        m[i][j]=val1
        s[i][j]=j-1
    else:
        m[i][j]=val2
        s[i][j]=i
    return m[i][j]

def main():
    # Call function
    #towerOfHanoi(3,"1","2","3")
    
    print(MatrixChainOrder(1,n-1))
    for r in s:
        for c in r:
            print(c,end = " ")
        print()
    # Save recursion tree to a file
    print(counter)
    vs.write_image("fibonacci.png")
    #vs.make_animation("fibonacci.gif", delay=2)


if __name__ == "__main__":
    main()