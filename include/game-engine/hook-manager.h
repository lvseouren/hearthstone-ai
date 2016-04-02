#pragma once

#include "game-engine/board-objects/minion.h"
#include "game-engine/board-objects/minions.h"

namespace GameEngine
{
	class Board;

	class HookManager
	{
	public:
		HookManager(Board & board);
		HookManager(HookManager const& rhs) = delete;
		HookManager(HookManager && rhs) = delete;
		HookManager & operator=(HookManager const& rhs) = delete;
		HookManager & operator=(HookManager && rhs) = delete;

	public: // hooks
		void PlayerTurnStart();
		void PlayerTurnEnd();
		void OpponentTurnStart();
		void OpponentTurnEnd();

		void HookAfterMinionAdded(BoardObjects::Minion & minion);
		void HookAfterMinionDamaged(BoardObjects::Minions & minions, BoardObjects::Minion & minion, int damage);

	private:
		Board & board;
	};
}