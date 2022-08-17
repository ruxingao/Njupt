#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()

{
string s="2435617";
char c[]="inseveraldistributedsystemsausershouldonlybeabletoaccessdata\
ifauserpossesacertainsetofcredentialsorattributescurrentlytheonlymethod\
forenforcingsuchpoliciesistoemployatrustedservertostorethedataandmediate\
accesscontrolHoweverifanyserverstoringthedataiscompromisedthenthe\
confidentialityofthedatawillbecompromisedinthispaperwepresenta\
systemforrealizingcomplexaccesscontrolonencrypteddatathatwecall\
ciphertextpolicyattributebasedencryptionbyusingourtechniquesencrypted\
datacanbekeptconfidentialevenifthestorageserverisuntrustedmoreover\
ourmethodsaresecureagainstcollusionattacks",d[999];
int i,k=0;
for(i=0;i<99;i++){
	d[k]=c[i*7+6];k++;d[k]=c[i*7+3];k++;d[k]=c[i*7+4];k++;d[k]=c[i*7+2];k++;
	d[k]=c[i*7+5];k++;d[k]=c[i*7];k++;d[k]=c[i*7+1];k++;
}
cout<<d<<endl;

return 0;
}

