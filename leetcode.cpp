//solutia problemei "Apply Operations to Maximize Score"
//nu stiu daca link-ul e public
// https://leetcode.com/problems/apply-operations-to-maximize-score/description
//contul e gratis si nu strica la nimic


//cele 2 asa zise optimizari ar fi
//1.) un fel de apel recursiv al functiei gps
//daca vreau sa calculez gps(36) eu voi calcula implicit si gps(9) (dupa impartirea la 2 de 2 ori)
//poate valoarea era deja calculata, poate va trebui sa o calculez
//nu pare ca a fost o optimizare foarte buna
//2.) in loc sa calculez tot timpul acele scoruri gps, ele pot fi cumva calculate la selectarea numerelor prime
//creste putin complexitatea acolo, dar e o functie pe care o apelam o singura data
//dupa aceea gps(x) e calculat in O(1)


class Solution {

    static bool done;
    static int primes[100010];
    static bool isPrime[100010];
    static int primeCount;
    static int numberScores[100010];
    
    static void doo(){
        memset(numberScores,0,100010*sizeof(int));
        for(int i=2;i<=100000;i+=2){
            numberScores[i]=1;
        }
        primes[0]=2;
        primeCount=1;
        for(int i=3;i<3200;i+=2){
            if(isPrime[i]==false){
                primes[primeCount++]=i;
                for(int j=i;j<=100000;j+=i){
                    numberScores[j]++;
                    isPrime[j]=true;
                }
            }
        }
        for(int i=3201;i<100000;i+=2){
             if(isPrime[i]==false){
                primes[primeCount++]=i;
                for(int j=i;j<=100000;j+=i){
                    numberScores[j]++;
                }
            }
        }
    }

    struct su{
        int poz, val, count;
        bool operator()(const su& s) const{
            if(val!=s.val){
                return val<s.val;
            }
            if(count!=s.count){
                return count<s.count;
            }
            return poz<s.poz;
        }
        bool operator<(const su& s) const{
            if(val!=s.val){
                return val<s.val;
            }
            if(count!=s.count){
                return count<s.count;
            }
            return poz<s.poz;
        }
    };


    int gps(int x, int sp){
        if(x==1){
            return 0;
        }
        int z=x, y=numberScores[x];
        if(y>0){
            return y;
        }
        for(int i=sp;i<primeCount;i++){
            if(x%primes[i]==0){
                while(x%primes[i]==0){
                    x/=primes[i];
                }
                int h=gps(x,i+1);
                numberScores[z]=h+1;
                return h+1;
            }
            if(primes[i]*primes[i]>x){
                numberScores[x]=1;
                return 1;
            }
        }
        return 0;
    }

    int gps(int x){
        int z=x;
        if(x==1){
            return 0;
        }
        int y=numberScores[x];
        if(y>0){
            return y;
        }
        int ret=0;
        for(int i=0;i<primeCount;i++){
            if(x%primes[i]==0){
                ret++;
                while(x%primes[i]==0){
                    x/=primes[i];
                }
                int h=gps(x,i+1);
                numberScores[z]=h+1;
                return h+1;
            }
            if(primes[i]*primes[i]>x){
                numberScores[z]=ret+1;
                return ret+1;
            }
        }
        numberScores[x]=ret;
        return ret;
    }

void processList(vector<int>& nums, priority_queue<su>& pq, int k){
    int l=nums.size();
    vector<pair<int,pair<int,int>>> v(l);
    stack<pair<int,int>> st;
    v[0].first=numberScores[nums[0]];
    v[0].second.first=0;
    st.push({v[0].first,0});
    for(int i=1;i<l;i++){
        int x=numberScores[nums[i]];
        v[i].first=x;
        pair<int,int> p{x,i};
        while(!st.empty() && st.top().first<x){
            st.pop();
        }
        v[i].second.first = (st.empty()?0:st.top().second+1);
        st.push(p);
    }
    stack<pair<int,int>> st1;
    st1.push({v[l-1].first,l-1});
    v[l-1].second.second = l-1;

    for(int i=l-2;i>=0;i--){
        int x=v[i].first;
        pair<int,int> p{x,i};
        while(!st1.empty()&&x>=st1.top().first){
            st1.pop();
        }
        v[i].second.second = st1.empty()?l-1:st1.top().second-1;
        st1.push(p);
        
    }
    long long kk=0LL;
    kk+=k;
    for(int i=0;i<l;i++){
        long long u=((long long)(v[i].second.second-i+1))*((long long)(i+1-v[i].second.first));
        u=min(u,kk);
        su s{i, nums[i], ((int)u)};
        pq.push(s);
    }
}

void pow(long long& start, int nr, int p){
    long long x=1LL, pp=0LL, m=1000000007LL;
    pp+=p;
    for(int i=1;i<=nr;i*=2){
        if((i&nr)){
            x*=pp;
            if(x>=m){
                x%=m;
            }
        }
        pp*=pp;
        if(pp>=m){
            pp%=m;
        }
    }
    start*=x;
    if(start>=m){
        start%=m;
    }
}

public:
    int maximumScore(vector<int>& nums, int k) {
        priority_queue<su> pq;
        if(!done){
            done=true;
            doo();
        }
        processList(nums,pq,k);
        long long ret=1, m=1000000007LL;
        while((!pq.empty())&&k>0){
            su s=pq.top();
            pq.pop();
            if(k>s.count){
                k-=s.count;
                pow(ret,s.count,s.val);
            }
            else{
                pow(ret,k,s.val);
                k=0;
            }
        }
        return ((int)ret);
    }
};
bool Solution::done=false;
int Solution::primes[100010];
int Solution::primeCount;
bool Solution::isPrime[100010];
int Solution::numberScores[100010];