#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()

{
char c[]="inseveraldistributedsystemsausershouldonlybeabletoaccessdata\
ifauserpossesacertainsetofcredentialsorattributescurrentlytheonlymethod\
forenforcingsuchpoliciesistoemployatrustedservertostorethedataandmediate\
accesscontrolhoweverifanyserverstoringthedataiscompromisedthenthe\
confidentialityofthedatawillbecompromisedinthispaperwepresenta\
systemforrealizingcomplexaccesscontrolonencrypteddatathatwecall\
ciphertextpolicyattributebasedencryptionbyusingourtechniquesencrypted\
datacanbekeptconfidentialevenifthestorageserverisuntrustedmoreover\
ourmethodsaresecureagainstcollusionattacks";
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
for(i=0;i<e/5;i++){
	b[5*i+0]=(a[5*i+0]*10+a[5*i+1]*3+a[5*i+2]*8)%26+97;
	b[5*i+1]=(a[5*i+0]*5+a[5*i+1]*14+a[5*i+2]*9)%26+97;
	b[5*i+2]=(a[5*i+0]*12+a[5*i+1]*21+a[5*i+2]*11)%26+97;
	b[5*i+3]=(a[5*i+3]*11+a[5*i+4]*3)%26+97;
	b[5*i+4]=(a[5*i+3]*8+a[5*i+4]*7)%26+97;
}
for(i=0;i<e;i++){
d[i]=(char)b[i];
	}

cout<<d<<endl;

return 0;
}

