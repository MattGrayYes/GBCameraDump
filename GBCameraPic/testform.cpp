//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "testform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    GBCameraPic= new TGBCameraPic(this);
    GBCameraPic->Parent=this;
    GBCameraPic->LoadSaveRam("c:\\gb_transferer_camera.sav");
    GBCameraPic->PictureNumber=1;

    Bitmap = new Graphics::TBitmap();
    Bitmap->Width=32;
    Bitmap->Height=840;
    Bitmap->PixelFormat=pf4bit;
    Bitmap->Assign(GBCameraPic->GetPreviewStrip());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
Image1->Canvas->Draw(0,0,GBCameraPic->DrawGameFace());  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
GBCameraPic->PictureNumber=TrackBar1->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int Col,
      int Row, TRect &Rect, TGridDrawState State)
{
TRect rTile;
rTile.Left=0;
rTile.Top=(Row*5+Col)*28;
rTile.Right=32;
rTile.Bottom=(Row*5+Col)*28+28;
DrawGrid1->Canvas->CopyRect(Rect,Bitmap->Canvas,rTile);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int Col,
      int Row, bool &CanSelect)
{
GBCameraPic->PictureNumber=(Row*5+Col)+1;    
}
//---------------------------------------------------------------------------

