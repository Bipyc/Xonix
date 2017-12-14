//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

SpritePlayer player1;
Enemy a[20];
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


Grid::Grid() {
	columnsCount = WIDTH_FIELD;
	rowsCount = HEIGHT_FIELD;
	tileSize = TILE_SIZE;

	lastColumn = (WIDTH_FIELD - 1) * TILE_SIZE;
	lastRow = (HEIGHT_FIELD - 1) * TILE_SIZE;

	width = WIDTH_FIELD * TILE_SIZE;
	height = HEIGHT_FIELD * TILE_SIZE;
	memset(grid, 0, sizeof(grid));
};

void drop(int x, int y)
{
// допилить
//	while (true) {
//
//	}
	if (grid.grid[x][y]==0) grid.grid[x][y]=-1;
	if (grid.grid[x-1][y]==0) drop(x-1,y);
	if (grid.grid[x+1][y]==0) drop(x+1,y);
	if (grid.grid[x][y-1]==0) drop(x,y-1);
	if (grid.grid[x][y+1]==0) drop(x,y+1);
}

Grid::~Grid() {

}

SpritePlayer::SpritePlayer()
{
	pathBitmap = new Graphics::TBitmap;
	xonixBitmap = new Graphics::TBitmap;
	wallBitmap = new Graphics::TBitmap;

	fieldBitmap = new Graphics::TBitmap;
	fieldBitmap->SetSize(grid.width, grid.height);
	fieldBitmap->Canvas->Brush->Color = RGB(203,170,150);

	TRect rect;
	rect.Right = grid.tileSize;
	rect.Bottom = grid.tileSize;
	fieldBitmap->Canvas->FillRect(rect);
	tempBitmap = new Graphics::TBitmap;
	tempBitmap->SetSize(grid.width, grid.height);
	srcBitmap = new Graphics::TBitmap;
	srcBitmap->SetSize(grid.width, grid.height);

	wallBitmap->LoadFromFile("images/wall.bmp");
	xonixBitmap->LoadFromFile("images/xonix.bmp");
    pathBitmap->LoadFromFile("images/path.bmp");

	SpritePlayer::setNewGame();
}

void SpritePlayer::loadSprite(const char *path)
{
}

void SpritePlayer::setNextLevel()
{
	SpritePlayer::stopMove();
	x = 0;
	y= grid.columnsCount / 2 * grid.tileSize; //Set position in the center
	for (int i = 0; i < grid.rowsCount; ++i)
	{
		grid.grid[i][0] = grid.grid[i][grid.columnsCount - 1] = WALL;
	}
	for (int i = 1; i < grid.columnsCount - 1; ++i)
		grid.grid[0][i] = grid.grid[grid.rowsCount - 1][i] = WALL;
	for (int i = 1; i < grid.rowsCount - 1; ++i) {
		for (int j = 1; j < grid.columnsCount - 1; ++j) {
			grid.grid[i][j] = FIELD;
		}
	}
	++level_;
	++enemyCount;
	currentTile = WALL;
    oldTile = WALL;
}

void SpritePlayer::setNewGame()
{
	score_ = 0;
	level_ = 0;
	enemyCount = 3;
    isGame = true;
	SpritePlayer::setNextLevel();
}

SpritePlayer::~SpritePlayer()
{
}

void SpritePlayer::setDirection(EDirection direction)
{
	this->direction_ = direction;
}

void SpritePlayer::setSpeed(unsigned char speed)
{
	this->speed_ = speed;
}

void SpritePlayer::stopMove()
{
	isMoves_ = false;
	vector_.x = vector_.y = 0;
	direction_ = 0;
}

unsigned int SpritePlayer::getLevel()
{
	return  level_;
}

unsigned int SpritePlayer::getProgress()
{
	return progress_;
}

unsigned int SpritePlayer::getScore()
{
	return score_;
}

void SpritePlayer::timerScore()
{
	--score_;
	if (score_ < 0) {
        score_ = 0;
	}
    progress_ = grid.countWall / (grid.columnsCount * grid.rowsCount);
}

void SpritePlayer::calcNextPosition()
{
	bool isInTile = ((x % grid.tileSize) == 0) && ((y % grid.tileSize) == 0);
	int curX, curY;
	if (isInTile) {
		curX= player1.x / grid.tileSize;
		curY = player1.y / grid.tileSize;
		if ((grid.grid[curX][curY] == PATH)) {
			player1.isGame = false;
			return;
		}
		if (grid.grid[curX][curY] == FIELD)
		{
			grid.grid[curX][curY] = PATH;
		}
		if (direction_) {
			switch (direction_) {
			case UP:
				this->vector_.x = -speed_;
				this->vector_.y = 0;
				isMoves_ = true;
				break;
			case RIGHT:
				this->vector_.x = 0;
				this->vector_.y = speed_;
				isMoves_ = true;
				break;
			case DOWN:
				this->vector_.x = speed_;
				this->vector_.y = 0;
				isMoves_ = true;
				break;
			case LEFT:
				this->vector_.x = 0;
				this->vector_.y = -speed_;
				isMoves_ = true;
				break;
			default:
				;
			}
			direction_ = 0;
		}
	}

	if ( !isMoves_ ) {
		return;
	}
	x += vector_.x;
	if (x < 0) {
		isMoves_ = false;
		x = 0;
	}
	if (x > grid.lastRow) {
		isMoves_ = false;
		x = grid.lastRow;
	}

	y += vector_.y;
	if (y < 0) {
		isMoves_ = false;
		y = 0;
	}
	if (y > grid.lastColumn) {
		isMoves_ = false;
		y = grid.lastColumn;
	}
	isInTile = ((x % grid.tileSize) == 0) && ((y % grid.tileSize) == 0);
	if (isInTile) {
		curX = player1.x / grid.tileSize;
		curY = player1.y / grid.tileSize;
        if ((grid.grid[curX][curY] == WALL) && (oldTile == FIELD)) {
			for (int i=0; i < player1.enemyCount; ++i)
				drop((a[i].x + 20)/grid.tileSize, (a[i].y + 20)/grid.tileSize);

			for (int i = 0; i<grid.rowsCount; ++i)
				for (int j = 0; j<grid.columnsCount; ++j)
					if (grid.grid[i][j]==-1)
						grid.grid[i][j]=FIELD;
					else if (grid.grid[i][j]==FIELD) {
						grid.grid[i][j]=WALL;
                        ++score_;
                    }
					else if (grid.grid[i][j] == PATH) {
						++score_;
						grid.grid[i][j]=WALL;
					}

			MainForm->Invalidate();
		}
		oldTile = currentTile;
		currentTile = grid.grid[curX][curY];
	}
}
Enemy::Enemy()
{
	image = new TImage (Application);
	image->Picture->LoadFromFile("images/enemy.png");
	x = TILE_SIZE + rand()%((HEIGHT_FIELD - 2) * TILE_SIZE);
	y = TILE_SIZE + rand()%((WIDTH_FIELD - 2) * TILE_SIZE);
	dx=SPEED_ENEMY/2-rand()%SPEED_ENEMY;  //4 8
	if (!dx) {
        ++dx;
	}
	dy=SPEED_ENEMY/2-rand()%SPEED_ENEMY;
	if (!dy) {
        ++dy;
	}
}

void Enemy::move()
{
    x+=dx;
	if (grid.grid[(x + 20)/grid.tileSize][(y + 20)/grid.tileSize]==WALL)
	{
		dx=-dx;
		x+=dx;
	}

	y+=dy;
	if (grid.grid[(x + 20)/grid.tileSize][(y + 20)/grid.tileSize]==WALL)
	{
		dy=-dy;
		y+=dy;
	}
}

void __fastcall TMainForm::timerMovementTimer(TObject *Sender)
{
	if (!player1.isGame) {
		MainForm->timerEnemy->Enabled = false;
		MainForm->imageGameOver->Visible = true;
		MainForm->Invalidate();
		return;
	}
	player1.calcNextPosition();
	shapePlayer->Left = player1.y;
	shapePlayer->Top = player1.x;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::timerEnemyTimer(TObject *Sender)
{
	for (int i = 0; i < player1.enemyCount; ++i)
	{
		a[i].move();
		a[i].image->Left = a[i].y;
		a[i].image->Top = a[i].x;
		a[i].image->Invalidate();
		if  (grid.grid[(a[i].x + 20) / grid.tileSize][(a[i].y + 20)/ grid.tileSize] == PATH) {
			player1.isGame = false;
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormPaint(TObject *Sender)
{
	for (int i = 0; i < grid.rowsCount; ++i) {
		for (int j = 0; j < grid.columnsCount; ++j) {
			switch (grid.grid[i][j]) {
			case WALL:
				MainForm->Canvas->Draw(j*grid.tileSize, i*grid.tileSize,
					player1.wallBitmap);
				break;
			case FIELD:
				MainForm->Canvas->Draw(j*grid.tileSize, i*grid.tileSize,
					player1.fieldBitmap);
				break;
			case PATH:
           		MainForm->Canvas->Draw(j*grid.tileSize, i*grid.tileSize,
					player1.pathBitmap);
				break;
			default:;
			}
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    switch (Key) {
	case VK_UP:
		player1.setDirection(UP);
		break;
	case VK_RIGHT:
		player1.setDirection(RIGHT);
		break;
	case VK_DOWN:
		player1.setDirection(DOWN);
		break;
	case VK_LEFT:
		player1.setDirection(LEFT);
		break;
	case 'W':
		player1.setDirection(UP);
		break;
	case 'D':
		player1.setDirection(RIGHT);
		break;
	case 'S':
		player1.setDirection(DOWN);
		break;
	case 'A':
		player1.setDirection(LEFT);
		break;
	default:
		if (!player1.isGame) {
			MainForm->imageGameOver->Visible = false;
            MainForm->timerEnemy->Enabled = true;
			player1.setNewGame();
			labelLevel->Caption = "Level: 1";
            MainForm->Invalidate();
			return;
		};
	}
}

DWORD __stdcall playMusic()
{
  while (true)
  {
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
	Beep(370, 500);
    Beep(417, 500);
    Beep(497, 500);
    Sleep(500);
    Beep(497, 500);
    Beep(277, 500);
    Beep(277, 500);
    Beep(440, 500);
    Beep(440, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);

		 /*     int a = 750;

     Beep(392, a);
     Beep(392, a);
     Beep(392, a);
     Beep(311, a*0.75);
     Beep(466, a*0.25);

     Beep(392, a);
     Beep(311, a*0.75);
     Beep(466, a*0.25);
     Beep(392, a*2);

     Beep(587, a);
     Beep(587, a);
     Beep(587, a);
     Beep(622, a*0.75);
     Beep(466, a*0.25);

     Beep(369, a);
     Beep(311, a*0.75);
     Beep(466, a*0.25);
     Beep(392, a*2);




     //dfgfgdfg
     Beep(196, 400);
     Beep( 262, 800);
     Beep( 196, 600);
     Beep( 220,200 );
     Beep( 247, 800 );
     Beep( 165, 400 );
     Beep( 165, 400);
     Beep(220 , 800);
     Beep( 196, 600);
     Beep( 175 , 200);
     Beep(  196 , 800 );
     Beep(  131, 400);
     Beep(  131, 400);
     Beep( 147 , 800);
     Beep(  147, 400 );
     Beep(   165, 400);
     Beep(  175,800 ); */
     //  -l  -n -f  -l -n -f -l  -n -f  -l  -n -f 175 -l 400 -n -f 196 -l 400 -n -f 220 -l 800 -n -f 247 -l 400 -n -f 262 -l 400 -n -f 294 -l 1200 -n -f 196 -l 400 -n -f 330 -l 800 -n -f 294 -l 600 -n -f 262 -l 200 -n -f 294 -l 800 -n -f 247 -l 400 -n -f 196 -l 400 -n -f 262 -l 800 -n -f 247 -l 600 -n -f 220 -l 200 -n -f 247 -l 800 -n -f 165 -l 400 -n -f 165 -l 400 -n -f 220 -l 800 -n -f 196 -l 400 -n -f 175 -l 400 -n -f 196 -l 800 -n -f 131 -l 400 -n -f 131 -l 400 -n -f 262 -l 800 -n -f 247 -l 400 -n -f 220 -l 400 -n -f 196 -l 1600 -n -f 330 -l 1600 -n -f 294 -l 400 -n -f 262 -l 400 -n -f 247 -l 400 -n -f 262 -l 400 -n -f 294 -l 1200 -n -f 196 -l 400 -n -f 196 -l 1600 -n -f 262 -l 1600 -n -f 247 -l 400 -n -f 220 -l 400 -n -f 196 -l 400 -n -f 220 -l 400 -n -f 247 -l 1200 -n -f 165 -l 400 -n -f 165 -l 1600 -n -f 262 -l 800 -n -f 220 -l 600 -n -f 247 -l 200 -n -f 262 -l 800 -n -f 220 -l 600 -n -f 247 -l 200 -n -f 262 -l 800 -n -f 220 -l 400 -n -f 262 -l 400 -n -f 350 -l 1600 -n -f 350 -l 1600 -n -f 330 -l 400 -n -f 294 -l 400 -n -f 262 -l 400 -n -f 294 -l 400 -n -f 330 -l 1200 -n -f 262 -l 400 -n -f 262 -l 1600 -n -f 294 -l 1600 -n -f 262 -l 400 -n -f 247 -l 400 -n -f 220 -l 400 -n -f 247 -l 400 -n -f 262 -l 1200 -n -f 220 -l 400 -n -f 220 -l 1600 -n -f 262 -l 800 -n -f 247 -l 400 -n -f 220 -l 400 -n -f 196 -l 800 -n -f 131 -l 600 -n -f 131 -l 200 -n -f 196 -l 1600 -n -f 220 -l 800 -n -f 246 -l 800 -n -f 262 -l 3200
    Sleep(1000);
  }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	srand(time(NULL));
	MainForm->ClientWidth = WIDTH_FIELD * TILE_SIZE;
	MainForm->ClientHeight = HEIGHT_FIELD * TILE_SIZE + Panel1->Height + 1;
	player1.stopMove();
	player1.loadSprite("images/enemy.bmp");
	player1.setSpeed( SPEED_XONIX );

	for (int i = 0; i < player1.enemyCount; ++i)
	{
		a[i].image->Parent = MainForm;;
	}
	//HANDLE hPlayMusic = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)playMusic, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::timerScoreTimer(TObject *Sender)
{
	player1.timerScore();
	char tempStr[100];
	sprintf(tempStr,"Level: %d", player1.getLevel());
	labelLevel->Invalidate();
	labelLevel->Caption = tempStr;

	sprintf(tempStr,"Progress: %d%", player1.getProgress());
	labelProgress->Invalidate();
	labelProgress->Caption = tempStr;

	sprintf(tempStr,"Score: %d", player1.getScore());
	labelScore->Invalidate();
	labelScore->Caption = tempStr;
}
//---------------------------------------------------------------------------

