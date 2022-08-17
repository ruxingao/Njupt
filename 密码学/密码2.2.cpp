#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()

{
char c[]="duvdxnypafavhdkoorbbgqinysacoabefpyxvklvikxsgxnbrqwum\
uchctbwrgtoaddyaeywegojnqyeipgrqkydbbxjkkmqrofgtuintdmhwcxxeftz\
xvwtevrlwybvpybdjrixbzlulqtyyfjyfhuksucavhkktfisuldooaswhcqfznk\
jizbxxxlebbfgjnnulufclqbgouuuwcthavajtruwucdzvxircqfznhcechxzrv\
cbbfgjmicciifgyocqngsftjvdmkbzltarnthzrcfnrjvdhychcrlpbpmkphwiok\
qyfcjeimikchrvoptrikdbbwgqinynwnevypnhflqtmktfijlwumucmkwsdoqvlvr\
mfzsfnzqtfgjwtzwryurtouuvbhkjbtmzkudkektuintdmhliirvftdwvotspnfug\
iefqyjvnyprcgusgcftdwvotvlofdgcqqhyoqotkltbsqgdzanipjomopwtmblxxyq\
ocqfzndkgtzalqdvbbmtbiaucdgsedgwthonzpwwceaalcowduvhkblaoasp\
nfdyjqiy";
int i,e=strlen(c);
char d[e+1];
int a[e],b[e],f[26];
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
	b[5*i+0]=(a[5*i+0]*21+a[5*i+1]*23+a[5*i+2]*25)%26+97;
	b[5*i+1]=(a[5*i+0]*15+a[5*i+1]*2+a[5*i+2]*4)%26+97;
	b[5*i+2]=(a[5*i+0]*17+a[5*i+1]*16+a[5*i+2]*3)%26+97;
	b[5*i+3]=(a[5*i+3]*7+a[5*i+4]*23)%26+97;
	b[5*i+4]=(a[5*i+3]*18+a[5*i+4]*11)%26+97;
}
for(i=0;i<e+1;i++){
d[i]=(char)b[i];
	}

cout<<d<<endl;

return 0;
}
