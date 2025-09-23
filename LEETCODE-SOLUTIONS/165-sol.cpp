class Solution {
public:
    int convertoint(string a){
        long long i = 0 ;
        if(a.empty()){
            return 0 ;
        }
        for(char x : a){
            i = i*10 + (int)x - (int)'0' ;
        }

        return (int)i ;

    }
    int compareVersion(string version1, string version2) {
        int v1 = 0 ;
        int n1 = version1.length() ;

        int v2 = 0 ;
        int n2 = version2.length() ;

        while(v1 < n1 || v2 < n2){

            string sub1 = "" ;
            string sub2 = "" ;

            while(v1 < n1 && version1[v1] != '.'){

                sub1 += version1[v1] ;
                v1++ ;

            }
            if(v1 < n1 && version1[v1] == '.' ){
                v1++ ;
            }

           while(v2 < n2 && version2[v2] != '.'){

                sub2 += version2[v2] ;
                v2++ ;

            }
             if(v2 < n2 && version2[v2] == '.' ){
                v2++ ;
            }

            if(convertoint(sub1) < convertoint(sub2)){
                return -1 ;
            }
            else if(convertoint(sub1) > convertoint(sub2)){
                return 1 ;
            }
        }

        return 0 ;
    }
};