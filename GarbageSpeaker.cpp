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
	a[0]="阿萨德法律框架和过";
	//a[0]="byd";
	a[1]="撒发是v都不高耗能";
	a[2]="发哈肌肤的那家都舒服呢就那";
	a[3]="啊加奶粉就卡就那啥的呢就";
	a[4]="阿基诺发的看到你开发你的";
	a[5]="克劳福德是昆仑饭店水";
	srand((unsigned)time(NULL));
	cout<<"Copyright 2023-2023 ErrorDesign v1.1"<<endl; 
	cout<<"输入你的模式(按空格开始，按空格结束)："<<endl<<"1.重复 阿萨德法律框架和过"<<endl<<"2.随机"<<endl<<"3.修改默认词库"<<endl;
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
