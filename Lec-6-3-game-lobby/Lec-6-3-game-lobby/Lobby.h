#ifndef Lobby_H
#define Lobby_H


#include "Player.h"
class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;
};
#endif Lobby_H