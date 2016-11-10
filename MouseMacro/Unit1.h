//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TLabel *Label3;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TButton *Kaydet;
	TButton *Yükle;
	TLabel *Label4;
	TEdit *Edit3;
	TLabel *Label5;
	TEdit *Edit4;
	TTimer *Timer2;
	TEdit *Edit5;
	TButton *Button1;

	TCheckBox *CheckBox1;
	TMemo *Memo1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall KaydetClick(TObject *Sender);
	void __fastcall YükleClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ListBox1DblClick(TObject *Sender);
	void __fastcall ListBox2DblClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
