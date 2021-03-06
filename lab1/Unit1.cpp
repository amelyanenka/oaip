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
        Edit1->Text = "16,55e-3";
        Edit2->Text = "-2,75";
        Edit3->Text = "0,15";
        Memo1->Clear();
        Memo1->Lines->Add("Lab1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        long double x;
        double z,y,a,b,c,rez;
        x = StrToFloat(Edit1->Text);
        y = StrToFloat(Edit2->Text);
        z = StrToFloat(Edit3->Text);

        a = pow(x, 1.0 / 3.0) + pow(x, y+2);
        b = pow(asin(z),2);
        c = fabs(x-y);

        rez = sqrt(10*a)*(b - c);

        Memo1->Lines->Add("When X = " + FloatToStr(x) + ";");
        Memo1->Lines->Add("Y = " + FloatToStr(y) + ";");
        Memo1->Lines->Add("Z = " + FloatToStr(z) + ";");
        Memo1->Lines->Add(" ... ");
        // The result as in example (40.630694) can't be positive since |x-y| is bigger than asin2(z),
        // and the right part of the expression will be always negative, while left will be always positive
        Memo1->Lines->Add("Result = "+FloatToStr(rez));
        Memo1->Lines->Add(" ");
}
//---------------------------------------------------------------------------
