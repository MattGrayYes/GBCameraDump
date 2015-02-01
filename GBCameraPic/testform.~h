//---------------------------------------------------------------------------
#ifndef testformH
#define testformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "GBCameraPic.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTrackBar *TrackBar1;
    TDrawGrid *DrawGrid1;
    TImage *Image1;
    void __fastcall FormClick(TObject *Sender);
    void __fastcall TrackBar1Change(TObject *Sender);
    void __fastcall DrawGrid1DrawCell(TObject *Sender, int Col, int Row,
          TRect &Rect, TGridDrawState State);
    void __fastcall DrawGrid1SelectCell(TObject *Sender, int Col, int Row,
          bool &CanSelect);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    TGBCameraPic *GBCameraPic;
    Graphics::TBitmap *Bitmap;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
