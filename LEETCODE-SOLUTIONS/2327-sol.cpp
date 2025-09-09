class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       int currentCount = 1;// people who are capable of sharing secret

       int whoKnows = 1 ;//people who know the secret whether capable of sharing it or not

       const long long m = 1e9 + 7 ;// modulo

        unordered_map<int,int> forgetfulPeople;//hashmap to store how many people forget on a particular day

        forgetfulPeople.insert({1+forget,1}) ;// for person - 1 

        unordered_map<int,int> sayingSecret ;//how many new people will be capable of sharing the secret on a particular day


     // % m IS USED TO PREVENT RUNTIME ERROR _ OVERFLOW

        for(int i = 1 + delay; i <= n;i++){

            currentCount  = (((currentCount - forgetfulPeople[i]) % m) + m )%m ;

            whoKnows = (((whoKnows - forgetfulPeople[i]) % m + m))%m ;

            currentCount = (currentCount + sayingSecret[i] )%m;

            forgetfulPeople[i + forget] = currentCount % m ;

             sayingSecret[i + delay] = currentCount % m ;

             whoKnows = (whoKnows  + currentCount )%m ;


        }

        return (whoKnows)%m ;
    }
};