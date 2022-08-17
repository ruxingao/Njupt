#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std
int main()

{
char c[]="xqjnknadyexjsaxmbsnejljsnhjdbjnajozbyezqylmndmynszdvvn\
jjedsdxwdbjnaizjjnjdvnasdxqjnszwvanenqsxdyjzadssaxmbsnjvbaanqsylso\
nzqylhnsozewzanqwzavxqfjbvoizyxvxnjxjsznhiyzldsabjsnejnaknaszjszan\
sonedsddqehnexdsndvvnjjvzqsazyoztnknaxwdqljnaknajszaxqfsonedsdxjvz\
hiazhxjnesonqsonvzqwxenqsxdyxslzwsonedsdtxyymnvzhiazhxjnexqsoxjidi\
natnianjnqsdjljsnhwzaandyxuxqfvzhiyncdvvnjjvzqsazyzqnqvalisneedsds\
odstnvdyyvxionasncsizyxvldssaxmbsnmdjnenqvalisxzqmlbjxqfzbasnvoqxr\
bnjnqvalisneedsdvdqmnpnisvzqwxenqsxdynknqxwsonjszadfnjnaknaxjbqsab\
jsnehzanzknazbahnsozejdanjnvbandfdxqjsvzyybjxzqdssdvpj";
int K1=3,K2=17;
int i,e=strlen(c);
int a[e],b[e],f[26];
char d[e+1];
for(i=0;i<e;i++){
a[i]=(int)c[i]-97;
	}
for(i=0;i<26;i++){
	b[i]=0;
}
for(i=0;i<e;i++){
a[i]=(int)c[i]-97;
b[a[i]]++;
	}
for(i=0;i<26;i++){
	cout<<b[i]<<" "<<endl;
}
for(i=0;i<e;i++){
    b[i]=(a[i]*3+17)%26+97;
}
for(i=0;i<e;i++){
d[i]=(char)b[i];
}

cout<<d<<endl;

return 0;
}
