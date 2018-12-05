#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
kmain()
{
       clearScreen();
	   
       print("Welcome to my operating system!\n________INDRONIL_OS________\nUser login\n");
	   string username = "indronil";
	   string password = "1507105";
	   string history = "";
	   uint8 n = 1;
	   
	   string inp = 0;
	   while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("Username: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("password: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("Login Done!\n");
			   break;
		   }
		   print("Wrong info. Try again\n");
	   }
	   
       while (1)
  			{
			char b = n + '0';
			string c;
			c[0]=b;			
			print("\nINDRONIL_OS( ");
			print(c);
			print(")--> ");
			inp = readStr();
			if(strEql(inp,"cmd"))
			{
				print("New cmd opened!\n");
				strcat(history, "cmd\n");
				n++;
				
			}
			else if(strEql(inp,"clear"))
			{
				clearScreen();
				strcat(history, "clear\n");
			}
			else if(strEql(inp,"history"))
			{
				print(history);
				strcat(history, "history\n");	
			}
			else if(strEql(inp,"substr"))
			{
				print("Enter string: ");
				inp = readStr();
				screen_substr(inp);
				strcat(history, "substr\n");
			}
			else if(strEql(inp,"help"))
			{
				print("clear\t: Clear screen.\ncmd : Starts new cmd.\nsubstr : Finds substring.\nexit : Exit from present cmd.\nshutdown : Turning off the OS.\nhistory : Shows the history.\nmname : Shows the user name.\n");
				strcat(history, "help\n");
			}
			else if(strEql(inp,"shutdown"))
			{
					print("Turning off my OS!\n");
					break;
			}
			else if(strEql(inp,"mname"))
			{
				print(username);
				strcat(history, "mname\n");
			}			
			else if(strEql(inp,"exit"))
			{
					print("Exits from present cmd!\n");
					n--;
					strcat(history, "exit\n");
				if(n==0)	{
						print("Turning off my OS!\n");
						break;}		
					
			}
			else
			{
					print("Bad command!\n");
			}
       }
}
