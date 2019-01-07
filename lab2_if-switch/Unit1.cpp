//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
       Edit1->Text="0";
       Edit2->Text="0";
       Edit3->Text="0";
       Memo1->Clear();
       Memo1->Lines->Add("Lab2");
       RadioGroup1->ItemIndex = 0;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double a,b,x,y,z,fx;
        bool wrongX = false;
	a=StrToFloat(Edit1->Text);
        b=StrToFloat(Edit2->Text);
        x=StrToFloat(Edit3->Text);

        // Check RadioGroup
        switch(RadioGroup1->ItemIndex){
                case 0: fx = 2*x;
                        Memo1->Lines->Add("f(x)= 2x");
                        break;
                case 1: fx = pow(x,2);
                        Memo1->Lines->Add("f(x)= x^2");
                        break;
                case 2: fx= x/3;
                        Memo1->Lines->Add("f(x)= x/3");
                        break;
        }

        // Checkbox
        if (CheckBox1->Checked){

        }
        if(CheckBox2->Checked) {
               if(x < 0){
               } else {
                 Memo1->Lines->Add("Wrong X. Please use X from range x = z < 0;");
                 wrongX = true;
               }
        }
        if(CheckBox3->Checked) {
               if(x >= -1 && x <= 1){
               } else {
                 Memo1->Lines->Add("Wrong X. Please use X from range x = sin(z)");
                 wrongX = true;
               }
        }
        if(CheckBox4->Checked) {
               if(x >= 0){
               } else {
                 Memo1->Lines->Add("Wrong X. Please use X from range x = z >= 0");
                 wrongX = true;
               }
        }

        if(!wrongX){
                y = 2 * a * pow(sin(x), 2) / 3  - 3 * b / 4 * pow(cos(fx), 2);
                Memo1->Lines->Add("result: " + FloatToStr(y));
        }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo1->Clear();    
}
//---------------------------------------------------------------------------

