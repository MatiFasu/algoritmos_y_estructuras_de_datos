#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --[ Funciones Basicas ]--

// Descripcion: Retorna la longitud de la cadena s
// Paramerto:
//    s - La cadena cuya longitud se desea conocer
// Retorna: la longitud de la cadena s
// Ejemplo: l
int length(string s)
{
   int i=0;
   while(s[i]!='\0')
   {
   		i++;
   }
   return i;
}

// Retorna la cantidad de veces que la cadena s contiene a c
int charCount(string s,char c)
{
   int i=0;
   int j=0;
   while(s[i]!='\0')
   {
   		i++;
   		if (s[i]==c)
   		{
   			j++;
		}
   }
   return j;
}

// Retorna la subcadena de s comprendida entre d (inclusive) y h (no inclusive)
string substring(string s,int d,int h)
{
	int i=d;
	string x;
   while(i<h){
   		x += s[i];
   		i++;
   }
   return x;
}

// Retorna la subcadena de s que va desde d (inclusive) hasta el final
string substring(string s,int d) // ok
{
   int i=d;
   string x;
   while(s[i]!='\0'){
   		x += s[i];
   		i++;
   }
   return x;
}

// Retorna la posicion de la primer ocurrencia
// de c dentro s, o -1 si s no contiene a c
int indexOf(string s,char c) // ok
{
   int i=0;
   int pos,p;
   while(s[i]!='\0'){
   		
   		if (s[i]==c){
   			pos=i;
   			return pos;
		   }
		else{
			p=-1;
		}   
		i++;
   }
   return p;
}

// Retorna la posicion de la primer ocurrencia de c dentro de s
// considerando la subcadena de s que va desde offset hasta el final.
// Ejemplo: indexOf("ALGORITMOS",'O',7) retorna: 1
int indexOf(string s,char c,int offSet) // ok
{
   int i=offSet;
   int n=length(s);
   int pos;
   while(s[i]!='\0'){
   	
 		if(s[i]==c){
 			pos=i;
 			i=n;
		 }
		
   		i++;
   }
   return pos;
}

// Retorna la posicion de la ultima ocurrencia de c dentro de s
// o -1 si s no contiene a c
int lastIndexOf(string s,char c)
{
   	int i=0;
   	int pos;
   	while(s[i]!='\0'){
   		
   		if (s[i]==c){
   			pos=i;
		}
   		i++;
	}
	
	if (s[pos]==c){
   		return pos;
	}
	else{
		return -1;
	}
}

// Retorna la posicion de la n-esima ocurrencia de c dentro de s.
// Por ejemplo: indexOfN("pedro|pablo|juan|rolo",'|',2) retorna 11.
int indexOfN(string s,char c,int n)
{
   int i=0;
   int j=0;
   int pos;
   while(s[i]!='\0'){
   	
   	if(s[i]==c){
   		j++;
   		if(j==n){
			pos=i;
		}
	}
   	i++;
   }
	
	return pos;
}

// Retorna el valor numerico de ch.
// Ejemplo: charToInt('4') retorna: 4.
int charToInt(char ch)
{
	return ch-48;
}

int charToInt2(char ch)
{
   int n;
	if((ch>=65) && (ch<=78)){
    	n=ch-64;
	}
	if(ch>=97 && ch<=110){
		n=ch-96;
	}
	if(ch>=79 && ch<=90){
		n=ch-64+1;
	}

	return n;
}

// Retorna el valor char de i.
// Ejemplo: intToChar(4) retorna: '4'.
char intToChar(int i)
{
   int x=i+48;
   return x;
}

char intToChar2(int i)
{
   char x;
   if(i>=48 && i<=57){
   	x=i+48;
   }
   if(i>=65 && i<=90){
   	x=i;
   }
   if(i>=97 && i<=122){
   	x=i;
   }
   return x;
}

// retorna el i-esimo digito de n contando desde la derecha
int getDigit(int n,int i) // ok
{	
	if (i==0){
		return n%10;
	}
	else{
		for(int j=0;j<i;j++){
			n/=10;
		}
		n%=10;
		return n;
	}
}

int digitCount(int n) // ok
{
	int i=0;
   for(int j=0;n>0;j++){
   	n/=10;
   	i++;
   }
   
   return i;
}

int digitCount2(double numero){
	int n=numero,cont=1;
	while(numero-int(numero)!=0){
		numero*=10;
		n=numero;
		if(n<10){
			cont++;
		}
	}
	int x=10;
	while(n/x!=0){
		cont++;
		x=x*10;
	}
	
	return cont;
}

string intToString(int num) // ok
{
	if( num==0)
	{
		return "0";
	}
	string numero;
	int cont=digitCount(num),j=0; //cont=5;
	double x=1;
	for(int i=0;i<digitCount(num);i++){
		x*=10;
	}
	for(int i=0;i<digitCount(num);i++){
		while(j<cont){
			x/=10;
			int n=(num/x);
			char c=intToChar(getDigit(n,0));
			numero+=c;
			j++;
		}
	}
	return numero;
}

int stringToInt(string s) // ok
{
   int i=0;
   int j=0;
   int n,x=0,m=1;
   while(s[i]!='\0'){
   	 i++;
   }
   for(int k=0;k<i-1;k++){
   	m*=10;
   }
   while(j<i){
   	n=charToInt((char)s[j]);
   	x= x + (n*m);
   	m/=10;
   	j++;
   }
   
   return x;
}

int stringToInt2(string s,int b) // ok
{
	int num=0,d,p=1;
	
	for(int i=length(s)-1;i>=0;i--){
		d=charToInt((char)s[i]);
		if(d>=10 && d<=42){
			d=d-7;
		}
		else{
			if (d>=49 && d<=94){
				d=d-39;
			}
		}
		num = num + d*p;
		p=p*b;
	}
	return num;
}

string charToString(char c)
{
	string s="h";
   int i=0;
   while(i<1){
   	s[i]=c;
   	i++;
   }
   
   return s;
}

char stringToChar(string s)
{
   char x;
   x=s[0];
   
   return x;
}

string stringToString(string s)
{
	return s;
}

string doubleToString(double d)
{
	//int i=0;
   string numero;
   numero = intToString(d);
   double decimal=d-int(d);
   
   if (d-int(d)!=0){
   	numero=numero+".";
   	int x=1;
   	for(int j=0;j<digitCount2(d)-digitCount2(int(d));j++){
   		x=x*10;
   		double n=decimal*x;
   		char c=intToChar(getDigit(n,0));
   		numero=numero+c;
	   }
   }
   
   return numero;
}

double stringToDouble(string s)
{
	int i=0;
	string n="";
	while(s[i]!='.'){
		n+=s[i];
		i++;
	}
	int y=stringToInt(n);
	
	string d;
	int j=0;
	while(s[i]!='\0'){
		i++;
		j++;
		d+=s[i];
	}
	int x=stringToInt(d);
	
	int w=1;
	for(int k=0;k<j-1;k++){
		w*=10;
	}
	
	double p=(double)x/w;
	
	double z= y+p;
	
	return z;
}

bool isEmpty(string s)
{
   bool n = false;
   if( s=="" )
   {
   		return !n;
   }
   
   return n;
}

bool contains(string s, char c)
{
   int i=0;
   while(s[i]!='\0'){
     
	 if(c==s[i]){
	 	return true;
	 }
	 	
	 i++;
   }
   
   return false;
}

string replace(string s, char oldChar, char newChar)
{
   int i=0;
   while(s[i]!='\0'){
   	
   	if (oldChar==s[i]){
   		s[i]=newChar;
	   }
   	
   	i++;
   }
   
   return s;
}

string insertAt(string s,int pos,char c)
{
   int i=0;
   string s1="";
   string s2="";
   while(i<pos+1){
   	s1+=s[i];
   	i++;
   }
   s1[pos]=c;
   
   while(s[pos]!='\0'){
   	s2+=s[pos];
   	pos++;
   }
   
   return s1+s2;
}

string removeAt(string s,int pos)
{
   string s1="";
   string s2="";
   int i=0;
   while(i<pos){
   	s1+=s[i]; //esto es
   	i++;
   }
   
   while(s[i+1]!='\0'){
   	s2+=s[i+1];
   	i++;
   }
   
   return s1+s2;
}

string ltrim(string s)
{
	int i=0;
	while(s[i]==32 && s[i]<65){
		i++;
	}
	
	int j=i;
	string x;
	while(s[j]!='\0'){
		x+=s[j];
		j++;
	}
  
   return x;
}

string rtrim(string s)
{
	int i=0,pos;
	while(s[i]!='\0'){
		if(s[i]>=97 && s[i]<=122){
			pos=i;
		}
		i++;
	}
	int j=0;
	string x="";
	while(j<pos+1){
		x+=s[j];
		j++;
	}
	
	return x;
}

string trim(string s)
{
   int i=0,pos,pos2;
   while(s[i]!='\0'){
   	if(s[i]>=65 && s[i]<=90){
   		pos=i;
	   }
	if(s[i]>=97 && s[i]<=122){
		pos2=i;
	}   
	
   	i++;
   }
   
   int j=pos;
   string x="";
   while(j<pos2+1){
   	x+=s[j];
   	j++;
   }
   
   return x;
}

string replicate(char c,int n)
{
	string s;
	for(int i=0;i<n;i++){
		s+=charToString(c);
	}
   
   return s;
}

string spaces(int n)
{
	string s;
   for(int i=0;i<n;i++){
   	s+=charToString(' ');
   }
   return s;
}

string lpad(string s,int n,char c)
{
	string x;
	int cant=length(s);
	int m;
   if (cant>=n){
   	x=s;
   }
   else{
   	m=n-cant;
   	for(int i=0;i<m;i++){
   		x+=charToString(c);
	}
	x+=s;
   }
   
   return x;
}

string rpad(string s,int n,char c)
{
   string x;
	int cant=length(s);
	int m;
   if (cant>=n){
   	x=s;
   }
   else{
   	m=n-cant;
   	for(int i=0;i<m;i++){
   		x+=charToString(c);
	}
	x=s+x;
   }
   
   return x;
}

string cpad(string s,int n,char c)
{
   string x;
   string izq,d;
	int cant=length(s);
	int m,t;
   if (cant>=n){
   	x=s;
   }
   else{
   	m=n-cant;
   	if(m%2==0){
   		t=m/2;
	}
	else{
		t=m/2+1;
	}
   	
   	for(int i=0;i<t;i++){
   		izq+=charToString(c);
	}
	for(int i=0;i<m/2;i++){
   		d+=charToString(c);
	}
	x=izq+s+d;
   }
   
   return x;
}

bool isDigit(char c)
{
   if (c>=48 && c<=57){
   	return true;
   }
   else{
   	return false;
   }
   
}

bool isLetter(char c)
{
	bool n=true;
   if ((c>=65 && c<=90) || (c>=97 && c<=122)){
   	return n;
   }
   else{
   	return !n;
   }
   
}

bool isUpperCase(char c)
{
   if (c>=65 && c<=90){
   	return true;
   }
   else{
   	return false;
   }
}

bool isLowerCase(char c)
{
   if(c>=97 && c<=122){
   	return true;
   }
   else{
   	return false;
   }
   
}

char toUpperCase(char c)
{
   char x=c;	
   if(c>=65 && c<=90){
   	x=c;
   }
   if(c>=97 && c<=122){
   	x=c-32;
   }
   
   return x;
}

char toLowerCase(char c)
{
   char x=c;
   if(c>=65 && c<=90){
   	x=c+32;
   }
   return x;
}








#endif
