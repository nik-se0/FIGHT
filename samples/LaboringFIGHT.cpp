// Copyright 2021 Semenova Veronika
#include <iostream>
#include <locale>
#include <cstdlib>
#include "HeaderFIGHT.h"
using namespace std;
int main()

{  // a 1 2 c 3 2 e 5 2 g 7 2 i 9 2 b 9 2 d 9 f 2 h 2 j 4 
   // a 6 b 1 b 3 b 6 c 1 c 3 c 6 e 1 e 3 e 8 f 6 f 5 f 8 f 10 g 8 h 3 h 6 h 8 j 3 i3
   setlocale(LC_ALL, "Rus");
   srand(time(NULL));
   FIGHT www;
   
   char entry=0;
   do {cout<<"\tÌÎÐÑÊÎÉ ÁÎÉ\n\n \tCûãðàåì?\n\t1.Äà\n\t2.Â ñëåäóþùèé ðàç\n\tÂâîä: ";
       cin>>entry;
       if(entry!='1'){system("cls"); cout<<"ÍÓ ×ÒÎ Æ, ÌÛ ÂÀÑ ÏÎÄÎÆÄÅÌ\n";}
       else { system("cls"); cout<<"\tÏÎËÅ ÃÎÒÎÂÎ. ÂÐÅÌß ÐÀÑÒÀÂËßÒÜ ÊÎÐÀÁËÈ\n"; cout<<www; }
   }  while(entry!='1');
	
	www.DEC();	         
	cout<<"\n\tß ÇÀÄÀË ÑÂÎÈ ÊÎÐÀÁËÈ. ÂÀØÀ Î×ÅÐÅÄÜ\n";
	www.CIN();
	cout<<"ÂÑÅ ÊÎÐÀÁËÈ ÂÂÅÄÅÍÛ, ÌÎÆÅÌ ÈÃÐÀÒÜ";
	www.FIRE();
    cin>>entry;   
}

