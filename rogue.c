#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct xy{
	int x;
	int y;
}man;

int field[100][100]={};
void output(),SetMan();


	int main(){
		char read[100];
		int i,j;
		int line;

		srand((unsigned int)time(NULL));
		line=GetField();
		SetMan();

		while(1){
			system("cls");
			output();
			move();
		}

		printf("end");
		return 0;
	}


/***********************************Function***********************************/

//GetField
	int GetField(){
		FILE *fi;
		char read[100];
		int line;
		int i,j;

		fi=fopen("field.txt","r");

		fscanf(fi,"%d",&line);

		for(i=0;i<line;i++){
			fscanf(fi,"%s",read);
			for(j=0;j<strlen(read);j++)
				field[j+5][i+5]=atoi(read[j]);
		}
		return line;
	}

//SetMan
	void SetMan(){
		do{
			man.x=rand()%100;
			man.y=rand()%100;
		}while(field[man.x][man.y]==0);
	}

//output
	void output(){
		int i,j;

		for(j=0;j<5;j++){
			for(i=0;i<11;j++){
				printf("%c",field[man.x-5+j][man.y-5+j]);
			}
		}

		for(i=0;i<5;i++)
			printf("%c",field[man.x-5+j][man.y]);
			
		for(j=6;j<11;j++){
			for(i=0;i<11;j++){
				printf("%c",field[man.x-5+j][man.y-5+j]);
			}
		}
	}

//move
	int move(){
		char input[5];

		while(1){
			if(kbhit()){
				sprintf(input,"%s",getch());
				if(strcmp(input,'潼')==0 || strcmp(input,'d')==0){
					man.x++;
					break;
				}
				else if(strcmp(input,'潭')==0 || strcmp(input,'a')==0){
					man.x--;
					break;
				}
				else if(strcmp(input,'澑')==0 || strcmp(input,'s')==0){
					man.y++;
					break;
				}
				else if(strcmp(input,'潯')==0 || strcmp(input,'w')==0){
					man.y--;
					break;
				}
			}
		}







/*	int CheckStatus(int x,int y){
		if(strcmp(field[x][y],'0')==0)		return 0;
		else if(strcmp(field[x][y],'1')==0)	return 1;
		return -1;
	}
*/
