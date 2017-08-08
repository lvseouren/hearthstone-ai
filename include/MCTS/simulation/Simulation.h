#pragma once

#include "MCTS/Config.h"
#include "MCTS/policy/Simulation.h"

namespace mcts
{
	namespace simulation
	{
		class Simulation
		{
		public:
			Simulation(int rand_seed) : random_(rand_seed) {}

			void StartNewAction() {
			}

			int ChooseAction(
				board::Board const& board,
				board::BoardActionAnalyzer const& action_analyzer,
				ActionType action_type,
				board::ActionChoices const& action_choices)
			{
				if (action_choices.Empty()) return -1;

				int choices = action_choices.Size();

				if (choices == 1) {
					return 0;
				}

				if (action_type.IsChosenRandomly()) {
					int rnd = random_.GetRandom(choices);
					return action_choices.Get(rnd);
				}

				assert(action_type.IsChosenManually());

				int choice = StaticConfigs::SimulationPhaseSelectActionPolicy::GetChoice(
					board, action_analyzer, action_type,
					policy::simulation::ChoiceGetter(choices)
				);
				if (choice < 0) return -1;

				return action_choices.Get(choice);
			}

			void ReportInvalidAction() {
			}

		private:
			StaticConfigs::SimulationPhaseRandomActionPolicy random_;
		};
	}
}