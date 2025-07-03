const int INF = 1e18;
const int N = 1e6+10;

int v[N],tree[4*N];
int merge(int a,int b){
    
    return min(a,b);
}
void build(int node,int b,int e)// 1 based
{
    if(b==e)
    {
        tree[node]=v[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=merge(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j)// 1 based 
{
    if(i>e || j<b)
        return INF;
    if(b>=i && e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return merge(p1,p2);
}
void update(int node,int b,int e,int i,int value) // 1 based
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node]+=value;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);
    tree[node]=merge(tree[left],tree[right]);
}
