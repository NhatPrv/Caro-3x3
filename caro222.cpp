#include <winbgim.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>


using namespace std;

void dauX(int x,int y, int color)  {  // hinh dau nhan
	setcolor(color);
	x=101*(x/100)+24;
	y=101*(y/100)+24;
	line(x+1,y,x+50,y+49);
	line(x,y,x+50,y+50);
	line(x,y+1,x+49,y+50);	
	
	line (x+49,y,x,y+49);
	line (x+50,y,x,y+50);
	line (x+50,y+1,x+1,y+50);
}
void re_draw_win(int x, int y) {
	
}

void dauO(int x,int y, int color)  {  // hinh tron
	setcolor(color);
	x=101*(x/100)+49;
	y=101*(y/100)+49;
	circle(x,y,25);
	circle(x,y,24);
	circle(x,y,26);
}
 
int main(){
	int Atd[3][3];
	int i,j;
	for (int a=0;a<3;a++)  {
		for (int b=0;b<3;b++)
		{
			Atd[a][b]=0;
		}
	}
	int count_click = 0;
    initwindow(500,500);	//kick thuoc khung hinh
    int x,y;
	setbkcolor(7);//mau background
    cleardevice();  
	bool is_win = false;
	string obj_win;
	while (1) { // Luu ý câu while này nhé ! tuc la chuong trinh cua chu dang lap di lap lai 1 vong lap => nhung bien nao duoc khai bao trong vong while nay se bi khai bao lai. dan den viec khong the luu tru bien duoc
		delay(0.0001);
		
		int n=3;
		int x=100;
		int y=100;
		int x1=200;
		int y1=200;
		setcolor(15);
		outtextxy(202,50,"DEMO CARO");
	
		setcolor(0);//mau ban co	
		rectangle(99,99,403,403);//ve vien ngoai
		rectangle(98,98,404,404);//ve vien ngoai
		rectangle(97,97,405,405);//ve vien ngoai
		
		
		for (i=1;i<=3;i++){  //ve ban 3x3
			for (j=0;j<3;j++)  {
				rectangle (x,y,x1,y1);
				x+=101;
				x1+=101;
				
			}
			y+=101;
			y1+=101;
			x-=101*n;
			x1-=101*n;
		}
		if(is_win == false){
						//mouse clicker event			
			if (ismouseclick(WM_LBUTTONUP)){   
		       	getmouseclick(WM_LBUTTONUP, x, y);			
				//printf("%d", count_click);
				
	           	if(x<=100 || x>=403 || x==200 || x==201 || x==302 || x==303 || y<=100 || y>=403 || y==200 || y==201 || y==302 || y==303)
	           	{
				}
				else {
					if (Atd[y/100-1][x/100-1]==0) {// xac dinh coi o do da duoc danh hay chua
						if(count_click < 9) {    
							if(count_click %2==0)  {
								Atd[y/100-1][x/100-1]=2; // 2 la dau x
								dauX(x,y,4);
							//	break;
							}
							else {
								Atd[y/100-1][x/100-1]=1;
								dauO(x,y,6); // 1 la y
								//	break;
							}
							int tdx = x/100-1;
							int tdy = y/100-1;
							int check_number = (count_click %2==0) ? 2 : 1;
							int count_trung = 0;
							
							// kiem tra tu diem x,y co ton tai 1 truong hop win nao khong
							// kiem tra cheo trai
							for (i=0;i<3;i++) {
								if(Atd[i][i]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
							}
							// kiem tra cheo phai
							count_trung = 0;
							for (i=0;i<3;i++) {
								if(Atd[2-i][i]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
							}
							// kiem tra doc
							count_trung = 0;
							for (i=0;i<3;i++) {
								if(Atd[i][tdx]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
								for (i=0;i<3;i++) {
									
									if (check_number==2) {
										dauX((tdx+1)*100,(i+1)*100,1);
										cout << "Dau moi2";
									}
								}
							}
							
							// kiem tra ngang
							count_trung = 0;
							for (i=0;i<3;i++) {
								if(Atd[tdy][i]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
							}
							
							count_click ++;
							
							
							if(is_win == true) {
								obj_win = check_number == 2 ? 'X' : 'O';
								string msg="Chuc mung " + obj_win + " da chien thang ! ";
								char p[msg.length()];
								for (i=0;i<msg.length();i++) {
									p[i]=msg[i];
								}
								
								cout << p;
								
								setcolor(0);
								int w=8*msg.length();
								outtextxy(250-w/2,425,p);
								if (kbhit) {
									break;
								}
							}
						} else {
						cout <<"Con o nua dau ma danh";
						if (kbhit){
							break;
						}
						}	
					}
				}
			}
		}	
	//}
	}
	
    system("pause");
    closegraph();
}
