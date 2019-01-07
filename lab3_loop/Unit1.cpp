//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
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
     Edit1->Text="0,1";       	Edit2->Text="1,0";
     Edit3->Text="10";        	Edit4->Text="0,2";
     Memo1->Clear();
     Memo1->Lines->Add("Lab 3");
}
//---------------------------------------------------------------------------

long double fact(int N)
        {
        if(N < 0)
                return 0;
        if (N == 0)
                return 1;
        else
                return N * fact(N - 1);
        };

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double a, b, x, h, r, sum, y, moduleSY;
        int n, k;
	a = StrToFloat(Edit1->Text);
	b = StrToFloat(Edit2->Text);
	n = StrToInt(Edit3->Text);
	h = StrToFloat(Edit4->Text);

        for(x = a; x<=b; x+=h) {
                r = sum = 0;
                for(k = 1; k<=n; k++) {
                        r = (2 * k + 1)/fact(k) * pow(x, 2*k);
                        sum+=r;
                }
                Memo1->Lines->Add("When x= "+FloatToStrF(x,ffFixed,8,2)
                        +" sum = "+FloatToStrF(sum,ffFixed,8,5));

                y = (1 + 2 * pow(x, 2)) * exp(pow(x, 2));
                Memo1->Lines->Add("Y = "+FloatToStrF(y,ffFixed,8,2));

                moduleSY = fabs(sum - y);
                Memo1->Lines->Add("|S(x) - Y(x)| = "+FloatToStrF(moduleSY,ffFixed,8,2));
        }




}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------
