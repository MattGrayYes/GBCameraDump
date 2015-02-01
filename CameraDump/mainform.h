//---------------------------------------------------------------------------
#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "GBCameraPic.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *LoadSaveRam1;
    TMenuItem *SaveCurrentPicture1;
    TMenuItem *SaveAllPictures1;
    TMenuItem *Exit1;
    TOpenDialog *od;
    TSaveDialog *sd;

    TMenuItem *SaveGameFace1;
    TGroupBox *gb;
    TGBCameraPic *GBPic;
    TMemo *Memo1;
    TGroupBox *Pictures;
    TDrawGrid *Grid;
    TImage *GameFace;
    void __fastcall Exit1Click(TObject *Sender);

    void __fastcall LoadSaveRam1Click(TObject *Sender);
    void __fastcall SaveCurrentPicture1Click(TObject *Sender);
    void __fastcall SaveAllPictures1Click(TObject *Sender);
    void __fastcall GridSelectCell(TObject *Sender, int Col, int Row,
          bool &CanSelect);
    void __fastcall GridDrawCell(TObject *Sender, int Col, int Row,
          TRect &Rect, TGridDrawState State);
    void __fastcall SaveGameFace1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
        Graphics::TBitmap *Bitmap;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 