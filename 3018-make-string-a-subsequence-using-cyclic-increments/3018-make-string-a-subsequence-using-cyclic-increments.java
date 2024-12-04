class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        if(str2.length()>str1.length())
            return false;
        int lp1=0,rp1=str1.length();
        int lp2=0,rp2=str2.length();
        while(lp1<rp1&&lp2<rp2){
            char ch1=str1.charAt(lp1);
            char ch2=str2.charAt(lp2);
            if(ch1=='z'&&ch2=='a'){
                lp2++;
            }
            if(ch1==ch2||ch2-ch1==1){
                lp2++;
            }
            lp1++;
        }
        return lp2==rp2;
    }
}