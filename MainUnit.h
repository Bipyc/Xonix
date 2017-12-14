//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Config.h"
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <iostream>

//---------------------------------------------------------------------------

enum EDirection{
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4   //можно не присваивать 2 3 4
};

#define COUNT_ETILEBITMAP 7
enum ETileBitmap{
	FIELD = 0,
	PATH = 1,
	WALL = 2
};

DWORD __stdcall playMusic();

class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *labelLevel;
	TLabel *labelProgress;
	TLabel *labelScore;
	TImage *ShareVkImage;
	TImage *ShareTwitterImage;
	TImage *ShareFacebookImage;
	TTimer *timerMovement;
	TPanel *Panel1;
	TShape *shapePlayer;
	TImage *imageGameOver;
	TTimer *timerEnemy;
	TTimer *timerScore;
	void __fastcall timerMovementTimer(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall timerEnemyTimer(TObject *Sender);
	void __fastcall timerScoreTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------

class Grid
{
public:
	Grid();
	~Grid();
	int rowsCount, columnsCount, tileSize;
	int width, height, lastColumn, lastRow, countWall;
	int grid[HEIGHT_FIELD][WIDTH_FIELD];
} grid;


void drop(int y, int x);

class Enemy
{
public:
	int x,y,dx,dy;
    TImage* image;
	Enemy();
	void move();
};

class SpritePlayer
{
public:
	SpritePlayer();
	~SpritePlayer();
	void setDirection(EDirection direction);
	void calcNextPosition();
	void loadSprite(const char *path);
	void stopMove();
	void setSpeed(unsigned char speed);
	void setNewGame();
	Graphics::TBitmap* images[ COUNT_ETILEBITMAP ];
	TImage* enemyImage;
	Graphics::TBitmap* pathBitmap;
	Graphics::TBitmap* xonixBitmap;
	Graphics::TBitmap* wallBitmap;
	Graphics::TBitmap* fieldBitmap;
	Graphics::TBitmap* tempBitmap;
	Graphics::TBitmap* srcBitmap;
	unsigned int getLevel();
	unsigned int getScore();
	unsigned int getProgress();
	void timerScore();
	int x,y;  //[x][y]
	bool isGame;
	int enemyCount;
    ETileBitmap currentTile, oldTile;

private:
	void setNextLevel();
	int score_, level_, progress_;
	POINT vector_;
	bool isMoves_;
	char direction_;
	unsigned char speed_;
};

#endif
