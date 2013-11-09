//�w�b�_�t�@�C��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//define
#define DispAreax 16
#define DispAreay 9	//�\���̈�(display area)��x*y�T�C�Y�ɂ���
#define radiusx (DispAreax-1)/2
#define radiusy (DispAreay-1)/2

//���W�̍\����
struct xy{
	int x;
	int y;
}man;

//�O���[�o���ϐ��錾
int field[200][200]={};

//�֐��錾
void output(),SetMan();


//���C���֐�
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
//�ufield.txt�v����t�B�[���h�f�[�^���ufield[x][y]�v�Ɋi�[����
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
					field[j+radiusx][i+radiusy]=(int)read[j]-'0';
				else 
					field[j+radiusx][i+radiusy]=0;
			}
		}
		return line;
	}

//SetMan
//�����Ŏ�l���̃X�^�[�g�ʒu�����߂�
	void SetMan(){
		do{
			man.x=rand()%95+5;
			man.y=rand()%95+5;
		}while(field[man.x][man.y]==0);
	}

//output
//��l�����ӂ̃}�b�v��[���o��
	void output(){
		int center;	//��l���ʒu�̃f�[�^��ۊ�
		int i,j;
		printf(" *   *   *   *   *   *   *\n");
		printf(" * �@���W�@ : x=%2d Y=%2d  *\n",man.x,man.y);
		printf(" * �\\���̈� :   %2d�~%2d   * \n",DispAreax,DispAreay);
		printf(" *   *   *   *   *   *   * \n\n");

		center=field[man.x][man.y];
		field[man.x][man.y]=9;
			
		for(j=0;j<DispAreay;j++){
			for(i=0;i<DispAreax;i++){
				figure(field[man.x-radiusx+i][man.y-radiusy+j]);
			}
			printf("\n");
		}

		field[man.x][man.y]=center;	//���ɒu���������f�[�^�����ɖ߂�
	}

//move
//�L�[�{�[�h����̓��͂ɂ���l���̈ʒu���ړ�������
	int move(){
		char input;

		while(1){
			if(kbhit()){
				input=getch();
				if(input=='d'&& field[man.x+1][man.y]!=0){
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
//�����ɑΉ������}�`���o�͂���
	int figure(int n){
		if(n==0)printf("��");
		else if(n==1)printf("�@");
		else if(n==9)printf("��");
	}

//ShowField
//���݂̃}�b�v�S�̂��o�͂��� �f�o�b�O�p
	void ShowField(){
		int i,j;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++)
				figure(field[i][j]);
				printf("\n");
		}
	}


