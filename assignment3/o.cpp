#include <iostream>
#define maximum 200

using namespace std;
int A[maximum][maximum],B[maximum][maximum],C[maximum][maximum];
void print(int n, int m){
    cout<<"A X B=>\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void multiply(int column1,int row2,int n1,int m2){
    if(column1==n1 || row2==m2 || C[column1][row2]!=0) return;
    for(int i=0;i<m2;i++){
        C[column1][row2]+=A[column1][i]*B[i][row2];
    }
    multiply(column1+1,row2,n1,m2);
    multiply(column1,row2+1,n1,m2);
}


int main(){
    cout<<"Number of rows and columns of A and B: ";
    int n,m,n2,m2;
    cin>>n>>m>>n2>>m2;
    if(m!=n2){
        cout<<"Invalid Dimensions\n";
    }else{
        cout<<"Matrix A:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>A[i][j];
            }
        }
        cout<<"Matrix B:\n";
        for(int i=0;i<n2;i++){
            for(int j=0;j<m2;j++){
                cin>>B[i][j];
            }
        }
        multiply(0,0,n,m2);
        print(n,m2);
    }
    

}