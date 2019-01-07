//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        long double x;
        double z,y,a,b,c,rez;
        // x = StrToFloat(Edit1->Text);
        // y = StrToFloat(Edit2->Text);
        // z = StrToFloat(Edit3->Text);
        cout << " Enter x,y and z:" << endl;
        cout << " X = " << endl;
        cin >> x;
        cout << " Y = " << endl;
        cin >> y;
        cout << " Z = " << endl;
        cin >> z;


        a = pow(x, 1.0 / 3.0) + pow(x, y+2);
        b = pow(asin(z),2);
        c = fabs(x-y);

        rez = sqrt(10*a)*(b - c);

        // The result as in example (40.630694) can't be positive since |x-y| is bigger than asin2(z),
        // and the right part of the expression will be always negative, while left will be always positive

        cout << "\nx=" << x << "\ny=" << y << "\nz=" << z << "\nResult=" << rez << endl;
        cout << " Press any key ... " << endl;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 