//ヘッダファイル
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//define
#define DispArea 11	//表示領域(display area)をn*nサイズにする

//座標の構造体
struct xy{
	int x;
	int y;
}man;

//グローバル変数宣言
int field[100][100]={};

//関数宣言
void output(),SetMan();


//メイン関数
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
//「field.txt」からフィールドデータを「field[x][y]」に格納する
	int GetField(){
		FILE *fi;
		char read[100];
		int line;
		int i,j;

		fi=fopen("field.txt","r");

		fscanf(fi,"%d",&line);
		for(i=0;i<line;i++){
			fscanf(fi,"%s",read);
			for(j=0;j<strlen(read);j++){
				if('1'<=read[j] && read[j]<='9')
					field[j+5][i+5]=(int)read[j]-'0';
				else 
					field[j+5][i+5]=0;
			}
		}
		return line;
	}

//SetMan
//乱数で主人公のスタート位置を決める
	void SetMan(){
		do{
			man.x=rand()%95+5;
			man.y=rand()%95+5;
		}while(field[man.x][man.y]==0);
		printf("主人公の位置はx=%d,y=%dです\n",man.x,man.y);
	}

//output
//主人公周辺のマップを端末出力
	void output(){
		int i,j;
		int area=(DispArea-1)/2;	//表示領域を変更可能

		printf("x=%d Y=%d\n\n",man.x,man.y);

		for(j=0;j<5;j++){
			for(i=0;i<11;i++){
				figure(field[man.x-area+i][man.y-area+j]);
			}
			printf("\n");
		}

		for(i=0;i<5;i++)
			figure(field[man.x-area+i][man.y]);

		printf("☆");	//主人公

		for(i=6;i<11;i++)
			figure(field[man.x-area+i][man.y]);

		printf("\n");
			
		for(j=6;j<11;j++){
			for(i=0;i<11;i++){
				figure(field[man.x-area+i][man.y-area+j]);
			}
			printf("\n");
		}
	}

//move
//キーボードからの入力により主人公の位置を移動させる
	int move(){
		char input;

		while(1){
			if(kbhit()){
				input=getch();
				if(input=='d' && field[man.x+1][man.y]!=0){
					man.x++;
					break;
				}
				else if(input=='a' && field[man.x-1][man.y]!=0){
					man.x--;
					break;
				}
				else if(input=='s' && field[man.x][man.y+1]!=0){
					man.y++;
					break;
				}
				else if(input=='w' && field[man.x][man.y-1]!=0){
					man.y--;
					break;
				}
				else if(input=='e')exit(0);
			}
		}
	}

//figure
//数字に対応した図形を出力する
	int figure(int n){
		if(n==0)printf("■");
		else if(n==1)printf("　");
	}

//ShowField
//現在のマップ全体を出力する デバッグ用
	void ShowField(){
		int i,j;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++)
				figure(field[i][j]);
				printf("\n");
		}
	}


