//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
 int n = 10;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

        randomize();
        Edit1->Text=IntToStr(n);
        StringGrid1->ColCount=n;
        for(int i=0; i<n;i++)
                StringGrid1->Cells[i][0] = IntToStr(random(21)-10);
        Label3->Hide();
        StringGrid2->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
       n=StrToInt(Edit1->Text);
        if(n>10){
                ShowMessage("Max is 10!");
                n=10;
                Edit1->Text = "10";
        }
        StringGrid1->ColCount=n;
        for(int i=0; i<n;i++)
                StringGrid1->Cells[i][0]=IntToStr(random(21)-10);
        Label3->Hide();
        StringGrid2->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int i, a[10], b=0;
        int resIndex = 0, firstNegativeIndex = -1, secondNegativeIndex = -1;
        int res[10];

        for(i=0; i<n;i++)
              a[i]=StrToInt(StringGrid1->Cells[i][0]);


        for(i=0; i<n;i++){
              if(firstNegativeIndex <0 && a[i] <0) {
                  firstNegativeIndex = i;
              }
              if(firstNegativeIndex !=i && secondNegativeIndex <0 && a[i] <0) {
                 secondNegativeIndex = i;
              }
        }

        if(firstNegativeIndex >=0 && secondNegativeIndex >=0 && (secondNegativeIndex - firstNegativeIndex) != 1){
                for (i=firstNegativeIndex+1; i<secondNegativeIndex;i++) {

                        res[resIndex] = a[i];
                        resIndex++;

                }
                for(i=0; i<resIndex;i++) b+=res[i];
                StringGrid2->ColCount = resIndex;
                StringGrid2->Show();
                Label3->Show();
                Label3->Caption = "Result: " + IntToStr(b);
                for(i=0; i<resIndex;i++) StringGrid2->Cells[i][0]=IntToStr(res[i]);
        }else {
                StringGrid2->Hide();
                Label3->Show();
                Label3->Caption = "No numbers apply the condition!";
        }


}
//---------------------------------------------------------------------------
