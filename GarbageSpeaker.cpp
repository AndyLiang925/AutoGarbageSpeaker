#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
void toClipboard(HWND hwnd, const std::string &s);
void pst(int x = 86)
{
keybd_event(VK_CONTROL,0,0,0);
keybd_event(x,0,0,0);
    keybd_event(x,0,KEYEVENTF_KEYUP,0);
    keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
    keybd_event(13,0,0,0);
    keybd_event(13,0,KEYEVENTF_KEYUP,0);
}
void send(string txt){

    size_t len = strlen(txt.c_str());
	HWND hwnd = GetDesktopWindow();
	toClipboard(hwnd, txt);
	pst();

}
int num=6;
string a[1005];
int ver=0;
int main(){
	a[0]="�����·��ɿ�ܺ͹�";
	//a[0]="byd";
	a[1]="������v�����ߺ���";
	a[2]="�����������ǼҶ�����ؾ���";
	a[3]="�����̷۾Ϳ�����ɶ���ؾ�";
	a[4]="����ŵ���Ŀ����㿪�����";
	a[5]="���͸��������ط���ˮ";
	srand((unsigned)time(NULL));
	cout<<"Copyright 2023-2023 ErrorDesign v1.1"<<endl; 
	cout<<"�������ģʽ(���ո�ʼ�����ո����)��"<<endl<<"1.�ظ� �����·��ɿ�ܺ͹�"<<endl<<"2.���"<<endl<<"3.�޸�Ĭ�ϴʿ�"<<endl;
	cin>>ver;
	if(ver==3){
		cin>>a[0];
	} 
 	//Sleep(5000);
 	char c = 'A';
 	
 	
 	if(ver==1){
 		num=1;
	}
 	while(!GetAsyncKeyState(VK_SPACE)){
 		
	}
	Sleep(1000);
	while(1){
		if(GetAsyncKeyState(VK_SPACE)){
			break;
		}else{
			send(a[rand()%num]);
			Sleep(100);
		}
	}
	return 0; 
}

void toClipboard(HWND hwnd, const std::string &s){
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);//
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}
