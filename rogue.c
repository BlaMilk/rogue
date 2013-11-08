//ヘッダファイル
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//define
#define DispArea 15	//表示領域(display area)をn*nサイズにする
#define radius (DispArea-1)/2
//座標の構造体
struct xy{
	int x;
	int y;
}man;

//グローバル変数宣言
int field[200][200]={};

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
					field[j+radius][i+radius]=(int)read[j]-'0';
				else 
					field[j+radius][i+radius]=0;
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
		printf("************************\n");
		printf("* 　座標　 : x=%d Y=%d *\n",man.x,man.y);
		printf("* 出力領域 :  %2d×%2d   *\n",DispArea,DispArea);
		printf("************************\n\n");
		for(j=0;j<radius;j++){
			for(i=0;i<DispArea;i++){
				figure(field[man.x-radius+i][man.y-radius+j]);
			}
			printf("\n");
		}

		for(i=0;i<radius;i++)
			figure(field[man.x-radius+i][man.y]);

		printf("☆");	//主人公

		for(i=radius+1;i<DispArea;i++)
			figure(field[man.x-radius+i][man.y]);

		printf("\n");
			
		for(j=radius+1;j<DispArea;j++){
			for(i=0;i<DispArea;i++){
				figure(field[man.x-radius+i][man.y-radius+j]);
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


