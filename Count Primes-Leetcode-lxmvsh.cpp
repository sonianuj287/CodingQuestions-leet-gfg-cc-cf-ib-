class Solution {
public:
    int countPrimes(int n) {
    if(n==0 || n==1 || n==2)
            return 0;

       bool arr[n]; 
        for(int i=0;i<n;i++)
        {
            arr[i]=true;
            
        }
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i<n;i++)
        {
               if (arr[i] == true) 
               {
                   for(int j=2;i*j<n;j++)
                       arr[j*i]=false;
               }
              
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if (arr[i]==true)
                count++;
        }
        return count;
        }
};
