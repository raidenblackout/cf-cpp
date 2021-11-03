#include <iostream>
using namespace std;

template<class t>
struct heap{
    t *elements;
    int size;
    void heapifyup(int root, int bottom);
    void heapifydown(int root, int bottom);
};
template<class t>
void Swap(t &a, t &b){
    t c=a;
    a=b;
    b=c;
}
template<class t>
void heap<t>::heapifyup(int root, int bottom){
    int maxchild,right,left;
    left=root*2+1;
    right=root*2+2;
    if(left<=bottom && elements[left]>elements[root]){
        maxchild=left;
    }else{
        maxchild=root;
    }
    if(right<=bottom && elements[right]>maxchild){
        maxchild=right;
    }
    if(maxchild!=root){
        Swap(elements[root],elements[maxchild]);
        heapifyup(maxchild,bottom);
    }
}
template<class t>
void heap<t>::heapifydown(int root, int bottom){
    int parent;
    if(bottom > root){
        parent=(bottom-1)/2;
        if(elements[parent]<elements[bottom]){
            Swap(elements[parent],elements[bottom]);
            heapifydown(root,parent);
        }
    }
};



int main(){
}