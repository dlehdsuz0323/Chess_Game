#include "ChessPiecesManager.h"
#include "BitImageManager.h"
#include "BitImage.h"
#include "Map.h"
#include "Pieces.h"
#include "Pown.h"

ChessPiecesManager *ChessPiecesManager::inst = nullptr;

void ChessPiecesManager::Init(void)
{
	for (int i = 0; i < CHESS_PIECES_POWN_MAXNUMBER; i++)
	{
		cBPown[i].Init(i, 1, BLACK_PIECES);
		BlackPlayerPieces[i] = &cBPown[i];

		cWPown[i].Init(i, 6, WHITE_PIECES);
		WhitePlayerPieces[i] = &cWPown[i];
	}

			// BLACK PIECES

	//KNIGHT
	cBKnight[0].Init(1, 0, BLACK_PIECES);
	cBKnight[1].Init(6, 0, BLACK_PIECES);
	BlackPlayerPieces[8] = &cBKnight[0];
	BlackPlayerPieces[9] = &cBKnight[1];

	//BISHOP
	cBBishop[0].Init(2, 0, BLACK_PIECES);
	cBBishop[1].Init(5, 0, BLACK_PIECES);
	BlackPlayerPieces[10] = &cBBishop[0];
	BlackPlayerPieces[11] = &cBBishop[1];

	//Rook
	cBRook[0].Init(0, 0, BLACK_PIECES);
	cBRook[1].Init(7, 0, BLACK_PIECES);
	BlackPlayerPieces[12] = &cBRook[0];
	BlackPlayerPieces[13] = &cBRook[1];

	//QUEEN
	cBQueen.Init(3, 0, BLACK_PIECES);
	BlackPlayerPieces[15] = &cBQueen;

	//KING
	cBking.Init(4, 0, BLACK_PIECES);
	BlackPlayerPieces[14] = &cBking;



			// WHITE PIECES

	//KNIGHT
	cWKnight[0].Init(1, 7, WHITE_PIECES);
	cWKnight[1].Init(6, 7, WHITE_PIECES);
	WhitePlayerPieces[8] = &cWKnight[0];
	WhitePlayerPieces[9] = &cWKnight[1];

	//BISHOP
	cWBishop[0].Init(2, 7, WHITE_PIECES);
	cWBishop[1].Init(5, 7, WHITE_PIECES);
	WhitePlayerPieces[10] = &cWBishop[0];
	WhitePlayerPieces[11] = &cWBishop[1];

	//Rook
	cWRook[0].Init(0, 7, WHITE_PIECES);
	cWRook[1].Init(7, 7, WHITE_PIECES);
	WhitePlayerPieces[12] = &cWRook[0];
	WhitePlayerPieces[13] = &cWRook[1];

	//QUEEN
	cWQueen.Init(3, 7, WHITE_PIECES);
	WhitePlayerPieces[15] = &cWQueen;

	//KING
	cWKing.Init(4, 7, WHITE_PIECES);
	WhitePlayerPieces[14] = &cWKing;
}


void ChessPiecesManager::Draw(HDC hdc)
{
	for (int i = 0; i < CHESS_PLAYER_PIECES_MAXNUMBER; i++)
	{
		if (BlackPlayerPieces[i]->GetState() == LIVE)
		{
			BitImageManager::GetInstance()->Draw(hdc,
				BlackPlayerPieces[i]->GetTeam(),
				BlackPlayerPieces[i]->GetPieces(),					
				BlackPlayerPieces[i]->GetPoint()->x,
				BlackPlayerPieces[i]->GetPoint()->y);
		}
	}

	for (int j = 0; j < CHESS_PLAYER_PIECES_MAXNUMBER; j++)
	{
		if (WhitePlayerPieces[j]->GetState() == LIVE)
		{
			BitImageManager::GetInstance()->Draw(hdc,
				WhitePlayerPieces[j]->GetTeam(),
				WhitePlayerPieces[j]->GetPieces(),
				WhitePlayerPieces[j]->GetPoint()->x,
				WhitePlayerPieces[j]->GetPoint()->y);
		}
	}
}

Pieces*	 ChessPiecesManager::LMouseButtonDown(POINT * SelectPoint,int *iGameState)
{
	if (SelectPoint->x <= 480 && SelectPoint->y <= 480)
	{
		MousePoint.x = SelectPoint->x / 60;
		MousePoint.y = SelectPoint->y / 60;
	}
	else
		return false;

	for (int i = 0; i < CHESS_PLAYER_PIECES_MAXNUMBER; i++)
	{
		if (BlackPlayerPieces[i]->GetPoint()->x == MousePoint.x && BlackPlayerPieces[i]->GetPoint()->y == MousePoint.y)
		{
			if (BlackPlayerPieces[i]->GetState() == LIVE)
			{
				*iGameState = PIECES_SELECT;
			//	TextOut(hdc, 10, 500, "       ", 9);
			//	TextOut(hdc, 10, 500, "°ËÀº»ö", 6);
				return BlackPlayerPieces[i];
			}
		}

		 if (WhitePlayerPieces[i]->GetPoint()->x == MousePoint.x && WhitePlayerPieces[i]->GetPoint()->y == MousePoint.y)
		{
			if (WhitePlayerPieces[i]->GetState() == LIVE)
			{
				*iGameState = PIECES_SELECT;
			//	TextOut(hdc, 10, 500, "       ", 9);
			//	TextOut(hdc, 10, 500, "Èò»ö", 4);
				return WhitePlayerPieces[i];
			}
		}
	}
	return false;
}


bool ChessPiecesManager::MovedToMousePos(Pieces * ChoicePieces, POINT* MousePos, int * iGameState, HWND hWnd, int *iPlayerTurn)
{
	if (MousePos->x <= 480 && MousePos->y <= 480)
	{
		MousePos->x = MousePos->x / 60;
		MousePos->y = MousePos->y / 60;
	}

	BeforMovingPos.x = ChoicePieces->GetPoint()->x;
	BeforMovingPos.y = ChoicePieces->GetPoint()->y;

	

	//	MessageBox(hWnd, "ChessPiecesManager", "MovedToMousePoint FALSE", MB_OK);

	for (int i = 0; i < CHESS_BOARD_HIGH; i++)
	{
		bMovedPieces = ChoicePieces->MovedToMousePoint(MousePos, &iMoveToNumber);

		if (bMovedPieces == true)
		{
			for (int j = 0; j < CHESS_PLAYER_PIECES_MAXNUMBER; j++)
			{
				if (ChoicePieces->GetPoint()->x >= CHESS_BOARD_HIGH || ChoicePieces->GetPoint()->y >= CHESS_BOARD_HIGH)
				{
					ChoicePieces->GetPoint()->x = BeforMovingPos.x;
					ChoicePieces->GetPoint()->y = BeforMovingPos.y;
					return false;
				}

				if (ChoicePieces->GetTeam() != *iPlayerTurn)
				{
					ChoicePieces->GetPoint()->x = BeforMovingPos.x;
					ChoicePieces->GetPoint()->y = BeforMovingPos.y;
					return false;
				}

				//	WhitePieces
				if (ChoicePieces->GetTeam() == WHITE_PIECES)
				{
					CheckedJumpPieces(ChoicePieces, WhitePlayerPieces, j);

					if (AttackedbleChessPieces(ChoicePieces, BlackPlayerPieces, j, iGameState) == true)
					{
						if (ChoicePieces->GetPieces() == POWN)
						{
							ChoicePieces = ChoicePieces->PownAdvanceMent(ChoicePieces);

							for (int i = 0; i < CHESS_PIECES_POWN_MAXNUMBER; i++)
							{
								for (int j = 0; j < CHESS_PLAYER_PIECES_MAXNUMBER; j++)
								{
									if (ChoicePieces->GetPoint()->x == WhitePlayerPieces[i]->GetPoint()->x &&
										ChoicePieces->GetPoint()->y == WhitePlayerPieces[i]->GetPoint()->y)
									{
										if (bMovedPieces == false)
										{
											WhitePlayerPieces[i] = ChoicePieces;
										}
										else
											WhitePlayerPieces[i] = ChoicePieces;
									}
								}
							}
						}
						*iGameState = PLAY_GAME;
						return true;
					}

					if (*iGameState == GAME_OVER)
					{
						return false;
					}
				}

				//	BlackPieces
				else if (ChoicePieces->GetTeam() == BLACK_PIECES)
				{
					CheckedJumpPieces(ChoicePieces, BlackPlayerPieces, j);

					if (AttackedbleChessPieces(ChoicePieces, WhitePlayerPieces, j, iGameState) == true)
					{
						if (ChoicePieces->GetPieces() == POWN)
						{
							ChoicePieces = ChoicePieces->PownAdvanceMent(ChoicePieces);

							for (int i = 0; i < CHESS_PIECES_POWN_MAXNUMBER; i++)
							{
								for (int j = 0; j < CHESS_PLAYER_PIECES_MAXNUMBER; j++)
								{
									if (ChoicePieces->GetPoint()->x == BlackPlayerPieces[i]->GetPoint()->x &&
										ChoicePieces->GetPoint()->y == BlackPlayerPieces[i]->GetPoint()->y)
									{
										if (bMovedPieces == false)
										{
											BlackPlayerPieces[i] = ChoicePieces;
										}
										else
											BlackPlayerPieces[i] = ChoicePieces;
									}
								}
							}
						}
						*iGameState = PLAY_GAME;
						return true;
					}

					if (*iGameState == GAME_OVER)
					{
						return false;
					}
				}
			}
		}

		if (ChoicePieces->GetTeam() != *iPlayerTurn)
		{
			ChoicePieces->GetPoint()->x = BeforMovingPos.x;
			ChoicePieces->GetPoint()->y = BeforMovingPos.y;
			*iGameState = PLAY_GAME;
			if (*iPlayerTurn == WHITE_PLAYER_TURN)
			{
				*iPlayerTurn = BLACK_PLAYER_TURN;
				*iGameState = PLAY_GAME;

				if (ChoicePieces->GetPieces() == POWN)
				{
					ChoicePieces->MovedPownReset();
				}
				return false;
			}
			else if (*iPlayerTurn == BLACK_PLAYER_TURN)
			{
				*iPlayerTurn = WHITE_PLAYER_TURN;
				*iGameState = PLAY_GAME;

				if (ChoicePieces->GetPieces() == POWN)
				{
					ChoicePieces->MovedPownReset();
				}
				return false;
			}
			return false;
		}


		MovedAblePown(ChoicePieces, WhitePlayerPieces, BlackPlayerPieces, 0);


		if (ChoicePieces->GetPoint()->x == BeforMovingPos.x &&
			ChoicePieces->GetPoint()->y == BeforMovingPos.y)
		{
			if(*iPlayerTurn == WHITE_PLAYER_TURN)
				{
					*iPlayerTurn = BLACK_PLAYER_TURN;
					*iGameState = PLAY_GAME;

					return false;
				}
			else if (*iPlayerTurn == BLACK_PLAYER_TURN)
				{
					*iPlayerTurn = WHITE_PLAYER_TURN;
					*iGameState = PLAY_GAME;

					return false;
				}
		}

		 if (bMovedPieces == false)
		{
			*iGameState = PLAY_GAME;
			return false;
		}

	}

	*iGameState = PLAY_GAME;
	return false;
}

void ChessPiecesManager::MovedAblePown(Pieces * ChoicePieces, Pieces * WhitePieces[CHESS_PLAYER_PIECES_MAXNUMBER], Pieces * Blackpieces[CHESS_PLAYER_PIECES_MAXNUMBER], int iPlayerTurn)
{
	if (bMovedPieces == true)
	{
		for (int j = 0; j < CHESS_PLAYER_PIECES_MAXNUMBER; j++)
		{
			if (ChoicePieces->GetPieces() == POWN &&
				ChoicePieces->GetPoint()->x != WhitePieces[j]->GetPoint()->x &&
				ChoicePieces->GetPoint()->y != WhitePieces[j]->GetPoint()->y &&
				ChoicePieces->GetPoint()->x != Blackpieces[j]->GetPoint()->x &&
				ChoicePieces->GetPoint()->y != Blackpieces[j]->GetPoint()->y)
			{
				ChoicePieces->GetPoint()->x = BeforMovingPos.x;
				ChoicePieces->GetPoint()->y = BeforMovingPos.y;
			}
		}
	}

	else if (bMovedPieces == false)
	{
		for (int i = 0; i < CHESS_PLAYER_PIECES_MAXNUMBER; i++)
		{
			if (ChoicePieces->GetTeam() == WHITE_PIECES)
			{
				if (ChoicePieces->GetPoint()->x == WhitePieces[i]->GetPoint()->x &&
					ChoicePieces->GetPoint()->y == WhitePieces[i]->GetPoint()->y &&
					ChoicePieces->GetPieces() != WhitePieces[i]->GetPieces() &&
					ChoicePieces->GetPieces() == POWN )
				{
					ChoicePieces->GetPoint()->x = BeforMovingPos.x;
					ChoicePieces->GetPoint()->y = BeforMovingPos.y;
				}

				if (ChoicePieces->GetTeam() == WHITE_PIECES &&
					ChoicePieces->GetPoint()->x == Blackpieces[i]->GetPoint()->x &&
					ChoicePieces->GetPoint()->y == Blackpieces[i]->GetPoint()->y &&
					Blackpieces[i]->GetState() == LIVE &&
					ChoicePieces->GetPieces() == POWN)
				{
					ChoicePieces->GetPoint()->x = BeforMovingPos.x;
					ChoicePieces->GetPoint()->y = BeforMovingPos.y;
				}
			}

			if (ChoicePieces->GetTeam() == BLACK_PIECES)
			{
				if (ChoicePieces->GetPoint()->x == Blackpieces[i]->GetPoint()->x &&
					ChoicePieces->GetPoint()->y == Blackpieces[i]->GetPoint()->y &&
					ChoicePieces->GetPieces() != Blackpieces[i]->GetPieces() &&
					ChoicePieces->GetPieces() == POWN)
				{
					ChoicePieces->GetPoint()->x = BeforMovingPos.x;
					ChoicePieces->GetPoint()->y = BeforMovingPos.y;
				}

				if (ChoicePieces->GetTeam() == BLACK_PIECES &&
					ChoicePieces->GetPoint()->x == WhitePieces[i]->GetPoint()->x &&
					ChoicePieces->GetPoint()->y == WhitePieces[i]->GetPoint()->y &&
					Blackpieces[i]->GetState() == LIVE &&
					ChoicePieces->GetPieces() == POWN)
				{
					ChoicePieces->GetPoint()->x = BeforMovingPos.x;
					ChoicePieces->GetPoint()->y = BeforMovingPos.y;
				}
			}
		}
	}
}

bool ChessPiecesManager::AttackedbleChessPieces(Pieces * ChoicePieces, Pieces * PlayerDiePieces[CHESS_PLAYER_PIECES_MAXNUMBER], int iChessPiecesNumber, int *iGameState)
{
	if (ChoicePieces->GetPoint()->x == PlayerDiePieces[iChessPiecesNumber]->GetPoint()->x &&
		ChoicePieces->GetPoint()->y == PlayerDiePieces[iChessPiecesNumber]->GetPoint()->y &&
		PlayerDiePieces[iChessPiecesNumber]->GetState() == LIVE)
	{
		PlayerDiePieces[iChessPiecesNumber]->SetDie();

		if (PlayerDiePieces[14]->GetState() == DEAD)
		{
			*iGameState = GAME_OVER;
			return false;
		}



		*iGameState = PLAY_GAME;
		return true;
	}

	return 0;
}

void ChessPiecesManager::CheckedJumpPieces(Pieces * ChoicePieces, Pieces * PlayerPieces[CHESS_PLAYER_PIECES_MAXNUMBER], int iChessPiecesNumber)
{
	if (ChoicePieces->GetPoint()->x == PlayerPieces[iChessPiecesNumber]->GetPoint()->x &&
		ChoicePieces->GetPoint()->y == PlayerPieces[iChessPiecesNumber]->GetPoint()->y &&
		ChoicePieces->GetPieces() != PlayerPieces[iChessPiecesNumber]->GetPieces() &&
		PlayerPieces[iChessPiecesNumber]->GetState() == LIVE)
	{
		ChoicePieces->GetPoint()->x = BeforMovingPos.x;
		ChoicePieces->GetPoint()->y = BeforMovingPos.y;
	}
}


void ChessPiecesManager::Release()
{	
}

ChessPiecesManager::ChessPiecesManager()
{
	iMoveToNumber = 1;
	bMovedPieces = false;
}


ChessPiecesManager::~ChessPiecesManager()
{
}

