def fn(x,v):
  if x==0:
    return 0
  ans=99
  for i in range(len(v)):
    if x-v[i]>=0:
        ans=min(ans,1+fn(x-v[i],v))
  return ans

print(fn(30,[1,3,5,7]))