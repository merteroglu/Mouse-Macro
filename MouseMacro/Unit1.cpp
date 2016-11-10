//---------------------------------------------------------------------------
#define _WIN32_WINT 0x0500
#include <vcl.h>
#pragma hdrstop
#include <windows.h>
#include "Unit1.h"
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

POINT p;
HWND window = FindWindow(0,"Legend Online");
DWORD wPID;
HANDLE wHandle;
BOOL Durum = FALSE;

void CheckCursorPos(){
GetCursorPos(&p);
}

void LclickDown(){
mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
}

void LclickUp(){
mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void Wait(int seconds){
clock_t endwait;
endwait = clock () + seconds * CLOCKS_PER_SEC;
while(clock() < endwait){}
}

void wait2(int miliseconds){
clock_t endwait;
endwait = clock () + miliseconds;
while(clock() < endwait){}
}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
GetCursorPos(&p);
Edit1->Text = p.x;
Edit2->Text = p.y;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Lines->Add("------------PaxweL Cursor Macro-----------");
Memo1->Lines->Add("Programý Duraklatmak için P tuþuna Basýn");
Memo1->Lines->Add("------------------------------------------");


   if(window){
   GetWindowThreadProcessId(window,&wPID);
   wHandle = OpenProcess(PROCESS_ALL_ACCESS,FALSE,wPID);
   SendMessage(window,WM_SETTEXT,0,(LPARAM)"PaxweL Cursor Macro");
   Memo1->Lines->Add("Caption Deðiþtirildi");
   }else{
	Memo1->Lines->Add("Legend Online Bulunamadý!");
   }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
if(GetAsyncKeyState('A')){
ListBox1->Items->Add(Edit1->Text);
ListBox2->Items->Add(Edit2->Text);
Memo1->Lines->Add("Koordinatlar Eklendi " + Edit1->Text+","+Edit2->Text);
}



}
//---------------------------------------------------------------------------

void __fastcall TForm1::KaydetClick(TObject *Sender)
{
if(ListBox1->GetCount() == 0 || ListBox2->GetCount() == 0 ) {
Memo1->Lines->Add("Koordinatlar Boþ Býrakýlamaz");
}else{
ListBox1->Items->SaveToFile("koorX.dat");
ListBox2->Items->SaveToFile("koorY.dat");
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::YükleClick(TObject *Sender)
{
ListBox1->Items->LoadFromFile("koorX.dat");
ListBox2->Items->LoadFromFile("koorY.dat");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

 if(ListBox1->GetCount() == 0 || ListBox2->GetCount() == 0 ) {
  Memo1->Lines->Add("Koordinatlar Boþ Býrakýlamaz");
   }else{
   Memo1->Lines->Add("Döngü Hazýrlanýyor");
	 ListBox1->ItemIndex = 0;
	 ListBox2->ItemIndex = 0;
	 Form1->ClientHeight = 91;
	 Memo1->Top = 2;
	 Form1->FormStyle = fsStayOnTop;
	 Wait(Edit3->Text.ToInt());
	 int x = 1,Dongu = Edit4->Text.ToInt() * ListBox1->Count;
	  int KoorX,KoorY;

	 while(x<=Dongu){

	 if(GetAsyncKeyState('P')){
	 Memo1->Lines->Add("Program Durduruldu");
	 Form1->ClientHeight = 295;
	 Memo1->Top = 204;
	 Form1->FormStyle = fsNormal;
	 break;
	 }

	  KoorX = ListBox1->Items->Strings[ListBox1->ItemIndex].ToInt();
	  KoorY = ListBox2->Items->Strings[ListBox2->ItemIndex].ToInt();
	  SetCursorPos(KoorX,KoorY);

	  if(CheckBox1->Checked == True){
	  wait2(500);
	  }else{
	  Wait(Edit3->Text.ToInt());
	  }

	  LclickDown();
	  LclickUp();
	  x++;
	  Edit5->Text = x/ListBox1->Count;
	  if(ListBox1->ItemIndex==0){
	  Memo1->Lines->Add(Edit5->Text + ".Döngü" );
	  }
	   if(CheckBox1->Checked == True){
	  wait2(500);
	  }else{
	  Wait(Edit3->Text.ToInt());
	  }


	  if(ListBox1->ItemIndex != ListBox1->Items->Count - 1){
	   ListBox1->ItemIndex++;
	   ListBox2->ItemIndex++;

	  }else{
	   ListBox1->ItemIndex = 0;
	   ListBox2->ItemIndex = 0;
	  }


	 }


	}




}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TForm1::ListBox1DblClick(TObject *Sender)
{
ListBox1->DeleteSelected();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox2DblClick(TObject *Sender)
{
   ListBox2->DeleteSelected();
}
//---------------------------------------------------------------------------

