//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GBCameraPic"
#pragma link "GBCameraPic"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Application->Title="GBCamera Dump";

    Bitmap= new Graphics::TBitmap();
    Bitmap->Width=32;
    Bitmap->Height=840;
    Bitmap->PixelFormat=pf4bit;
    Bitmap->Canvas->FillRect(Rect(0,0,32,840));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadSaveRam1Click(TObject *Sender)
{
    if (od->Execute())
        {
        GBPic->LoadSaveRam(od->FileName);
        Bitmap->Assign(GBPic->GetPreviewStrip());
        GameFace->Canvas->Draw(0,0,GBPic->DrawGameFace());
        GBPic->PictureNumber=1;
        }
    Grid->Invalidate();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveCurrentPicture1Click(TObject *Sender)
{
    if (sd->Execute())
        {
        GBPic->SaveCurrentPicture(sd->FileName);
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveAllPictures1Click(TObject *Sender)
{
    if (sd->Execute())
        {
        AnsiString File=sd->FileName;
        File.Delete(File.Length() -3,4);

        for (int x=1; x<=30;x++)
            {
            GBPic->PictureNumber=x;
            GBPic->SaveCurrentPicture(AnsiString(File + File.FormatFloat("00",x) + ".bmp"));
            }
        }
    GBPic->PictureNumber=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GridSelectCell(TObject *Sender, int Col, int Row,
      bool &CanSelect)
{
    GBPic->PictureNumber=(Row*6+Col)+1;
    gb->Caption= "Picture #" + IntToStr((Row*6+Col)+1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GridDrawCell(TObject *Sender, int Col, int Row,
      TRect &Rect, TGridDrawState State)
{
TRect rTile;
rTile.Left=0;
rTile.Top=(Row*6+Col)*28;
rTile.Right=32;
rTile.Bottom=(Row*6+Col)*28+28;
Grid->Canvas->CopyRect(Rect,Bitmap->Canvas,rTile);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveGameFace1Click(TObject *Sender)
{
    if (sd->Execute())
        {
        GBPic->SaveGameFace(sd->FileName);
        }
}
//---------------------------------------------------------------------------

