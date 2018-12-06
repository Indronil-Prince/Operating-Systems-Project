#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
int indronil_main()
{
           clearScreen();
	   
       	   print("Welcome to my operating system!\n________INDRONIL_OS________\n\nUser login\n");
	   string username = "indronil";
	   string password = "1507105";
	   string history = "";
	   uint8 n=1;
	   
	   string inp = 0, len= "";

		while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("Username: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("Password: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("Login Succesful!\n");
			   break;
		   }
		   print("Wrong info. Try again\n");
	   }
	   
       while (1)
  			{		
			print("\nINDRONIL_OS(");
			printnum(n);
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
			else if(strEql(inp,"strlen"))
			{
				print("Enter string: ");
				inp = readStr();
				printnum(strlength(inp));
				strcat(history, "strlen\n");
			}
			else if(strEql(inp,"help"))
			{
				print("clear : Clear screen.\n");
				print("cmd : Starts new cmd.\n");
				print("substr : Finds substring.\n");
				print("exit : Exit from present cmd.\n");
				print("shutdown : Turning off the OS.\n");
				print("history : Shows the history.\n");
				print("mname : Shows the user name.\n");
				print("strlen : Gives length of a given string.\n");
				print("print : Print a given string.\n");
				print("clrline : Clears given lines in cmd.\n");
				//print("logout : Logout.\n");
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
				print("\n");
				strcat(history, "mname\n");
			}	
			else if(strEql(inp,"print"))
			{
				print("Enter string: ");
				inp = readStr();
				print(inp);
				strcat(history, "print\n");
			}	
			else if(strEql(inp,"clrline"))
			{
				uint16 a, b;				
				print("From: ");
				inp = readStr();
				a=atoi(inp);
				inp = 0;				
				print("To: ");
				inp = readStr();
				b=atoi(inp);		
				clearLine(a,b);
				print("Line "); printnum(a); print(" to"); printnum(b); print(" cleared!\n");
				strcat(history, "clrline\n");
			}		
			else if(strEql(inp,"exit"))
			{
					print("Exits from present cmd!\n");
					strcat(history, "exit\n");
					n--;					
					if(n==0)	{
						print("Turning off my OS!\n");
						break;}	
			}
			else
			{
					print("Bad command!\n");
			}
        }
       
	return 0;
}
