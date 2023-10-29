class Solution {
public:
    int poorPigs(int buckets, int mtd, int mtt){
  int a=mtt/mtd;
  float n=log(buckets)/log(a+1);
  if(n-(int)n == 0)
  return n;
  return n+1;
}
};