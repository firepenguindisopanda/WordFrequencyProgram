
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;
char upperToLowerCase (char ch){
	if((ch>= 'A') && (ch<='Z')){
		ch=ch+32;
	}
	return ch;
}
int readCharacters(char data[]) {        
 
    ifstream fin;     				
	char ch;     
	int i;             
	
	fin.open("passage.txt");     
	
	if (!fin.is_open()) {         
		cout << "Error -- passage.txt could not be opened." << endl;         
		return -1;
	}         
	
	i = 0;
	
	fin >> noskipws;          
	fin >> ch;  
	ch=upperToLowerCase(ch);//changes all characters to lower case. Makes data easier to manipulate.  
	while (!fin.eof()) {           
		data[i] = ch;          
		i = i + 1;
		fin>>noskipws;           
		fin >> ch;
		ch=upperToLowerCase(ch);     
	}          
	
	data[i] = '\0';          
	fin.close();
	                
	return i; 

}

bool isLetter (char c) {
	if ((c >= 'A' && c <= 'Z') ||
	    (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}
int getWord (char words[], int start, char word[]) { 
 
    int i, j, length;         
	
	length = strlen (words);			// find how many characters in words
	
	i = start;
	while (i < length && !isLetter(words[i]))
		i = i + 1;             
		
	if (i == length)					// there are no more words
		return -1;						
		
	j = 0;     							// copy characters to word
	while (isLetter(words[i])) {
		word[j]= words[i];
		i = i + 1;
		j = j + 1;     
	}       
 
    word[j]= '\0';          
    
	return i;							// starting position to look for next word
}
/*
This function sorts the words in ascending order
*/
void sort(string array[], int len) {
	int i, j;
	string check;
	
	for(i=1; i<len; i++) {
		check = array[i];
		for(j=i; j>=1 && (check < array[j-1]); j--) {
			array[j] = array[j-1];
			array[j-1] = check;
		}
	}
}
void countWords(char allWords[]){
	ofstream output;
	int length, wcount, j=0, i=0, x=0, y=0, te=0, tr, counter=0, ty=0, cap;
	int count[100];
	string tempW[100];//tempW: temporary Word aray
	string tempW2[100];
	string temp, temp2;
	char tempC[100];//tempC: temporary Character array
	output.open("result.txt");
	if(!output.is_open()){
		cout<<"Error opening file shania.txt"<<endl;
		return ;
	}
	length=strlen(allWords);
	for(int l=0;l<length;l++){
		if(allWords[l]== ' '){
			wcount++;
		}
	}
	//The while loop is used to acquire all the words from the allWords[] array and store it in
	// the tempW[] string array as strings
	while(i<wcount){
		j=getWord(allWords, j, tempC);
		tempW[i]=tempC;
		i++;
	}
	for(int wd=0;wd<i;wd++){
		count[wd]= 0;
	}
	sort(tempW, i);//sorts the words in tempW array even if they occur more than once
	
	while(x<i){
		temp=tempW[te];
		for(int ja=0;ja<i;ja++){
			if(temp==tempW[ja]){
				tr=ja;//tr is the index of the last occurrence of the word in the tempW[] array
			}
		}
		tempW2[y]=tempW[tr];//This array was used to remove the words that appear more than once
		te=tr+1;//te is given the number tr+1 to go to the next index position in the tempW[] array to get the next word
		//cout<<te<<endl;
		x=te;// x is assigned the value of the variable te to avoided duplication of the last word in the array
		y++;

	}
	//checks for the occurrence of each word
	while(counter<y){
		temp2=tempW2[counter];
		for (int mn=0;mn<i;mn++){
			if(temp2==tempW[mn]){
				count[counter]=count[counter]+1;
			}
		}
		counter++;
	}
	output<<"Words"<<"==============================="<<"Frequency"<<endl;
	for(int jk=0;jk<y;jk++){
		if(jk<50){
			output<<tempW2[jk]<<"					"<<count[jk]<<endl;
			cap=jk;
		}	
	}
	cap=cap+1;
	for(int qw=0;qw<5;qw++){
		output<<endl;
	}
	output<<"These word(s) were unable to be stored."<<endl;
	output<<"Words"<<"====================================="<<"Frequency"<<endl;
	for(int lp=cap; lp<y;lp++){
		output<<tempW2[lp]<<"						"<<count[lp]<<endl;
	}

}



int main(){
	ifstream in;
	
	char word;
	int count=0, i = 0, chFind, wFind;
	char data[500];
	char words[50];
	chFind=readCharacters(data);

	cout<<endl;
	
	//getWords(data, words);
	
	countWords(data);
	cout<<"Program Excuted and output placed into the result.txt file"<<endl;

	return 0;
}
