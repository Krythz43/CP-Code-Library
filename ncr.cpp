const lli mod = 1e9+7;
const int S = 1e5+5;
 
lli fact[S];
lli inv[S];

lli multi(lli x,lli n){
    if(n == 0)return 1;
    if(n==1)return x%mod;
    lli ans = multi((x*x)%mod,n/2);
    if(n%2)ans=(ans*x)%mod;
    return ans;
}

void precal()
{
  lli i;
  fact[0] = 1;
  inv[0] = multi(fact[0],mod-2);
  for(i=1;i<S;i++)
  {
    fact[i] = (i*fact[i-1])%mod;
    inv[i] = multi(fact[i],mod-2);
  }
}

lli ncr(lli x,lli y)
{
  if(x<y || x<0 || y<0)
    return 0;
  lli temp = fact[x];
  temp = (temp*inv[y])%mod;
  temp = (temp*inv[x-y])%mod;
  return temp;
}