//---------------------------------------------------------------------------
#ifndef GBCameraPicH
#define GBCameraPicH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TGBCameraPic : public TImage
{
private:
    Graphics::TBitmap *Picture;
    Graphics::TBitmap *Bitmap;
    Graphics::TBitmap *GameFace;

    Byte SaveRam[131072];
    TColor Clr[4];
    int FPictureNumber;

    void __fastcall DrawPic(int Number);

    void __fastcall SetPictureNumber(int Number);

protected:
public:
    __fastcall TGBCameraPic(TComponent* Owner);
    __fastcall ~TGBCameraPic(void);

    void __fastcall LoadSaveRam(const System::AnsiString Filename);
    void __fastcall SaveCurrentPicture(const System::AnsiString Filename);
    void __fastcall SaveGameFace(const System::AnsiString Filename);    Graphics::TBitmap* __fastcall GetPreviewStrip(void);
    Graphics::TBitmap* __fastcall DrawGameFace(void);

__published:
    __property int PictureNumber = {read=FPictureNumber,write=SetPictureNumber};
};
//---------------------------------------------------------------------------
#endif
