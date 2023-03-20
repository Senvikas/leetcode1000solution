class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int c=0;
        if(flowerbed.length==1 && flowerbed[0]==0 && n==1){
            return true;
        }
        if(flowerbed.length>=2 && flowerbed[1]==0 && flowerbed[0]==0){
            c++;
            flowerbed[0]=1;
        }
    
        for(int i=1;i<flowerbed.length-1;i++){
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                c++;
                flowerbed[i]=1;
            }
        }
        if(flowerbed.length>=2 &&flowerbed[flowerbed.length-2]==0 && flowerbed[flowerbed.length-1]==0){
            c++;
        }
        if(n<=c){
            return true;
        }
        else{
            return false;
        }
    }
}